#include <cstdio>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <memory.h>
#include <chrono>

int udpRecvHandler(const int &fd)
{
  char buf[1024];
  int recvNum = 0;
  struct sockaddr_in clientAddr;
  const int len = sizeof(struct sockaddr_in);
  using std::chrono::system_clock;
  time_t old = system_clock::to_time_t(system_clock::now());
  while (1)
  {
    old = system_clock::to_time_t(system_clock::now());
    recvNum = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&clientAddr, (socklen_t*)&len);
    if(recvNum<0)
    {
      std::printf("received faild! timeout: %lds.\n", system_clock::to_time_t(system_clock::now()) - old);
      return -1;
    }else
    {
      std::printf("recv: %s\n", buf);
    }
  }
}


int main()
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
  udpRecvHandler(local_socket);
  shutdown(local_socket, SHUT_RDWR);
  return 0;
}
