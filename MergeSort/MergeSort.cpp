#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printowanie(int tablica[], int *rozmiar)
{
    for(int i=0; i<*rozmiar; i++)
        cout << tablica[i] << "  ";
    cout << endl;
}


void generowanie(int tablica[], int *rozmiar, int *range)
{
    for(int i=0; i<*rozmiar; i++)
        tablica[i] = rand()%*range;
}


void get_info(int *rozmiar, int *range)
{
    cout << "Podaj ile liczb chcesz wygenerowac." << endl;
    cin >> *rozmiar;
    cout << endl;
    cout << "Podaj zakres generowanych liczb." << endl;
    cin >> *range;
    cout << endl;
}


void Merge(int pocz, int sr, int kon, int tab[], int pom[])
{
    int i, j, k;

    for (i=pocz; i<=kon; i++) pom[i] = tab[i];
    i=pocz; j=sr+1; k=pocz;

    while (i<=sr && j<=kon)
    {
        if(pom[i]<pom[j])
            tab[k++]=pom[i++];
        else
            tab[k++]=pom[j++];
    }
    while (i<=sr) tab[k++] = pom[i++];
}


void MergeSort(int lewy, int prawy, int tab[], int pom[])
{
    int sr;
    if(lewy < prawy)
    {
        sr = (lewy+prawy)/2;
        MergeSort(lewy, sr, tab, pom);
        MergeSort(sr+1, prawy, tab, pom);
        Merge(lewy, sr, prawy, tab, pom);
    }
}

int main ( void )
{
    srand( time ( NULL ));

    int ile;
    int range;
    get_info(&ile, &range);
    int tab[ile];
    int pom[ile];

    generowanie(tab, &ile, &range);
    cout << "Wygenerowane liczby:" << endl;
    printowanie(tab, &ile);

    MergeSort(0, ile-1, tab, pom);
    cout << "Posortowane liczby:" << endl;
    printowanie(tab, &ile);

    return 0;
}
