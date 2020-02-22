#ifndef _Common_H
#define _Common_H

#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1)

#define Error(Str) printf("%s", Str)

typedef char ElementType;

#endif
