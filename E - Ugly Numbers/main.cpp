

#include<iostream>

using namespace std;



int menor(int a, int b, int c){
   if(a < b){
      if(a < c)
         return a;
      else
         return c;
   }
   else{
      if(b < c)
         return b;
      else
         return c;
   }
}

int main(int argc, char const *argv[]){

   int vet[1600] = {1}; // 1 é o primeiro num feio
   int i_2 = 0, i_3 = 0, i_5 = 0; // iteradores
   int mult_2 = 2, mult_3 = 3, mult_5 = 5; // multiplos permitidos 
   int num;

   for(int i = 1; i <= 1500; ++i){

      num = menor(mult_2, mult_3, mult_5); // encontra o menor valor
      vet[i] = num;

      if(num == mult_2){
         i_2++;
         mult_2 = vet[i_2]*2; // calcula o próximo multiplo
      }
      if(num == mult_3){
         i_3++;
         mult_3 = vet[i_3]*3;
      }
      if(num == mult_5){
         i_5++;
         mult_5 = vet[i_5]*5;
      }
   }
   cout << "The 1500'th ugly number is " << num << "." << endl;
   return 0;
}

