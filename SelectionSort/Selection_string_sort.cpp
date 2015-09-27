#include <iostream>

using namespace std;

void selection_string_sort(string tab[], int rozmiar)
{
    for(int i=0; i<rozmiar-1; i++)
    {
        int index = i;
        for(int j=i+1; j<rozmiar; j++)
        {
            if(tab[j]<=tab[index])
                index = j;
        }
        swap(tab[i], tab[index]);
    }
}

int main( void )
{
    int ile;

    cout << "Ile slow chcesz posortowac?" << endl;
    cin >> ile;
    string words[ile];
    cout << "Podawaj kolejno slowa, zatwierdzajac je Enterem" << endl;
    for(int i=0; i<ile; i++) cin >> words[i];
    selection_string_sort(words, ile);
    cout << "Posortowane slowa:" << endl;
    for(int i=0; i<ile; i++) cout << words[i] << "  ";
    return 0;
}