#include "rms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Missing filepath.\n");
    return 1;
  }

  if (!strcmp(argv[1], "-r") || !strcmp(argv[1], "-rf")) {
    if (argc < 3 || !argv[2]) {
      fprintf(stderr, "Missing filepath");
      return 1;
    }
    return deleteFiles(argv[2]);
  }
  else {
    return deleteFile(argv[1]);
  }
}