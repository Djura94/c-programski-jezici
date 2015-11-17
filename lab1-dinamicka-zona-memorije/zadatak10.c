//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

////////////////////////////////////////////////////////
/*Zadatak 10: Napisati program na C - u koji ce od
proizvoljnog niza pozitivnih projeva kreirati niz
jednocifrenih brojeva, tako što ce svaki visecifreni
broj rastaviti na njegove cifre(npr. 159 -> 1, 5, 9).
NAPOMENA : Niz pamtiti u dinamickoj zoni memorije i pre
i posle transformisanja on treba da zauzima onoliki deo
memorijskog prostora koliko je potrebno za pamcenje
njegovih elemenata.*/
////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

main()
{
	int *A, *B;
	int duzina = 0, duzinaB = 0;
	int i, j, izlaz, broj, cifra;

	A = (int*)malloc(duzina*sizeof(int));
	B = (int*)malloc(duzinaB*sizeof(int));

	printf("Unesite duzinu niza: ");
	scanf_s("%d", &duzina);
	printf("Unesite niz A: ");
	for (i = 0; i < duzina; i++)
	{
		A = (int*)realloc(A, (i + 1)*sizeof(int));
		scanf_s("%d", (A + i));
	}

	for (i = 0; i < duzina; i++)
	{
		izlaz = 0;
		broj = *(A + i);
		cifra = 0;

		//prebrojavanje cifara
		for (j = 0; izlaz == 0; j++)
		{
			if (broj != 0)
			{
				cifra++;
				broj = broj / 10;
			}
			else
			{
				izlaz = 1;
			}
		}
		broj = *(A + i);
		duzinaB += cifra;
		B = (int*)realloc(B, (duzinaB)*sizeof(int));
		//upis cifara u novi niz
		for (j = duzinaB - 1; j >= duzinaB - cifra; j--)
		{
			*(B + j) = broj % 10;
			broj = broj / 10;
		}
	}

	//printanje niza
	printf("Niz jednocifrenih brojeva B: ");
	for (i = 0; i < duzinaB - 2; i++)
	{
		printf("%d, ", *(B + i));
	}
	printf("%d i %d.", *(B + duzinaB - 2), *(B + duzinaB - 1));

	free(A);
	free(B);

	printf("\n\n");
	system("pause");
}