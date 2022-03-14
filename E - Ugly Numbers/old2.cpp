

#include <iostream>

using namespace std;

int verifica_vetor(int vet[], int q, int c){

   for(int i = 0; i < 2000; ++i){
      if(vet[c-i] == q)
         return true;
      else if(vet[c-i] < q)
         return false;
   }
   return false;
}

int main(int argc, char const *argv[]){

    int count = 0;
    int quociente = 0, dividendo = 0, divisor = 2;
    int i;
    int pre_proc[2000] = {1};

    for(i = 2; count < 1500 ; ++i){

        dividendo = i;    
        while(true){
            if(dividendo%2 == 0){
                quociente = dividendo/2;
                if(verifica_vetor(pre_proc, quociente, count)){
                   count++;
                   //cout << dividendo << endl;
                   pre_proc[count] = dividendo;
                   break;
                }
                else if(quociente == 1){
                    count++;
                    pre_proc[count] = quociente;
                    //cout << i << endl;
                    break;
                }
                else
                  dividendo = quociente;   
            }
            else if(dividendo%3 == 0){
                     quociente = dividendo/3;
                     if(verifica_vetor(pre_proc, quociente, count)){
                        count++;
                        //cout << dividendo << endl;
                        pre_proc[count] = dividendo;
                        break;
                     }
                     else if(quociente == 1){
                        count++;
                        pre_proc[count] = quociente;
                        //cout << i << endl;
                        break;
                     }
                     dividendo = quociente;
            }
            else if(dividendo%5 == 0){
                     quociente = dividendo/5;
                     if(verifica_vetor(pre_proc, quociente, count)){
                        count++;
                        //cout << dividendo << endl;
                        pre_proc[count] = dividendo;
                        break;
                     }
                     else if(quociente == 1){
                        count++;
                        pre_proc[count] = quociente;
                        //cout << i << endl;
                        break;
                     }
                     dividendo = quociente;
            }
            else
               break;
        }
    }
    cout << i-1 << endl;

    return 0;
}