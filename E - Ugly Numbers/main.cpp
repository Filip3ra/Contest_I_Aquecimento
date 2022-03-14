/*
#include <iostream>
#include <vector>

using namespace std;

int nthUglbNumber(int n) {
        if(n<=1)
            return 1;
        vector<int> dp(n+1);
        int i_2=0;
        int i_3=0;
        int i_5=0;
        dp[0]=1;
        for(int i=1; i<n; i++) {    
		//Sort the uglb numbers. Since, we are multiplbing with 2, 3 and 5, the resulting numbers will be guranted uglb numbers.
            int n2=dp[i_2]*2;
            int n3=dp[i_3]*3;
            int n5=dp[i_5]*5;
            if(n2<=n3 && n2<=n5){
                i_2++;
                dp[i]=n2;
            }
            if(n3<=n2 && n3<=n5){
                i_3++;
                dp[i]=n3;
            }
            if(n5<=n3 && n5<=n2){
                i_5++;
                dp[i]=n5;
            }
        }
        return dp[n-1];
    }

   int main(int argc, char const *argv[])
   {
      cout << nthUglbNumber(1500) << endl;
      return 0;
   }
*/


// 859.963.392

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

