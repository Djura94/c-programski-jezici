//Borisa Eric
//borisa123@hotmail.com
//github.com/PrisonBreakeR/c-programski-jezici
//Feel free to contact me.

/*Napisati program na C-u za zamenu prve pojave
podstringa s1 u stringu s stringom s2.
Stringovi s1 i s2 mogu biti razlicitih duzina.
Sve stringove pamtiti u dinamickoj zoni memorije i
za svaki od njih u svakom trenutku treba da bude
rezervisano onoliko memorijskog prostora
koliko je potrebno za pamcenje njihovih vrednosti.*/
#include<stdio.h>
#include<stdlib.h>

main()
{
	//Inicijalizacija
	int duzinaS, duzinaS1, duzinaS2, i, j, k;
	char *stringS, *stringS1, *stringS2;

	//Unos duzine stringova i rezervacija memorije
	printf("Unesite duzine stringova (S, S1, S2): ");
	scanf("%d %d %d", &duzinaS, &duzinaS1, &duzinaS2);
	stringS = (char*)malloc(duzinaS + 1); //rezervisanje prostora
	stringS1 = (char*)malloc(duzinaS1 + 1); //rezervisanje prostora
	stringS2 = (char*)malloc(duzinaS2 + 1); //rezervisanje prostora

	//Unos stringova
	printf("\nUnesite string S: ");
	scanf("%s", stringS);
	printf("Unesite string S1 iz S koji zelite da zamjenite sa stringom S2: ");
	scanf("%s", stringS1);
	printf("Unesite string S2: ");
	scanf("%s", stringS2);

	//Trazimo S1 u S
	//i je pocetna adresa od koje trazimo s1 u s
	//j je broj pronadjenih slova
	for (i = 0, j = 0; i <= duzinaS - duzinaS1 && j<duzinaS1; )
	{
		if (stringS[i + j] == stringS1[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}

	//Transformacija
	if (j<duzinaS1)
		printf("String S1 ne postoji u strigu S!\n");
	else
	{
		if (duzinaS2>duzinaS1)
		{
			//Treba prosiriti string S
			k = duzinaS2 - duzinaS1;
			realloc(stringS, duzinaS + k + 1);
			for (j = duzinaS; j >= i + duzinaS1; j--)
				stringS[j + k] = stringS[j];
		}
		else if (duzinaS1>duzinaS2)
		{
			//Treba smanjiti string S
			k = duzinaS1 - duzinaS2;
			for (j = i + duzinaS1; j <= duzinaS; j++)
				stringS[j - k] = stringS[j];
			realloc(stringS, duzinaS - k + 1);
		}
		for (j = 0; j<duzinaS2; j++)
			stringS[i + j] = stringS2[j];
		printf("Transformisani string je: %s\n", stringS);
	}

	//Press any key to continue
	printf("\n\n\n");
	system("pause");
}