//============================================================================
// Name        : WB.cpp
// Author      : Radosław Krzak
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;


void printowanie(int tab[], int length)
{
	cout << "Tablica: " << endl;
	for ( int i = 0; i < length; i++)
		cout << tab[i] << endl;
}


void generowanie(int tab[], int length, int range)
{
	for ( int i = 0; i < length; i++)
		tab[i] = rand() % range;
}


void get_info(int *ile, int *range, int *szukana)
{
	cout << "Podaj ile liczb chcesz wygenerowac?" << endl;
	cin >> *ile;
	cout << "Podaj zakres generowanych liczb? " << endl;
	cin >> *range;
	cout << "Podaj szukana liczbe? " << endl;
	cin >> *szukana;
}


int wyszukiwanie_binarne(int tab[], int *szukana, int srodek, int *ile)
{
	if ( tab[srodek] > *szukana )
		srodek = wyszukiwanie_binarne(tab, szukana, srodek / 2, ile);
	else if (tab[srodek] < *szukana)
		srodek = wyszukiwanie_binarne(tab, szukana, srodek + (srodek / 2), ile);
	else if ( tab[srodek] == *szukana)
	{
		cout << "Index "<< srodek << endl;
		exit(1);
	}
	else if ( srodek == 0 or srodek == *ile)
		return -1;
	return 0;

}


int main() {
	srand(time(NULL));

	int ile, range, szukana;

	get_info(&ile, &range, &szukana);

	int tab[ile];

	generowanie(tab, ile, range);
	printowanie(tab, ile);

	sort(tab, tab+ile);

	cout << "Posortowane liczby: " << endl;
	printowanie(tab, ile);

	int srodek = ile/2;
	wyszukiwanie_binarne(tab, &szukana, srodek, &ile);

	return 0;
}
