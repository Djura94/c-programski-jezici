//Borisa Eric 
//borisa123@hotmail.com 
//github.com/PrisonBreakeR/c-programski-jezici 
//Feel free to contact me. 

//////////////////////////////////////////////////////////////////////////////////////////
/*Zadatak 1: Napisati program na C-u kojim se u znakovni niz S1 duzine m karaktera
umece znakovni niz S2 dužine n karaktera pocev od pozicije k. Stampati niz S1 pre
i posle transformisanja.
NAPOMENA: Nizove S1 i S2 pamtiti u dinamickoj zoni memorije i za svaki od njih rezervisati
onoliko prostora koliko je potrebno za predstavljanje njihovih vrednosti. Elementima nizova
uvek pristupati koriscenjem pokazivaca.*/
//////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

main()
{
	char *s1, *s2, pom;
	char slovo;
	int m = 0, n = 0, izlaz = 0, k, i;


	s1 = (char*)malloc(m*sizeof(char));
	printf("Unesite string S1: ");
	while (izlaz == 0)
	{
		scanf_s("%c", &slovo);

		s1 = (char*)realloc(s1, (m + 1)*sizeof(char));
		if (slovo != '\n')
		{
			*(s1 + m) = slovo;
		}
		else
		{
			*(s1 + m) = '\0';
			izlaz = 1;
		}
		m++;
	}

	izlaz = 0;
	s2 = (char*)malloc(n*sizeof(char));
	printf("Unesite string S2: ");
	while (izlaz == 0)
	{
		scanf_s("%c", &slovo);

		s2 = (char*)realloc(s2, (n + 1)*sizeof(char));
		if (slovo != '\n')
		{
			*(s2 + n) = slovo;
		}
		else
		{
			*(s2 + n) = '\0';
			izlaz = 1;
		}
		n++;
	}
	printf("\n\nUnijeli ste stringove S1:%s %d i  S2:%s %d\n\n", s1, m - 1, s2, n - 1);

	printf("Unesite poziciju k: ");
	scanf_s("%d", &k);

	s1 = (char*)realloc(s1, (m + n + 1)* sizeof(char));

	for (i = k; i < m; i++)
	{
		*(s1 + i + n - 1) = *(s1 + i);
	}

	for (i = 0; i < n - 1; i++)
	{
		*(s1 + i + k) = *(s2 + i);
	}
	*(s1 + m + n - 2) = '\0';

	printf("\nString posle umetanja S2 u S1 od pozicije %d: \n%s\n\n", k, s1);

	free(s1);
	free(s2);
   
	system("pause");
}

