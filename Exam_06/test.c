#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_client{
  int id;
  char msg[140000];
} t_client;

int max = 0, next_id = 0;
char r_bff[140000], w_bff[140000];
t_client clients[4096];
fd_set fds, rfds, wfds;

