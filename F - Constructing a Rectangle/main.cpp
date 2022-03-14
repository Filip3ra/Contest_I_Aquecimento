#include <iostream>

using namespace std;

void insertionSort(int arr[])
{
    int i, key, j;
    for (i = 1; i < 3; i++){
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[]){

    int t, a, b, c;
    int vet[3];
    cin >> t;

    for(int i = 0; i < t ; ++i){

        cin >> a >> b >> c;

        vet[0] = a;
        vet[1] = b;
        vet[2] = c;

        insertionSort(vet);

        
        if(a%2 != 0 && b%2 != 0 && c%2 != 0) // os três são ímpares
            cout << "NO" << endl;
        else if(a%2 == 0 && b%2 == 0 && c%2 == 0){ // os três são pares...
            if( a == b && b == c) // ...e são iguais
                cout << "YES" << endl;
            else if( ((a == b) && c!=a ) || ((a == c) && b!=a) || ((b == c) && a!=b)) // ...mas um é diferente
                cout << "YES" << endl;
            else{   // ...mas são diferentes entre si
                if(vet[2] - vet[0] == vet[1]) // e o maior menos o menor der o do meio
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        else if((a%2 == 0 && b%2 != 0 && c%2 != 0) || 
                (a%2 != 0 && b%2 == 0 && c%2 != 0) || 
                (a%2 != 0 && b%2 != 0 && c%2 == 0)){    // se tenho dois ímpares e um par...
            if(a!=b && a!=c && b!=c)    // ...e os três são diferentes
                if((vet[0] + vet[1]) == vet[2]) // ...então a soma dos dois menores tem que dar o maior 
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            else if(a==b || a==c || b==c)
                cout << "YES" << endl;
        }
        else // dois pares e um ímpar
            cout << "NO" << endl;
        
    }

    return 0;
}