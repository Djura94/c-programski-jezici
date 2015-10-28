//Borisa Eric
//borisa123@hotmail.com
//github.com/PrisonBreakeR/c-programski-jezici
//Feel free to contact me.

/*Napisati program na C - u za dekompresiju zadatog niza celih brojeva.
Niz se sa standardnog ulaza ucitava u kompresovanom obliku
(na svakoj parnoj poziciji stoji element vektora, a na
sledecoj neparnoj, broj uzastopnih ponavljanja prethodnog elementa).
Niz pamtiti u dinamickoj zoni memorije i u programu ne koristiti pomocne nizove.
Za niz je rezervisano tacno onoliko memorijskog prostora koliko elemenata ima.*/
#include<stdio.h>
#include<stdlib.h>

main()
{
	//Inicijalizacija
	int br_elem=1, *niz, i, brojPonavljanja, j, k, temp=0;

	//Unos broja elemenata i niza

	while (br_elem%2!=0)
	{
		printf("Unesite broj elemenata: ");
		scanf_s("%d", &br_elem);
	}
	niz = (int*)malloc(br_elem*sizeof(int));
	for (i = 0; i < br_elem; i++)
	{
		if (i%2==0)
			printf("Unesite parni clan niza: ");
		else
			printf("Unesite neparni clan niza: ");

		scanf_s("%d", &niz[i]);
	}

	//Ispisivanje unesenog niza
	printf("\n\nNiz treba kompresovati na sledeci nacin:");
	for (i = 0; i < br_elem-1; i+=2)
	{
		printf("\n\t\t%d x %d", niz[i], niz[i+1]);
	}

	//Dekompresija niza
	for (i = 1; i<br_elem; i += 2)
	{
		temp += niz[i];
	}
	niz = (int*)realloc(niz, temp*sizeof(int));

	k = temp - 1;

	for (i = br_elem - 1; i>0; i -= 2)
	{
		brojPonavljanja = niz[i]; //odredjivanje broja ponavljanja
		for (j = 0; j < brojPonavljanja; j++)
		{
			niz[k--] = niz[i - 1];
		}
	}
	br_elem = temp;

	//Ispisivanje niza posle kompresije
	printf("\n\nNiz posle dekompresije: ");
	for (i = 0; i < br_elem; i ++)
	{
		printf("%d ", niz[i]);
	}

	//Press any key to continue...
	printf("\n\n");
	system("pause");
}