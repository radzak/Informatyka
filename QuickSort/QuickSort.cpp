#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define RANGE 10
short tab[RANGE];

void generowanie ( short tablica_pusta[] )
{
    srand( time( NULL ) );
    cout << "Wygenerowano " << RANGE << " liczb:" << endl;
    for (long long i = 0; i < RANGE; i++)
    {
        tablica_pusta[i] = rand()%10000;
        cout << tablica_pusta[i] << "  ";
    }
    cout << endl << endl;
}


void quicksort(int pocz, int kon, short tab[])
{
    int i, j, pivot;
    i = pocz;
    j = kon;
    pivot = tab[div(pocz+kon, 2).quot];
    do
    {
        while(tab[i]<pivot) i++;
        while(tab[j]>pivot) j--;
        if(i<=j){
            swap(tab[i], tab[j]);
            for (long long i = 0; i < RANGE; i++) cout << tab[i] << "  ";
            cout << endl;
            i++; j--;
        }
    }while(i<=j);
    if(pocz<j) quicksort(pocz, j, tab);
    if(i<kon) quicksort(i, kon, tab);


}


int main( void )
{
    generowanie(tab);
    quicksort(0, RANGE-1, tab);
    for (long long i = 0; i < RANGE; i++) cout << tab[i] << "  ";
    return 0;
}
