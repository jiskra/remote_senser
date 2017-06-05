/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  gprs_main.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2016年02月26日)
 *         Author:  hulu <luhu918@gmail.com>
 *      ChangeLog:  1, Release initial version on "2016年02月26日 10时38分16秒"
 *                 
 ********************************************************************************/

#include"gprs.h"

int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);
int send_message(int fd);
int call_number(int fd);
/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
    int fd;
    char select;

    fd = open( "/dev/ttyS1", O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd<0){
        perror("Can't Open Serial Port");
        return -1;
    }
     //配置串口
    set_opt( fd,115200,8,'N',1);

    printf("==========================================\n");
    printf("gprs call number and send message\n");
    printf("==========================================\n");
    printf("enter your select:  's' is send message,  'c' is call number,   'q' is exit \n");

    select=getchar();
     switch(select)
    {
        case 's':
                 send_message(fd);
                 break;
        case 'c':
                 call_number(fd);
                 break;
        case 'q':
                 exit(0);
                 break;
        default:
                 break;
    }
    close(fd);


    return 0;
} /* ----- End of main() ----- */
