#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define BUF_SIZE 1024

char writeOver(int fd, int filesize) {

  char buffer[BUF_SIZE];
  
  int dataLeft = filesize;
  int outSize = sizeof(buffer);
  
  while(dataLeft > 0) {
    size_t written = 0;
    //generate random data to write
    arc4random_buf(buffer, outSize);


    
    if (dataLeft < outSize) {
      //make sure we aren't writing more data than
      //the original file
      written = write(fd, buffer, dataLeft);
    } else 
      written = write(fd, buffer, outSize);


    dataLeft -= written;
    
    //stop on failure to write
    if (written <= 0)
      break;
  
  }
  close(fd);
  
  return errno;
}



int main (int argc, char *argv[]) {

  if (argc < 2) {
    printf("Missing filepath.\n");
    return 1;
  }

  char *filepath = argv[1];


  int fd = open(filepath, O_RDWR);
  if (fd < 0) {
    printf("Failed opening file.\n");
    return 2;
  }

  struct stat st = {};
  lstat(filepath, &st);
  
  int status = writeOver(fd, st.st_size);
  if (status) {
    printf("Error overwriting file.\n");
    return 3;
  }
  
  //delete file
  //unlink(filepath);
  
  return 0;
}
