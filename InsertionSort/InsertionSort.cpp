#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generowanie(int tablica[], int *ile, int *range)
{
    for(int i=0; i<*ile;i++)
        tablica[i]=rand()%*range;
}

void printowanie(int tablica[], int *ile)
{
    for(int i=0; i<*ile;i++)
        cout << tablica[i] << "  ";
}

void get_info(int *ile, int *range)
{
    cout << "Podaj ile liczb chcesz wygenerowac w celu posortowania?" << endl;
    cin >> *ile;
    cout << endl;

    cout << "Podaj zasieg generowanych liczb?" << endl;
    cin >> *range;
    cout << endl;
}

void insertion_sort_liniowy(int tablica[], int *ile)
{
    int liczba;
    int x;
    for(int i=*ile-2; i>=0; i--)
    {
        x = i;
        liczba = tablica[i];
        while(liczba>tablica[x+1] && x<*ile-1)
        {
            tablica[x] = tablica[x+1];
            x++;
        }
        tablica[x] = liczba;
        //printowanie(tablica);
    }
}




int main( void )
{
    srand( time ( NULL ) );
    int ile, range;
    get_info(&ile, &range);
    int tab[ile];

    cout << "Wygenerowane liczby to:" << endl;
    generowanie(tab, &ile, &range);
    printowanie(tab, &ile);

    insertion_sort_liniowy(tab, &ile);

    cout << endl << endl << "Sortowanie liniowe:" << endl;
    printowanie(tab, &ile);
    return 0;
}
