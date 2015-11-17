//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

/////////////////////////////////////////////////////////////////////
/*Zadatak 3: Napisati program na C - u kojim se iz znakovnog niza S
dužine m karaktera izbacuju sve pojave slova V. Stampati niz S pre i
posle transformisanja.
NAPOMENA : Niz S pamtiti u dinamickoj zoni memorije i pre i posle
transformisanja on treba da zauzima onoliki deo memorijskog prostora
koliko je potrebno za pamcenje njegove vrednosti.Elementima niza uvek
pristupati koriscenjem pokazivaca.*/
/////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

void main()
{
	char *S;
	char slovo = ' ';
	int m = 0, n, i, j;

	S = (char*)malloc(m*sizeof(char));

	printf("Unesite string S: ");
	while (slovo != '\n')
	{
		S = (char*)realloc(S, (m + 1)*sizeof(char));
		scanf_s("%c", &slovo);
		if (slovo != '\n')
		{
			*(S + m) = slovo;
		}
		else
		{
			*(S + m) = '\0';
		}
		m++;
	}

	printf("String S: %s, duzina: %d", S, m);

	for (i = 0; i < m; i++)
	{
		if (*(S + i) == 'v' || *(S + i) == 'V')
		{
			for (j = i; j < m; j++)
			{
				*(S + j) = *(S + j + 1);
			}
			S = (char*)realloc(S, (m)*sizeof(char));
			m--;
			*(S + m) = '\0';
			i--;
		}
	}
	printf("\nTransformisani string S: %s, duzina: %d", S, m-1);

	free(S);

	printf("\n\n");
	system("pause");
}


