#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int ile;
int range;

void get_info()
{
    cout << "Ile liczb chcesz wygenerowac, a nastepnie posortowac?" << endl;
    cin >> ile;
    cout << endl << "Podaj zasieg generowanych liczb" << endl;
    cin >> range;
    cout << endl;
}


void printowanie(int tab[], int range)
{
    for(int i=0; i<range; i++) cout << tab[i] << "  ";
}


void generowanie(int tab[])
{
    for(int i=0; i<ile; i++) tab[i] = rand()%range;
}


int wysz_liniowe(int tab[], int range, int szukana)
{
    for(int i=0; i<range; i++)
        if(tab[i] == szukana)
            return i;
    return -1;
}


int main( void )
{
    srand(time(NULL));
    get_info();
    int tab[ile];
    generowanie(tab);
    printowanie(tab, ile);
    sort(tab, tab+ile);
    cout << endl;
    printowanie(tab, ile);
    if(wysz_liniowe(tab, ile, 5)!= -1)
        cout << "szukana liczba jest na pozycji: " << wysz_liniowe(tab, ile, 5);
    else
        cout << "brak takiej liczby";
}
