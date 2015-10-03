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
    int liczba, x;

    for (int i=*ile-2; i>=0; i--)
    {
        x = i;
        liczba = tablica[i];
        while(liczba>tablica[x+1] && x<*ile-1)
        {
            tablica[x] = tablica[x+1];
            x++;
        }
        tablica[x] = liczba;
    }
}

void insertion_sort_binarny(int tablica[], int *ile)
{
    int liczba, x;
    int lewy, sr, prawy;
    for (int i=*ile-2; i>=0; i--)
    {
        liczba = tablica[i];
        lewy = i;
        prawy = *ile-1;

        while(true){
        sr = (lewy + prawy) / 2;
            if(sr==i && tablica[i]>tablica[i+1])
            {
                x=i+1;
                break;
            }
            else if(sr==*ile-1)
            {
                x = *ile-1;
                break;
            }

            if(liczba>=tablica[sr] && liczba<=tablica[sr+1])
            {
                x = sr;
                break;
            }
            else if(liczba < tablica[sr])
                prawy = sr;
            else if(liczba > tablica[sr])
                lewy = sr+1;
        }
        for(int z=i; z<x; z++)
            tablica[z] = tablica[z+1];
        tablica[x]=liczba;
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
    cout.flush();

    insertion_sort_binarny(tab, &ile);
//    insertion_sort_liniowy(tab, &ile);

    cout << endl << endl << "Sortowanie binarne:" << endl;
    printowanie(tab, &ile);
    return 0;
}