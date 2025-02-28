//Copyright Maria Bianca Popescu 2023

#include <stdio.h>

#define NMAX 100

// functie pentru verificarea corectitudinii puzzle-ului
int check_nonogram(int line,
				   int column,
				   int line_restr[NMAX][NMAX],
				   int column_restr[NMAX][NMAX],
				   int grid[NMAX][NMAX]
)
{
	int line_groups[NMAX];
	int column_groups[NMAX];
	int count = 0;

	for (int i = 0; i < line; i++) {
		int pos = 0;

		for (int j = 0; j < column; j++) {
			if (grid[i][j] == 1) {
				count++; // numaram cate valori de 1 avem in fiecare grup
			} else {
				if (count != 0) {
					// salvam dimensiunile intr-un vector de aparitii
					line_groups[pos] = count;
					pos++;
					count = 0;
				}
			}

			// cazul in care ultimul element din linie e 1
			if (count != 0 && j == column - 1) {
				line_groups[pos] = count;
				pos++;
				count = 0;
			}
		}

		// nr de grupuri nu corespunde cu nr specificat pe prima pozitie
		if (pos != line_restr[i][0])
			return 0;

		// comparam vectorul de aparitii cu restrictiile
		for (int j = 1; j <= line_restr[i][0]; j++) {
			if (line_groups[j - 1] != line_restr[i][j])
				return 0;
		}
	}

	// acelasi lucru pentru coloane
	for (int i = 0; i < column; i++) {
		int pos = 0;

		for (int j = 0; j < line; j++) {
			if (grid[j][i] == 1) {
				count++;
			} else {
				if (count != 0) {
					column_groups[pos] = count;
					pos++;
					count = 0;
				}
			}

			if (count != 0 && j == line - 1) {
				column_groups[pos] = count;
				pos++;
				count = 0;
			}
		}

		if (pos != column_restr[i][0])
			return 0;

		for (int j = 1; j <= column_restr[i][0]; j++) {
			if (column_groups[j - 1] != column_restr[i][j])
				return 0;
		}
	}

	return 1;
}

int main(void)
{
	int T;

	scanf("%d\n", &T); //citim numarul de puzzle-uri

	for (int t = 0; t < T; t++) {
		int line, column;
		int line_restr[NMAX][NMAX];
		int column_restr[NMAX][NMAX];

		scanf("%d %d\n", &line, &column); //citim numarul de linii si coloane

		for (int i = 0; i < line; i++) {
			int groups = 0; // numarul grupurilor de pe linia i
			scanf("%d", &groups);

			// salvam numarul grupurilor pe prima pozitie din linia i
			line_restr[i][0] = groups;

			for (int j = 1; j <= groups; j++)
				scanf("%d", &line_restr[i][j]);
		}

		for (int i = 0; i < column; i++) {
			int groups = 0; // numarul grupurilor de pe coloana i
			scanf("%d", &groups);

			// salvam numarul grupurilor pe prima pozitie din coloana i
			column_restr[i][0] = groups;

			for (int j = 1; j <= groups; j++)
				scanf("%d", &column_restr[i][j]);
		}

		int grid[NMAX][NMAX];

		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++)
				scanf("%d", &grid[i][j]); // citim grid-ul
		}

		if (check_nonogram(line, column, line_restr, column_restr, grid))
			printf("Corect\n"); // verificam corectitudinea
		else
			printf("Eroare\n");
	}

	return 0;
}
