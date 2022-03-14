
#include <iostream>

using namespace std;

int verifica_vetor(int vet[], int q, int c){

   for(int i = 0; i < 2000; ++i){
       if(vet[c-i] >= q)
         return true;
   }
   return false;
}

int main(int argc, char const *argv[]){

    int count = 1;
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
                   cout << dividendo << endl;
                   pre_proc[count] = dividendo;
                   break;
                }
                else if(quociente == 1){
                    count++;
                    pre_proc[count] = quociente;
                    cout << i << endl;
                    break;
                }
                dividendo = quociente;   
            }
            else if(dividendo%3 == 0){
                     quociente = dividendo/3;
                     if(verifica_vetor(pre_proc, quociente, count)){
                        count++;
                        cout << dividendo << endl;
                        pre_proc[count] = dividendo;
                        break;
                     }
                     else if(quociente == 1){
                        count++;
                        pre_proc[count] = quociente;
                        cout << i << endl;
                        break;
                     }
                     dividendo = quociente;
            }
            else if(dividendo%5 == 0){
                     quociente = dividendo/5;
                     if(verifica_vetor(pre_proc, quociente, count)){
                        count++;
                        cout << dividendo << endl;
                        pre_proc[count] = dividendo;
                        break;
                     }
                     else if(quociente == 1){
                        count++;
                        pre_proc[count] = quociente;
                        cout << i << endl;
                        break;
                     }
                     dividendo = quociente;
            }
            else
               break;
        }
    }
    //cout << i-1 << endl;

    return 0;
}

/*
// 859963 392
# include<iostream>
using namespace std;

int min(int x, int y, int z) {            //find smallest among three numbers
   if(x < y) {
      if(x < z)
         return x;
      else
         return z;
   }else {
      if(y < z)
         return y;
      else
         return z;
   }
}

int getUglyNum(int n) {
   int uglyNum[n];          // To store ugly numbers
   int i2 = 0, i3 = 0, i5 = 0;

   //find next multiple as 1*2, 1*3, 1*5

   int next2mul = 2;
   int next3mul = 3;
   int next5mul = 5;
   int next = 1;              //initially the ugly number is 1

   uglyNum[0] = 1;

   for (int i=1; i<n; i++) {
      next = min(next2mul, next3mul, next5mul);       //find next ugly number
      uglyNum[i] = next;

        cout << next << endl;

      if (next == next2mul) {
         i2++;             //increase iterator of ugly numbers whose factor is 2
         next2mul = uglyNum[i2]*2;
      }

      if (next == next3mul) {
         i3++;             //increase iterator of ugly numbers whose factor is 3
         next3mul = uglyNum[i3]*3;
      }

      if (next == next5mul) {
         i5++;              //increase iterator of ugly numbers whose factor is 5
         next5mul = uglyNum[i5]*5;
      }
   }
   return next;        //the nth ugly number
}

int main() {
   int n;
   cout << "Enter term: "; cin >> n;
   cout << n << "th Ugly number is: " << getUglyNum(n) << endl;
}

*/