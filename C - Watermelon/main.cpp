#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 0;

    cin >> a;

    if(a != 2 && a % 2==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
