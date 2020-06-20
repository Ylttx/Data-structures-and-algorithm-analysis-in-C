#ifndef Common_H
#define Common_H

#include <stdio.h>
#include <stdlib.h>

#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1)

#define Error(Str) printf("%s", Str)

typedef char ElementType;

#endif
