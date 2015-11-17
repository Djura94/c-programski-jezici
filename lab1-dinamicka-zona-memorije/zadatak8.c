//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

////////////////////////////////////////////////////////////
/*Zadatak 8: Napisati program na C-u koji ce niz brojeva
(min=0, max=15) transformisati u prividno binarni niz,
tj. potrebno je svaki broj iz originalnog niza prestaviti
sa cetiri cifre (0 i 1).
NAPOMENA: Niz pamtiti u dinamickoj zoni memorije i pre i
posle transformisanja on treba da zauzima onoliki deo
memorijskog prostora koliko je potrebno za pamcenje
njegovih elemenata.*/
////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

main()
{
	int *A;
	char *S;
	int duzina = 0, duzinaS = 0;
	int i, j;
	char prva, druga, treca, cetvrta;

	A = (int*)malloc(duzina*sizeof(int));
	S = (char*)malloc(duzinaS*sizeof(char));

	printf("Unesite duzinu niza: ");
	scanf_s("%d", &duzina);
	printf("Unesite niz A: ");
	for (i = 0; i < duzina; i++)
	{
		A = (int*)realloc(A, (i + 1)*sizeof(int));
		scanf_s("%d", (A + i));
	}

	printf("\nNiz u binarnom zapisu glasi!\n");
	for (i = 0; i < duzina; i++)
	{
		prva = '0';
		druga = '0';
		treca = '0';
		cetvrta = '0';
		if (*(A + i) >= 8)
		{
			prva = '1';
			*(A + i) -= 8;
		}
		if (*(A + i) >= 4)
		{
			druga = '1';
			*(A + i) -= 4;
		}
		if (*(A + i) >= 2)
		{
			treca = '1';
			*(A + i) -= 2;
		}
		if (*(A + i) == 1)
		{
			cetvrta = '1';
		}
		S = (char*)realloc(S, (duzinaS + 4)*sizeof(char));
		*(S + duzinaS) = prva;
		duzinaS++;
		*(S + duzinaS) = druga;
		duzinaS++;
		*(S + duzinaS) = treca;
		duzinaS++;
		*(S + duzinaS) = cetvrta;
		duzinaS++;
	}
	*(S + duzinaS) = '\0';

	for (i = 0; i < duzinaS; i++)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n");
		printf("%c", *(S + i));
	}

	printf("\n\n");
	system("pause");
}