#include <iostream>

using namespace std;

int main() {
    float zmienna;
    char character = 'a';
    bool boolean = -20;
    int char_int = character;

//    cout << U'a'<< "Podaj liczbę używając notacji wykładniczej (e+ lub e-): ";
//    cin >> zmienna;
//
//    cout << zmienna << endl;
//    cout << character << endl;
//    cout << char_int << endl;
//    cout << boolean << endl;

    string abra;
    cout << "Podaj słowo, którego ilość samogłosek chcesz sprawdzić: ";
    cin.sync();
    getline(cin, abra);
    int count = 0;
    for(int i=0; i<abra.length();i++)
    {
        if(abra[i]== 'a'||abra[i]=='ą'||abra[i]=='e'||abra[i]=='ę'||abra[i]=='o'||abra[i]=='ó'||abra[i]=='u'||abra[i]=='y'||abra[i]=='i')
            count++;
        if(abra[i]== 'A'||abra[i]=='Ą'||abra[i]=='E'||abra[i]=='Ę'||abra[i]=='O'||abra[i]=='Ó'||abra[i]=='U'||abra[i]=='Y'||abra[i]=='I')
            count++;
    }
    cout << "Ilosc samoglosek: " << count;

    cout.put('!') << endl;

    return 0;
}