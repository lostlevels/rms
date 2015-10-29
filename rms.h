#ifndef __RMS_H__
#define __RMS_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

int writeOver(int fd, int filesize, unsigned int blockSize);
int deleteFile(const char *filepath);
bool isDirectory(const char *filepath);
bool isDotDirectory(const char *filename);
const char *pathJoin(const char *dir, const char *file);
int deleteFiles(const char *directory);

#ifdef __cplusplus
}
#endif

#endif
