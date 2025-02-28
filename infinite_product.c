//Copyright Maria Bianca Popescu 2023

#include <stdio.h>
#include <math.h>

int main(void)
{
	unsigned long scal_prod = 0, N, a, b;
	long max_a1 = -1, max_a2 = -1, max_b1 = -1, max_b2 = -1;
	double norm_a = 0, norm_b = 0;

	scanf("%lu", &N); // citim numarul de perechi

	for (unsigned long i = 0; i < N; i++) {
		scanf("%lo%lo", &a, &b); // citim perechile, pe rand, in baza 8

		scal_prod += a * b; // calculam produsul scalar, dupa formula
		norm_a += (double)a * (double)a; // calculam cantitatea de sub radical
		norm_b += (double)b * (double)b;

		// calculam al doilea maxim pentru fiecare vector
		if ((long)a > max_a1) {
			max_a2 = max_a1;
			max_a1 = (long)a;
		} else if ((long)a > max_a2 && (long)a < max_a1) {
			max_a2 = (long)a;
		}

		if ((long)b > max_b1) {
			max_b2 = max_b1;
			max_b1 = (long)b;
		} else if ((long)b > max_b2 && (long)b < max_b1) {
			max_b2 = (long)b;
		}
	}

	norm_a = sqrt(norm_a); // facem radical pentru a obtine a doua norma
	norm_b = sqrt(norm_b);

	printf("%lu\n", scal_prod); // afisam produsul scalar

	if ((max_a2 == -1 && max_b2 == -1) || N == 0)
		printf("-1 -1\n"); // afisam -1 cand vectorul nu exista
	else if (max_a2 == -1)
		printf("-1 %ld\n", max_b2);
	else if (max_b2 == -1)
		printf("%ld -1\n", max_a2);
	else
		printf("%ld %ld\n", max_a2, max_b2);

	printf("%.7f %.7f\n", norm_a, norm_b); // afisam normele cu 7 zecimale

	return 0;
}
