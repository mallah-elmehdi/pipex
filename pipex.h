#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define ERR -1
#define SUCCESS 0

// ======== util.c
int error(const char *err);
