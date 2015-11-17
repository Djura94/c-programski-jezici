//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

/////////////////////////////////////////////////////////////////////
/*Zadatak 2: Napisati program na C-u kojim se iz znakovnog niza S
dužine m karaktera izbacuje n karaktera pocev od pozicije k.
Stampati niz S pre i posle transformisanja.
NAPOMENA: Niz S pamtiti u dinamickoj zoni memorije i pre i posle
transformisanja on treba da zauzima onoliki deo memorijskog prostora
koliko je potrebno za pamcenje njegove vrednosti. Elementima niza
uvek pristupati koriscenjem pokazivaca.*/
/////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

void main()
{
	char *S;
	char slovo = ' ';
	int m = 0, n, k, i, j;

	S = (char*)malloc(m*sizeof(char));

	printf("Unesite string S: ");
	while (slovo != '\n')
	{
		S = (char*)realloc(S, (m + 1)*sizeof(char));
		scanf_s("%c", &slovo);
		if (slovo != '\n')
		{
			*(S + m) = slovo;
			m++;
		}
		else
			*(S + m) = '\0';
	}

	printf("String S: %s, duzina: %d", S, m);

	printf("\n\nUnesite poziciju k i duzinu n: ");
	scanf_s("%d %d", &k, &n);

	for (i = 0; i < m; i++)
	{
		if (i >= k && i<k + n)
		{
			for (j = k; j < m; j++)
			{
				*(S + j) = *(S + j + 1);
			}
			m--;
			S = (char*)realloc(S, (m + 1)*sizeof(char));
			*(S + m) = '\0';
		}
	}
	printf("\nTransformisani string S: %s, duzina: %d", S, m);
	free(S);

	printf("\n\n\n");
	system("pause");
}

