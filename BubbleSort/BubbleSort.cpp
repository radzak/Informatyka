#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generowanie(int tab[], int *length, int *range)
{
    for(int i=0; i<*length; i++)
        tab[i] = rand()%*range;
}


void printowanie(int tab[], int *length)
{
    for(int i=0; i<*length; i++)
        cout << tab[i] << "  ";
    cout << endl;
}


void get_info(int *ile, int *range)
{
    cout << "Ile liczb chcesz wygenerowac?" << endl;
    cin >> *ile;
    cout << endl;
    cout << "Podaj zakres generowanych liczb" << endl;
    cin >> *range;
    cout << endl;
}

//cpp0x
//void bubble_sort(int tab[], int *ile, int *count)
//{
//    for(int i=0; i<*ile; i++)
//    {
//        for(int j=0; j<*ile-1; j++)
//        {
//            *count += 1;
//            if(tab[j]>tab[j+1])
//                swap(tab[j], tab[j+1]);
//        }
//    }
//    cout << "count wynosi: " << *count << " dla " << *ile << " liczb.";
//}

//autorstwa wlasnego
void bubble_sort(int tab[], int *ile, int *count)
{
    int x;
    for(int i=*ile-2; i>=0; i--)
    {
        x = i;
        while(tab[x]>=tab[x+1]) {
            swap(tab[x], tab[x + 1]);
            *count += 1;
            x++;
        }
    }
}

//wikipedia
//void bubble_sort(int tab[], int *ile, int *count)
//{
//    int n = *ile;
//    do
//    {
//        for(int i=0; i<n-1; i++)
//        {
//            *count += 1;
//            if (tab[i] > tab[i+1])
//                swap(tab[i], tab[i + 1]);
//        }
//        n -= 1;
//    }while(n>1);
//    cout << "count wynosi: " << *count << " dla " << *ile << " liczb.";
//}

int main( void )
{
    srand(time(NULL));
    int ile, range;
    int count = 0;

    get_info(&ile, &range);

    int tab[ile];

    generowanie(tab, &ile, &range);
    cout << "Wygenerowane liczby:" << endl;
    printowanie(tab, &ile);

    bubble_sort(tab, &ile, &count);
    cout << endl << "Posortowane liczby:" << endl;
    printowanie(tab, &ile);

}
