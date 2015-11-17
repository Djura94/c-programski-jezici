//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

//////////////////////////////////////////////////////////////////
/*Zadatak 7:  Napisati program na C-u za izracunavanje preseka
dva skupa. Skupovi su zadati kao nizovi celih brojeva. Nizovi
se ucitavaju sa standardnog ulaza i pamtimo ih u dinamickoj zoni
memorije. Za ulazne nizove, kao i za rezultantni niz, treba da
bude rezervisano tacno onoliko memorijskog prostora koliko
elemenata imaju.
NAPOMENA: Niz pamtiti u dinamickoj zoni memorije i pre i posle 
transformisanja on treba da zauzima onoliki deo memorijskog 
prostora koliko je potrebno za pamcenje njegovih elemenata.*/
//////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

main()
{
	int *A, *B, *C;
	int duzina1 = 0, duzina2 = 0, duzina3 = 0;
	int i, j, k;

	A = (int*)malloc(duzina1*sizeof(int));
	B = (int*)malloc(duzina2*sizeof(int));
	C = (int*)malloc(duzina3*sizeof(int));

	printf("Unesite duzinu niza A: ");
	scanf_s("%d", &duzina1);
	printf("Unesite duzinu niza B: ");
	scanf_s("%d", &duzina2);

	printf("\nUnesite niz A: ");
	for (i = 0; i < duzina1; i++)
	{
		A = (int*)realloc(A, (i + 1)*sizeof(int));
		scanf_s("%d", (A + i));
	}
	printf("Unesite niz B: ");
	for (i = 0; i < duzina2; i++)
	{
		B = (int*)realloc(B, (i + 1)*sizeof(int));
		scanf_s("%d", (B + i));
	}

	for (i = 0; i < duzina1; i++)
	{
		for (j = 0; j < duzina2; j++)
		{
			if (*(A + i) == *(B + j))
			{
				for (k = 0; k < duzina3; k++)
				{
					if (*(A + i) == *(C + k))
						duzina3--;
				}
				C = (int*)realloc(C, (duzina3 + 1)*sizeof(int));
				*(C + duzina3) = *(A + i);
				duzina3++;
			}
		}
	}

	printf("\nPresek A i B je niz C: ");
	for (i = 0; i < duzina3; i++)
	{
		printf("%d ", *(C + i));
	}

	free(A);
	free(B);
	free(C);

	printf("\n\n");
	system("pause");
}

