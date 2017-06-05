/********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  gprs.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(2016年02月26日)
 *         Author:  hulu <luhu918@gmail.com>
 *      ChangeLog:  1, Release initial version on "2016年02月26日 10时55分23秒"
 *                 
 ********************************************************************************/

#ifndef __GPRS_H__
#define __GPRS_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

extern int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);
extern int send_message(int fd);
extern int call_number(int fd);

#endif
