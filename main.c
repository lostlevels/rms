#include "rms.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
  int c;
  int recurs = 0;
  int writeSize = 0;
  while ((c = getopt (argc, argv, "rfs:")) != -1) {
    switch (c) {
      case 's':
        writeSize=strtol(optarg, NULL, 10);
        break;
      case 'f':
        break;
      case 'r':
        recurs=1;
        break;
      default:
        abort();
    }
  }
  
  if (optind > argc - 1) {
    return 0;
  }

  switch(recurs) {
    case 1:
      deleteFiles(argv[optind]);
      break;
    default:
      deleteFile(argv[optind]);
  }
}