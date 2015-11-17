//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

/////////////////////////////////////////////////////////////////////////
/*Zadatak 4: Napisati program na C-u kojim se iz zadatog celogrojnog
niza A={a1, a2, ..., an} izbacuju svi duplikati. Stampati niz S pre i
posle transformisanja.
NAPOMENA: Niz A pamtiti u dinami?koj zoni memorije i pre i posle
transformisanja on treba da zauzima onoliki deo memorijskog prostora
koliko je potrebno za pamcenje njegovih elemenata. Elementima niza uvek
pristupati koriscenjem pokazivaca.*/
/////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int niz[] = { 1,2,3,1,2,3,3,2,1,4,5,6,5,6,5,7,8,9,9,8,3 };
	int duzinaNiza;
	int i, *A, j, k;

	A = (int*)malloc(0 * sizeof(int));

	duzinaNiza = 21;
	for (i = 0; i < duzinaNiza; i++)
	{
		A = (int*)realloc(A, (i + 1)*sizeof(int));
		*(A + i) = *(niz + i);
	}

	printf("Niz prije transformacije: ");
	for (i = 0; i < duzinaNiza; i++)
	{
		printf("%d ", *(A + i));
	}
	printf("\nDuzina niza: %d", duzinaNiza);

	//transformacija
	for (i = 0; i < duzinaNiza; i++)
	{
		for (j = i + 1; j < duzinaNiza; j++)
		{
			if (*(A + i) == *(A + j))
			{
				for (k = j; k < duzinaNiza; k++)
				{
					*(A + k) = *(A + k + 1);
				}
				A = (int*)realloc(A, (duzinaNiza - 1)*sizeof(int));
				duzinaNiza--;
				j--;
			}
		}
	}

	printf("\n\nNiz poslije transformacije: ");
	for (i = 0; i < duzinaNiza; i++)
	{
		printf("%d ", *(A + i));
	}
	printf("\nDuzina niza: %d", duzinaNiza);

	free(A);

	printf("\n\n");
	system("pause");
}

