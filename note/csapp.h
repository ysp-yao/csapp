#ifndef CSAPP_H_
#define CSAPP_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/* Persistent state for the robust I/O (Rio) package */
/* $begin rio_t */
#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;                /* Descriptor for this internal buf */
    int rio_cnt;               /* Unread bytes in internal buf */
    char *rio_bufptr;          /* Next unread byte in internal buf */
    char rio_buf[RIO_BUFSIZE]; /* Internal buffer */
} rio_t;
/* $end rio_t */

ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);

void rio_readinitb(rio_t *rp, int fd);

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);


static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n);

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAXLINE 8192
#define LISTENQ  1024 
#define MAXBUF   8192

typedef struct sockaddr SA;
int open_clientfd(char *hostname, char *port);
int open_listenfd(char *port);


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern char **environ; /* Defined by libc */

#endif // CSAPP_H_