#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printowanie(int tablica[], long *rozmiar)
{
    for(long i=0; i<*rozmiar; i++) cout << tablica[i] << "  ";
}


void generowanie(int tablica[], long *rozmiar, int *range)
{
    for (long i=0; i<*rozmiar; i++) tablica[i] = rand()%*range;
    printowanie(tablica, rozmiar);
    cout << endl << endl;
}


void select_sort(int tab[], long *rozmiar)
{
    long index;
    for(long i=0; i<*rozmiar-1; i++)
    {
        index = i;
        for(long j=i+1; j<*rozmiar; j++)
        {           
            if(tab[j] <= tab[index])
                index = j;
        }
        swap(tab[i], tab[index]);
    }
}


void get_info(long *rozmiar, int *range)
{
    cout << "Ile liczb chcesz wygenerowac w celu sortowania?" << endl;
    cin >> *rozmiar;
    cout << "Podaj zasieg generowanych liczb" << endl;
    cin >> *range;
}


int main( void )
{
    srand(time(NULL));
    long ile;
    int range;
    get_info(&ile, &range);
    int tab[ile];

    cout << "Wygenerowane liczby to:" << endl;
    generowanie(tab, &ile, &range);
    select_sort(tab, &ile);
    cout << "Liczby po posortowaniu:" << endl;
    printowanie(tab, &ile);
    return 0;
}

