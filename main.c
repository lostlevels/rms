#include "rms.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
  int c =0;

  //switches
  int recurs = 0, writeSize = 0;

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

  int argNum = optind;
  int status = 0;

  //continue deleting files passed into arguments until no more or error
  while(!status && argNum < argc) {

    switch(recurs) {
	    case 1:
	      status = deleteFiles(argv[argNum]);
	      break;
	    default:
	      status = deleteFile(argv[argNum]);
        break;
	  }

    argNum++;
  }

  return status;
}
