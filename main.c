#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

  if (argc < 2) {
    printf("Missing filepath.\n");
    exit(1);
  }

  char *filepath = argv[1];


  



  


  unlink(filepath);
  
  return 0;
}
