//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

/////////////////////////////////////////////////////////
/*Zadatak 5: Napisati program na C-u kojim se iz zadate
kvadratne matrice A(nxn) izbacuje k-ta kolona. Stampati
matricu pre i posle transformisanja.
NAPOMENA: Matricu A pamtiti u dinamickoj zoni memorije
i pre i posle transformisanja ona treba da zauzima
onoliki deo memorijskog prostora koliko je potrebno
za pamcenje njenih elemenata. Elementima matrice uvek
pristupati koriscenjem pokazivaca.*/
/////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void brisanjeKolone(int **matrica, int k, int n);

void main()
{
	int n, broj;
	int **M;
	int i, j, k;

	M = (int**)malloc(0 * sizeof(int*));

	printf("Unesite dimenziju matrice n: ");
	scanf_s("%d", &n);

	//rezervisanje prostora
	M = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		*(M + i) = (int*)malloc(n*sizeof(int));
	}

	//unos matrice
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &broj);
			*(*(M + i) + j) = broj;  //pristupanje preko pokazivaca
									 //M[i][j] = broj;
		}
	}

	printf("Unesite koju kolonu zelite da izbacite: ");
	scanf_s("%d", &k);

	//stampanje matrice poslije transformacije
	printf("\nMatrica prije transformacije:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", *(*(M + i) + j));
		}
		printf("\n");
	}

	//transformacija
	for (i = 0; i < n; i++)
	{
		for (j = k - 1; j < n - 1; j++)
		{
			//M[i][j] = M[i][j+1];
			*(*(M + i) + j) = *(*(M + i) + j + 1);
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		*(M + i) = (int*)realloc(*(M + i), (n - 1)*sizeof(int));
	}

	//stampanje matrice poslije transformacije
	printf("\nMatrica poslije transformacije:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			printf("%d ", *(*(M + i) + j));
		}
		printf("\n");
	}

	//oslobadjanje memorije
	for (i = 0; i < n; i++)
	{
		//*(M + i) = (int*)realloc(*(M+i), 0*sizeof(int));
		free(*(M + i));
	}
	//M = (int**)realloc(M, 0 * sizeof(int*));
	free(M);

	printf("\n\n");
	system("pause");
}

