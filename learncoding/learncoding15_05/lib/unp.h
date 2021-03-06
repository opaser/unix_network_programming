#ifndef __unp_h
#define __unp_h
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>
#include <netdb.h>
#include <fcntl.h>
/* define var */
#define MAXLINE 4096
#define SERV_PORT 9877
#define SERV_PORT_STR "9877"
#define UNIXSTR_PATH "/tmp/unix.str"
#define UNIXDG_PATH "/tmp/unix.dg"

#define SA struct sockaddr
#define IPV6 11
#define LISTENQ 1024
#define BUFFSIZE	8192

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE  (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)


typedef void  Sigfunc(int);
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#ifndef INFTIM
#define	INFTIM	(-1)
#endif

#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46
#endif

// about msghdr
#define HAVE_MSGHDR_MSG_CONTROL

/*sock_ntop.c */
char * sock_ntop(const struct sockaddr *sa, socklen_t salen);
char * Sock_ntop(const struct sockaddr *sa, socklen_t salen);

/* wrapsock.c  */

void Getsockname(int, SA *, socklen_t *);
void Bind(int, const SA *, socklen_t);
void Listen(int, int);
void Connect(int, const SA*, socklen_t);
int	 Socket(int, int, int);
void Socketpair(int, int, int, int*);
int  Select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
void Shutdown(int, int);
int  Accept(int, SA *, socklen_t *);
int	 Poll(struct pollfd*, unsigned long, int);
ssize_t Recvfrom(int, void *, size_t, int, SA *, socklen_t *);
ssize_t Recvmsg(int, struct msghdr *, int);
void Sendto(int, const void*, size_t, int, const SA *, socklen_t);
void Setsockopt(int, int, int, const void *, socklen_t);
void Sendmsg(int, const struct msghdr *, int);

/* signal.c */
Sigfunc *Signal(int, Sigfunc *);

/* wrapunix.c */
void Close(int);
pid_t Fork(void);
ssize_t Read(int, void *, size_t);
void	Write(int, void *, size_t);
pid_t Waitpid(pid_t, int *, int);

/* writen.c */
ssize_t writen(int, const void *, size_t);
void Writen(int, void *, size_t);

/*error.c */
#include <errno.h>
void err_sys(const char *, ...);
void err_quit(const char *, ...);
void err_msg(const char *, ...);
void err_ret(const char *, ...);


/* wraplib.c */
const char	*Inet_ntop(int, const void *, char *, size_t);
void	Inet_pton(int, const char *, void *);

/* wrapstdio.c */
char *Fgets(char *, int, FILE *);
void  Fputs(const char*, FILE *);

/*str_echo.c is testing */
void str_echo(int);

/*str_cli.c is testing */
void str_cli(FILE *, int);

/* readline.c */
ssize_t readline(int, void *, size_t);
ssize_t Readline(int, void *, size_t);

/* dg_echo.c */
void dg_echo(int, SA *, socklen_t);

/*dg_cli.c*/
void dg_cli(FILE *, int, const SA *, socklen_t);

/*read_fd.c*/
ssize_t Read_fd(int, void *, size_t, int *);

/*write_fd.c*/
ssize_t Write_fd(int, void *, size_t, int);
#endif
