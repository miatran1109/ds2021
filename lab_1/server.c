#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 1024

void write_file(int ss){
  int n;
  FILE *fp;
  char buffer[SIZE];

  fp = fopen("recv.txt", "w");
  while (1) {
    n = recv(ss, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}

int main(){
  int ss, new_ss;
  struct sockaddr_in ad, new_ad;
  socklen_t ad_size;
  char buffer[SIZE];

  ss = socket(AF_INET, SOCK_STREAM, 0);
  printf("Server created.\n");

  ad.sin_family = AF_INET;
  ad.sin_addr.s_addr = INADDR_ANY;
  ad.sin_port = htons(12345);

  bind(ss, (struct sockaddr*)&ad, sizeof(ad));

 listen(ss, 10);
 printf("Listening..\n");
 

  ad_size = sizeof(new_ad);
  new_ss = accept(ss, (struct sockaddr*)&new_ad, &ad_size);
  write_file(new_ss);
  printf("Data written!\n");

  return 0;
}
