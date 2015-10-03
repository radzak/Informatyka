#include <iostream>
#include <cmath>

using namespace std;

bool czy_podzielna(int liczba)
{
    if(liczba == 0 || liczba == 1)
        return false;
    for(int i=2; i<=sqrt(liczba); i++)
    {
        if(liczba%i == 0) {
            cout << "najmniejszy dzielnik liczby " << liczba << " wynosi: " << i << endl;
            return false;
        }
    }
    return true;
}

int main( void )
{
    int liczba;
    cout << "Podaj liczbę, której pierwszość chcesz sprawdzić: ";
    cin >> liczba;
    if(czy_podzielna(liczba))
        cout << "Liczba " << liczba << " jest pierwsza.";
    else
        cout << "Liczba " << liczba << " nie jest pierwsza.";
    return 0;
}
