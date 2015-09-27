#include <iostream>
#include <cstdlib>
#include <ctime>

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


int minimalna(int tab[], int range)
{
    int min = tab[0];
    for(int i=1; i<range; i++)
        if(tab[i] < min)
        {
            min = tab[i];
        }
    return min;
}


int maksymalna(int tab[], int range)
{
    int max = tab[0];
    for(int i=1; i<range; i++)
        if(tab[i] > max)
        {
            max = tab[i];
        }
    return max;
}


void bucket_sort(int tab[])
{
    int min = minimalna(tab, ile);
    int max = maksymalna(tab, ile);
    int ilosc = max - min +1;
    int liczydlo[ilosc];
    cout << endl << "max - min: " << ilosc << endl;
    for(int i=0; i<ilosc; i++)
        liczydlo[i] = 0;

    //zliczanie ilosci wystapien danej liczby
    for(int i=0; i<ile; i++) liczydlo[tab[i]-min]++;
    cout << "ilosc wystapien poszczegolnych liczb:" << endl;
    printowanie(liczydlo, ilosc);

    //szukanie pierwszej liczby i nadanie jej indeksu 0 lub wiekszego, gdy tych samych liczb jest wiecej niz jedna
    //ustawianie indeksow na podstawie sumy liczb mniejszych i rownych "i"
    bool first = false;
    for(int i=0; i<ilosc; i++)
    {
        if(liczydlo[i] != 0 && first == false)
        {
            liczydlo[i] -= 1;
            first = true;
            continue;
        }
        if(first == true)
            liczydlo[i] += liczydlo[i-1];
    }
    int result_tab[ile];
    for(int i=ile-1; i>=0; i--) result_tab[liczydlo[tab[i]-min]--] = tab[i];
    cout << endl << "posortowana tablica:" << endl;
    printowanie(result_tab, ile);
}




int main( void )
{
    srand(time(NULL));
    get_info();
    int tab[ile];
    generowanie(tab);
    cout << "tablica przed posortowaniem:" << endl;
    printowanie(tab, ile);
    cout << endl << "minimalna wartosc to: " << minimalna(tab, ile);
    cout << endl << "maksymalna wartosc to: " << maksymalna(tab, ile);
    bucket_sort(tab);
    return 0;
}
