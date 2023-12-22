#include "factor.h"

void factorize(mpz_t n)
{
	mpz_t p, q, sqrt_n;
	mpz_inits(p, q, sqrt_n, NULL);
	mpz_sqrt(sqrt_n, n);
	mpz_set_ui(p, 2);

	while (mpz_cmp(p, sqrt_n) <= 0)
	{
		if (mpz_divisible_p(n, p))
		{
			mpz_divexact(q, n, p);
			gmp_printf("%Zd=%Zd*%Zd\n", n, p, q);
			break;
		}
		mpz_nextprime(p, p);
	}
	mpz_clears(p, q, sqrt_n, NULL);
}
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	mpz_t n;
	mpz_init_set_str(n, argv[1], 10);
	factorize(n);
	mpz_clear(n);

	return 0;
}
