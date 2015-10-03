#include <iostream>
#include <cmath>

using namespace std;
//int count = 0;

void sito_eratostenesa(bool tab[], int range)
{
    cout << "pierwiastek wynosi: " << sqrt(double(range)) << endl;
    for(int i=2; i<=sqrt(range); i++)
    {
        if(!tab[i]) {
//            count++;
            continue;
        }
        for(int x=i*i; x<range; x+=i)
        {
//            count++;
            tab[x] = false;
//            cout << x << endl;
        }
    }
}


int main() {
    int range;
    cout << "Podaj zasięg liczb do przesiania sitem ERATOSTENESA :) ";
    cin >> range;
    range++;
    bool array[range];
    fill_n(array, range, true); //from std namespace
//    for(int i=0; i<range; i++) array[i] = true;
    array[0] = false;
    array[1] = false;

    sito_eratostenesa(array, range);
    cout << "Liczby pierwsze w zakresie do " << range-1 << " włącznie to: " << endl;
    for(int i=0; i<range; i++)
    {
        if(array[i])
            cout << i << "  ";
    }
    cout << "zlozonosc: " << count;

    return 0;
}