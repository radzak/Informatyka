#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int ile;
int range;


void generowanie(int tablica[])
{
    for(int i=0; i<ile;i++)
        tablica[i]=rand()%range;
}


void printowanie(int tablica[])
{
    for(int i=0; i<ile;i++)
        cout << tablica[i] << "  ";
}


void insertion_sort_liniowy(int tablica[])
{
    int liczba;
    int x;
    for(int i=ile-2; i>=0; i--)
    {
        x = i;
        liczba = tablica[i];
        cout << "liczba to: " << liczba << endl;
        while(liczba>tablica[x+1] && x<ile-1)
        {
            tablica[x] = tablica[x+1];
            //printowanie(tablica);
            cout << endl;
            x++;
        }
        cout << "liczba to: " << liczba << endl;
        tablica[x] = liczba;
        printowanie(tablica);
        cout << "nowy przebieg" << endl;
    }
}




int main( void )
{
    srand(time(NULL));
    cout << "Podaj ile liczb chcesz wygenerowac w celu posortowania?" << endl;
    cin >> ile;
    cout << endl;

    cout << "Podaj zasieg generowanych liczb?" << endl;
    cin >> range;
    cout << endl;

    int tab[ile];
    cout << "Wygenerowane liczby to:" << endl;
    generowanie(tab);
    printowanie(tab);
    cout << endl;
    insertion_sort_liniowy(tab);
    cout << endl;
    cout << "Sortowanie liniowe:" << endl;
    printowanie(tab);
    return 0;
}
