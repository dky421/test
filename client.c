#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>

int main()
{
  int st;
  struct sockaddr_in addr;
  char buf[1024];

  st = socket(AF_INET, SOCK_STREAM, 0);

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8000);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  connect(st, (struct sockaddr *)&addr, sizeof(addr));
  
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "Hello world!");
  send(st, buf, strlen(buf), 0);

  close(st);

  exit(EXIT_SUCCESS);
}
