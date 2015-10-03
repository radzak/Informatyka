#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generowanie (int tab[], int *ile, int *range)
{
    for(int i=0; i<*ile; i++) tab[i]=rand()%*range;
}

void printowanie (int tab[], int *ile)
{
    for(int i=0; i<*ile; i++) cout << tab[i] << "  ";
}

void get_info(int *ile, int *range)
{
    cout << "Ile liczb chcesz wygenerowac?" << endl;
    cin >> *ile;
    cout << endl;

    cout << "Podaj zakres generowanych liczb?" << endl;
    cin >> *range;
    cout << endl;
}

void quicksort(int pocz, int kon, int tab[], int ile)
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
            //printowanie(tab, ile);
            i++; j--;
        }
    }while(i<=j);
    if(pocz<j) quicksort(pocz, j, tab, ile);
    if(i<kon) quicksort(i, kon, tab, ile);
}

int main( void )
{
    int ile, range;

    get_info(&ile, &range);

    int tab[ile];

    generowanie(tab, &ile, &range);
    cout << "Wygenerowane liczby:" << endl;
    printowanie(tab, &ile);

    quicksort(0, ile-1, tab, ile);
    cout << endl << endl << "Posortowane liczby:" << endl;
    printowanie(tab, &ile);
    return 0;
}
