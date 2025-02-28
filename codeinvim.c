//Copyright Maria Bianca Popescu 2023

#include <stdio.h>

#define NMAX 100

// functie pentru interschimbarea valorilor
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(void)
{
	int n;
	int grades[NMAX], credits[NMAX], pon[NMAX];
	int score = 0, min_score;

	scanf("%d", &n); //citim numarul de note

	for (int i = 0; i < n; i++)
		scanf("%d", &grades[i]); // citim notele

	for (int i = 0; i < n; i++)
		scanf("%d", &credits[i]); // citim creditele corespunzatoare notelor

	scanf("%d", &min_score); // citim punctajul minim care trebuie obtinut

	for (int i = 0; i < n; i++) {
		// facem un vector auxiliar in care punem ponderile calculate
		pon[i] = (10 - grades[i]) * credits[i];

		score += grades[i] * credits[i]; // calculam punctajul total
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// sortam descrescator vectorul de ponderi
			if (pon[i] < pon[j]) {
				swap(&pon[i], &pon[j]);
				swap(&grades[i], &grades[j]);
				swap(&credits[i], &credits[j]);
			}
		}
	}

	int min_nr = 0;

	for (int i = 0; i < n; i++) {
		// calculam cel mai mic punctaj mai mare decat min_score
		if (score < min_score) {
			score += pon[i];
			min_nr++; // numaram materiile
		}
	}

	// daca problema nu are solutie, afisam -1
	if (score < min_score) {
		printf("-1");
		return 0;
	}

	printf("%d", min_nr); // afisam numarul minim de materii

	return 0;
}
