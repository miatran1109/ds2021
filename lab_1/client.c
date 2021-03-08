#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 1024

void send_file(FILE *fp, int serv){
  int n;
  char data[SIZE] = {0};

  while(fgets(data, SIZE, fp) != NULL) {
    bzero(data, SIZE);
  }
}

int main(int argc, char* argv[]){
  char *ip = "127.0.0.1";
  struct sockaddr_in ad;
  FILE *fp;

  int serv = socket(AF_INET, SOCK_STREAM, 0);
  printf("Server created!\n");

  memset(&ad, 0, sizeof(ad));
  ad.sin_family = AF_INET;
  ad.sin_addr.s_addr = inet_addr(ip);
  ad.sin_port = htons(12345);

  connect(serv, (struct sockaddr*)&ad, sizeof(ad));
  printf("Connected to server.\n");

  fp = fopen("send.txt", "r");

  send_file(fp, serv);
  printf("File is sent!\n");

  close(serv);

  return 0;
}
