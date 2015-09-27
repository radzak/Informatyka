#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define ROZMIAR 10
using namespace std;

int tab[ROZMIAR];

void printowanie(int tablica[])
{
    for(int i = 0; i < ROZMIAR; i++) cout << tablica[i] << "  ";
    cout << endl;
}

void Generowanie(int tablica[])
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        tablica[i] = rand()%100;
    }
}

void Merge(int i, int j, int k, int tab[])
{
    int pom[ROZMIAR];

    for (int index = 0; index < k; index++)
    {
        pom[index] = tab[index];
    }
    //printowanie(tab);

    int n = i;
    while(i<=j && j<=k)
    {
        if(pom[i] < pom[j]){
            tab[n++] = pom[i++];
        }
        else
            tab[n++] = pom[j++];
    }
    while(i<=j) tab[n++] = pom[i++];
    while(i<=k) tab[n++] = pom[j++];

    //printowanie(tab);
    //printowanie(pom);
}

void MergeSort(int lewy, int prawy, int tab[])
{
    int sr;
    while(lewy < prawy)
    {
        sr = (lewy+prawy)/2;
        MergeSort(lewy, sr, tab);
        MergeSort(sr+1, prawy, tab);
        Merge(lewy, sr, prawy, tab);
    }

}




int main ( void )
{
    srand( time ( NULL ));

    Generowanie(tab);
    printowanie(tab);
    Merge(0, 5, ROZMIAR, tab);
    printowanie(tab);


    return 0;
}
