#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0;

    cin >> i;
    if(i == 42)     // caso onde o primeiro valor é o 42
        return 0;
    else{
        for( ;i != 42; ){   // obs: estou supondo que não teremos entradas com mais de dois dígitos
            cout << i << endl;
            cin >> i;
        }
    }
    return 0;
}
