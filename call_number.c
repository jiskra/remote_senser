/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  call_number.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2016年02月26日)
 *         Author:  hulu <luhu918@gmail.com>
 *      ChangeLog:  1, Release initial version on "2016年02月26日 10时46分56秒"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include"gprs.h"

/**************************************************************************************
 *  Description:    gprs打电话函数
 *   Input Args:    fd 串口设备文件描述符
 *  Output Args:
 * Return Value:
 *************************************************************************************/
int call_number (int fd)
{
    getchar();                             //将缓冲区回车吃掉

    int count=0;
    char call[20]="atd";     
    char number[20];
    char reply[128];

    printf("enter you call number\n");
    if(NULL==fgets(number,20,stdin))      //输入电话号码，其中fgets在读入一个字符串后在字符串尾端默认加入\n字符
        exit(0);           //这个语句的功能可以用gets实现，区别在于 fgets 读入的含 "\n"（最后一个字符），gets 不含 "\n"

    while(strlen(number)!=12)           
    {
        printf("please again number\n");
        if(NULL==fgets(number,20,stdin))
            exit(0);
        if(count==3)
            exit(0);
        count++;
    }

    number[strlen(number)-1]='\0'; //将刚才fgets读入的字符串尾端去除\n字符
    strcat(call,number);     
    strcat(call,";\r");            // \r是换行字符

    write(fd,call,strlen(call));   //向串口拨打号码
    printf("write %s\n",call);
    sleep(3);  
    memset(reply,0,sizeof(reply));
    read(fd,reply,sizeof(reply));
    printf("%s\n",reply);

    printf("=================================================\n");
    printf("number is calling,please press 'a' hang up \n");
    printf("=================================================\n");

   while('a'!=getchar())
        printf("please again input 'a' to hung up \n");

    memset(call,0,sizeof(call));
    strcpy(call,"ATH\r"); 
    write(fd,call,strlen(call));
    sleep(1);
    memset(reply,0,sizeof(reply));
    read(fd,reply,sizeof(reply));
    printf("%s\n",reply);
    printf("has hung up\n");


    return 0;
} /* ----- End of call_number()  ----- */
