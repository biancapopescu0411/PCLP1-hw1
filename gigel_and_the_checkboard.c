// Copyright Maria Bianca Popescu 2023

#include <stdio.h>

#define NMAX 1000

// functie pentru citirea tablei de sah
int scanf_checkboard(int n, int checkboard[NMAX][NMAX])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &checkboard[i][j]);
	}

	return 0;
}

// functie pentru verificarea culorii unui patrat
int white(int line, int column)
{
	if ((line + column) % 2 == 0)
		return 1;

	return 0;
}

// functie pentru valoarea absoluta
int abs_value(int x)
{
	if (x < 0)
		return -x;

	return x;
}

int main(void)
{
	int n;
	scanf("%d", &n); // citim numarul de linii/coloane

	int checkboard[NMAX][NMAX];
	scanf_checkboard(n, checkboard); // citim tabla

	int line = 0, column = 0;
	long dist = 0, total_dist = 0;

	// conditia de oprire este cand intalnim 0
	while (checkboard[line][column]) {
		if (white(line, column)) { // verificam daca ne aflam pe alb
			dist = checkboard[line][column];
			checkboard[line][column] = 0; // marcam locurile deja vizitate
			total_dist += abs_value(dist); // calculam distanta totala parcursa

			if (dist > 0) { // daca valoarea este pozitiva, ne mutam la dreapta
				column += dist;
				column %= n;
			} else { // in caz contrar, la stanga
				column += dist;
				column %= n;
				column += n;
				column %= n;
			}
		} else { // urmam aceiasi pasi pentru un patrat negru
			dist = checkboard[line][column];
			checkboard[line][column] = 0;
			total_dist += abs_value(dist);

			if (dist > 0) {
				line += dist;
				line %= n;
			} else {
				line += dist;
				line %= n;
				line += n;
				line %= n;
			}
		}
	}

	printf("%ld\n", total_dist); // afisam distanta totala

	if (column < 26) { // afisam pozitia finala pe care ne aflam
		char c = 'A' + column;

		printf("%d %c\n", n - line, c);
	} else {
		char c = 'A' + (column / 26) - 1;
		char cc = 'A' + (column % 26);

		printf("%d %c%c\n", n - line, c, cc);
	}

	return 0;
}
