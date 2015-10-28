//Borisa Eric
//borisa123@hotmail.com
//github.com/PrisonBreakeR/c-programski-jezici
//Feel free to contact me.

/*Napisati program na C-u za kompresiju zadatog niza celih brojeva.
Poznato je da se u ulaznom nizu "svaki" element ponavlja najmanje
dva puta uzastopno. U kompresovanom nizu, na svakoj parnoj poziciji
treba da stoji element vektora, a na sledecoj neparnoj, broj
uzastopnih ponavljanja prethodnog elementa. Niz pamtiti u dinamickoj
zoni memorije i u programu ne koristiti pomocne nizove. Za niz
rezervisati tacno onoliko memorijskog prostora koliko elemenata ima.*/
#include<stdio.h>
#include<stdlib.h>

main()
{
	//Inicijalizacija
	int br_elem, *niz, i, brojPonavljanja, j=0;

	//Unos broja elemenata i niza
	printf("Unesite broj elemenata: ");
	scanf_s("%d", &br_elem);
	niz = (int*)malloc(br_elem*sizeof(int));
	for ( i = 0; i < br_elem; i++)
	{
		printf("Unesite %d. clan niza: ", i+1);
		scanf_s("%d", &niz[i]);
	}

	//Ispisivanje unesenog niza
	printf("\n\nNiz koji treba kompresovati:");
	for ( i = 0; i < br_elem; i++)
	{
		printf("\t%d", niz[i]);
	}

	//Kompresija niza
	brojPonavljanja = 1; //ne prebrojavamo prvi element
	for ( i = 0; i < br_elem; i++)
	{
		if (niz[i]==niz[i+1]) //uvijek se izvrsava bar jednom iz uslova zadatka
		{
			brojPonavljanja++;
		}
		else
		{
			niz[j++] = niz[i];
			niz[j++] = brojPonavljanja;
			brojPonavljanja = 1;
		}
	}
	niz[j++] = niz[i];
	niz[j] = brojPonavljanja;
	niz = (int*)realloc(niz, j*sizeof(int));

	//Ispisivanje niza posle kompresije
	printf("\n\nNiz posle kompresije: ");
	for ( i = 0; i < j-1; i+=2) //ispisujemo po dva clana
	{
		printf("\n\t\t\t%d x %d", niz[i], niz[i + 1]);
	}

	//Press any key to continue...
	printf("\n\n");
	system("pause");
}