/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  send_message.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2016年02月26日)
 *         Author:  hulu <luhu918@gmail.com>
 *      ChangeLog:  1, Release initial version on "2016年02月26日 10时46分28秒"
 *                 
 ********************************************************************************/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include"gprs.h"


/**************************************************************************************
 *  Description:    gprs发短信函数
 *   Input Args:    fd 串口设备文件描述符
 *  Output Args:
 * Return Value:
 *************************************************************************************/
int send_message (int fd)
{
    int count=0;
    char  cmgf[]="at+cmgf=1\r";  //设置短信发送模式为text （0-PDU;1-text）
    char  cmgs[128]="at+cmgs=\"";
    char  send_number[16];
    char  message[128];
    char  reply[128];

    getchar();                   //吃掉缓冲区回车
    printf("enter send_message number :\n");
    if(NULL==fgets(send_number,16,stdin))
        exit(0);
    while(12!=strlen(send_number))
    {
        getchar();
        printf("please again input number\n");
        if(NULL==fgets(send_number,16,stdin))
             exit(0);
        if(count==3)
            exit(0);
        count++;
    }

    send_number[strlen(send_number)-1]='\0';   //去除字符串末端读入的换行符\n;
    strcat(cmgs,send_number);
    strcat(cmgs,"\"\r");

    printf("enter send_message :\n");
    if(NULL==fgets(message,128,stdin))
        exit(0);

    message[strlen(message)-1]='\0';
    strcat(message,"\x1a");

    /* write cmgf */

    write(fd,cmgf,strlen(cmgf));
    printf("write %s\n",cmgf);
    sleep(2);
    memset(reply,0,sizeof(reply));
    read(fd,reply,sizeof(reply));
    printf("%s\n",reply);

    /* write cmgs */

    write(fd,cmgs,strlen(cmgs));
    printf("writr %s\n",cmgs);
    sleep(5);
    //memset(reply,0,sizeof(reply));
    //read(fd,reply,sizeof(reply));
    //printf("%s\n",reply);


    /*write  message*/

    write(fd,message,strlen(message));
    printf("writr %s\n",message);
    sleep(4);
    memset(reply,0,sizeof(reply));
    read(fd,reply,sizeof(reply));
    printf("%s\n",reply);


    return 0;
} /* ----- End of send_message()  ----- */
