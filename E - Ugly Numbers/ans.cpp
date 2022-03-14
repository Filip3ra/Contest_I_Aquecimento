/*
#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n) {
        if(n<=1)
            return 1;
        vector<int> dp(n+1);
        int i2=0;
        int i3=0;
        int i5=0;
        dp[0]=1;
        for(int i=1; i<n; i++) {    
		//Sort the ugly numbers. Since, we are multiplying with 2, 3 and 5, the resulting numbers will be guranted ugly numbers.
            int n2=dp[i2]*2;
            int n3=dp[i3]*3;
            int n5=dp[i5]*5;
            if(n2<=n3 && n2<=n5){
                i2++;
                dp[i]=n2;
            }
            if(n3<=n2 && n3<=n5){
                i3++;
                dp[i]=n3;
            }
            if(n5<=n3 && n5<=n2){
                i5++;
                dp[i]=n5;
            }
        }
        return dp[n-1];
    }

   int main(int argc, char const *argv[])
   {
      cout << nthUglyNumber(1500) << endl;
      return 0;
   }
*/


// 859.963.392
#include<iostream>
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

