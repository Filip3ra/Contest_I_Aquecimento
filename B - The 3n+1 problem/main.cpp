#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    int n = 0, i, j;
    int count = 1;
    

    while(cin >> i >> j){ // que pegadinha sacana essa da leitura kkkkk
        int max_lenght = 0;
        int aux = i;

        if(i <= j){
            for(; i<=j; ++i){   // percorre o intervalo de i até j
                n = i;
                while(n != 1){

                    if(n%2 != 0){    // ímpar
                        n = 3*n + 1;
                        count++;
                    }
                    else{           // par
                        n = n/2;
                        count++;
                    }
                }
                
                if(count > max_lenght)
                    max_lenght = count;   
                
                count = 1;      
            }
            cout << aux << " " << j << " " << max_lenght << endl;
        }
        else{
            for(; i>=j; --i){   // percorre o intervalo de i até j
                n = i;
                while(n != 1){

                    if(n%2 != 0){    // ímpar
                        n = 3*n + 1;
                        count++;
                    }
                    else{           // par
                        n = n/2;
                        count++;
                    }
                }
                
                if(count > max_lenght)
                    max_lenght = count;   
                
                count = 1;      
            }
            cout << aux << " " << j << " " << max_lenght << endl;

        }
    }
    return 0;
}