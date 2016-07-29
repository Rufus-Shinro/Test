#ifndef MY_INCLUDE_H
#define MY_INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define bool char
#define TRUE 1
#define FALSE 0

#define RANGED_INTEGER_DATA "ranged_integer.data"
#define RANGED_NATURAL_DATA "ranged_natural.data"
#define UNRANGED_INTEGER_DATA "unranged_integer.data"
#define UNRANGED_NATURAL_DATA "unranged_natural.data"
#define DATA_DIR "./data/"

int gcd(int m, int n);

#endif
