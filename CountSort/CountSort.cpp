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
}


void printowanie(int tab[], int range)
{
    for(int i=0; i<range; i++) cout << tab[i] << "  ";
}


void generowanie(int tab[])
{
    for(int i=0; i<ile; i++) tab[i] = rand()%range;
}


void countSort(int tab[], int result_tab[])
{
    //tworzenie arraya z wyzerowanym licznikiem
    int liczydlo[range+1];
    for(int i = 0; i < range+1; i++)
    {
        liczydlo[i] = 0;
    }
    //zliczanie ilosci wystapien danej liczby
    for(int i=0; i<ile; i++) liczydlo[tab[i]]++;

    //szukanie pierwszej liczby i nadanie jej indeksu 0 lub wiekszego, gdy tych samych liczb jest wiecej niż jedna
    //ustawianie indeksów na podstawie sumy liczb mniejszych i równych "i"
    bool first = false;
    for(int i=0; i<range+1; i++)
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
    for(int i=ile-1; i>=0; i--) result_tab[liczydlo[tab[i]]--] = tab[i];
}


int main( void )
{
    srand( time ( NULL ) );
    get_info();

    int tab[ile];
    int result_tab[ile];

    generowanie(tab);
    //
    cout << endl << "Wygenerowane liczby to: " << endl;
    printowanie(tab, ile);
    //
    countSort(tab, result_tab);
    //
    cout << endl << endl << "Posortowane liczby to: " << endl;
    printowanie(result_tab, ile);
    cout << endl << endl;

    return 0;
}
