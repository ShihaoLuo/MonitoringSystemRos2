#include <cstdio>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <memory.h>
#include <chrono>
#include <arpa/inet.h>
#include <iostream>


int main(int argc, char** argv)
{
  const int local_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if(local_socket < 0)
  {
    std::printf("socket create faild!\n");
    return -1;
  }
  struct timeval timeout;
  timeout.tv_sec = 5;
  timeout.tv_usec = 0;
  if(setsockopt(local_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))<0)
  {
    std::printf("set timeout faild!\n");
    return -1;
  }
  struct sockaddr_in ser_addr;
  memset(&ser_addr, 0, sizeof(struct sockaddr_in));
  ser_addr.sin_family = AF_INET;
  ser_addr.sin_port = 8890;
  ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  while(1)
  {
    if(bind(local_socket, (struct sockaddr*)&ser_addr, sizeof(struct sockaddr_in))<0)
    {
        std::printf("bind port %d faild! Try %d.\n", ser_addr.sin_port, ser_addr.sin_port+1);
        ser_addr.sin_port += 1;
    }else
    {
        std::printf("bind port %d succeed!\n", ser_addr.sin_port);
        break;
    }
  }
  struct sockaddr_in dst_addr;
  memset(&dst_addr, 0, sizeof(struct sockaddr_in));
  dst_addr.sin_family = AF_INET;
  dst_addr.sin_port = 8889;
  uint32_t ip;
  inet_pton(AF_INET, argv[1], &ip);
  dst_addr.sin_addr.s_addr = ip;
  char cmd[100]={'\0'};
  int size = 0;
  while(1)
  {
    std::cin>>cmd;
    while(cmd[size]!='\0')
    {
      size +=1 ;
    }
    std::printf("send cmd: %s, size:%d.\n", cmd, size);
    sendto(local_socket, &cmd, size, 0, (struct sockaddr *)&dst_addr, sizeof(struct sockaddr));
    memset(cmd, 0, size+1);
    size = 0;
  }
  shutdown(local_socket, SHUT_RDWR);
  return 0;
}
