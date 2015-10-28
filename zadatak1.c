//Borisa Eric
//borisa123@hotmail.com
//github.com/PrisonBreakeR/c-programski-jezici
//Feel free to contact me.

/*Napisati program koji od elemenata dinamickog niza formira
druga dva dinamicka niza, niz pozitivnih i niz negativnih brojeva.
Prikazati elemente tako dobijenih nizova.*/
#include<stdio.h>
#include<stdlib.h>

main()
{
	//Inicijalizacija
	int br_elem, i, *niz, *nizPoz, *nizNeg, brPoz, brNeg;

	//Unos niza
	printf("Unesite broj elemenata niza: ");
	scanf("%d", &br_elem);
	niz = (int*)malloc(br_elem*sizeof(int)); //rezervisanje prostora
	for ( i = 0; i < br_elem; i++)
	{
		printf("Unesite %d. clan niza: ", i + 1);
		scanf("%d", &niz[i]);
	}

	//Rezervisanje prostora za dva nova niza
	brNeg = brPoz = 0;
	nizPoz = (int*)malloc(brPoz*sizeof(int));
	nizNeg = (int*)malloc(brNeg*sizeof(int));

	//Brojanje pozitivnih i negativnih ?lanova
	for ( i = 0; i < br_elem; i++)
	{
		if (niz[i] >= 0)
		{
			brPoz++;
			nizPoz = (int*)realloc(nizPoz, brPoz*sizeof(int)); //prosirenje niza za 1 clan po iteraciji
			nizPoz[brPoz-1] = niz[i];
		}
		else
		{
			brNeg++;
			nizNeg = (int*)realloc(nizNeg, brNeg*sizeof(int)); //prosirenje niza za 1 clan po iteraciji
			nizNeg[brNeg-1] = niz[i];
		}
	}

	//Printanje pozitivnog niza
	if (brPoz == 0)
	{
		printf("\n\nU unesenom nizu nije pronadjen nijedan pozitivan clan!");
	}
	else
	{
		printf("\n\nNiz pozitivnih brojeva:");
		for ( i = 0; i < brPoz; i++)
		{
			printf("\t%d", nizPoz[i]);
		}
	}
	free(nizPoz); //oslobadjanje memorija

	//Printanje negativnog niza
	if (brNeg == 0)
	{
		printf("\n\nU unesenom nizu nije pronadjen nijedan negativan clan!");
	}
	else
	{
		printf("\n\nNiz negativnih brojeva:");
			for (i = 0; i < brNeg; i++)
			{
				printf("\t%d", nizNeg[i]);
			}
	}
	free(nizNeg); //oslobadjanje memorije

	//Printanje niza
	printf("\n\nUneseni niz:");
	for (i = 0; i < br_elem; i++)
	{
		printf("\t%d", niz[i]);
	}
	free(niz);

	//Press any key to continue
	printf("\n\n\n");
	system("pause");
}