#ifndef _FACTOR_H_
#define _FACTOR_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>

int factorize(char *buffer);
void factorize(mpz_t n);

#endif /* _FACTOR_H_ */
