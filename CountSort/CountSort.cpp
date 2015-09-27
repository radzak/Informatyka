#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void get_info(int *ile, int *range)
{
    cout << "Ile liczb chcesz wygenerowac, a nastepnie posortowac?" << endl;
    cin >> *ile;
    cout << endl << "Podaj zasieg generowanych liczb" << endl;
    cin >> *range;
}

void printowanie(int tab[], int *range)
{
    for(int i=0; i<*range; i++) cout << tab[i] << "  ";
}

void generowanie(int tab[], int *ile, int *range)
{
    for(int i=0; i<*ile; i++) tab[i] = rand()%*range;
}

void countSort(int tab[], int result_tab[], int *ile, int *range)
{
    //tworzenie arraya z wyzerowanym licznikiem
    int liczydlo[*range] = { 0 };

    //zliczanie ilosci wystapien danej liczby
    for(int i=0; i<*ile; i++) liczydlo[tab[i]]++;

    //zliczanie ilosci wystapien liczb mniejszych i rownych od liczydlo[i]
    for(int i=0; i<*range; i++)
        liczydlo[i] += liczydlo[i-1];
    for(int i=*ile-1; i>=0; i--)
        result_tab[(liczydlo[tab[i]]-- - 1)] = tab[i];
}

int main( void )
{
    srand( time ( NULL ) );
    int ile;
    int range;

    get_info(&ile, &range);

    int tab[ile];
    int result_tab[ile];

    generowanie(tab, &ile, &range);
    cout << endl << "Wygenerowane liczby to: " << endl;
    printowanie(tab, &ile);

    countSort(tab, result_tab, &ile, &range);

    cout << endl << endl << "Posortowane liczby to: " << endl;
    printowanie(result_tab, &ile);
    return 0;
}
