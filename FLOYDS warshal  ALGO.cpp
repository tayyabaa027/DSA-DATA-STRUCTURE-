#include <iostream>
#include <iomanip>
using namespace std;

void display(int a[8][8], const char *[8]);
void warshalalgo(int a[8][8]);
void header(const char *[8]);

int main()
{
    const char *name[8] = {"fsd","isd","khi","lhr","mtn","pwr","rwp","swl"};

    int city[8][8] = {
        {1,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0},
        {1,1,0,1,0,0,0,0},
        {1,0,0,1,1,0,0,0},
        {0,1,0,0,1,1,0,0},
        {0,0,0,0,0,1,1,0},
        {1,0,0,0,0,0,0,1}
    };

    cout << "Initial Matrix:\n";
    header(name);
    display(city, name);

    warshalalgo(city);

    cout << "\n\nAfter Warshall Algorithm (Transitive Closure):\n";
    header(name);
    display(city, name);

    return 0;
}

void header(const char *ch[8])
{
    cout << "    ";
    for(int i = 0; i < 8; i++)
        cout << setw(4) << ch[i];
}

void warshalalgo(int arr[8][8])
{
    for(int k = 0; k < 8; k++)
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                arr[i][j] |= arr[i][k] & arr[k][j];
}

void display(int arr[8][8], const char *ch[8])
{
    for(int i = 0; i < 8; i++)
    {
        cout << endl << setw(4) << ch[i];
        for(int j = 0; j < 8; j++)
            cout << setw(4) << arr[i][j];
    }
    cout << endl;
}
