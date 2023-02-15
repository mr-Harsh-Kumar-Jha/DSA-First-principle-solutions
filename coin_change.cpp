// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Input: coins = [1,2,5], amount = 11
//  Output: 3
//  Explanation: 11 = 5 + 5 + 1

//==================================================================================

// this is a recursive based approch where time complexity of the solution is exponential ans space complexity is stack_Space+O(n*amt);

#include <bits/stdc++.h>
using namespace std;

 int countCoin(vector<int> &vec, int amt, int n){
      if (amt <= 0) return 0;

      if (n == 0 && amt%vec[n] == 0) return (amt/vec[n]);
      else if(n==0 && amt%vec[n]!=0) return INT_MAX-1;

      int TakeCount = INT_MAX-1;
      if (vec[n] <= amt){
         TakeCount = 1 + countCoin(vec, amt - vec[n], n);
      }
      int noTakeCount = countCoin(vec, amt, n - 1);
      return min(noTakeCount, TakeCount);
}

int main(){
    vector<int>vec{1,3,2,7};
    int amt = 103;
    cout<<countCoin(vec,amt,vec.size()-1)<<endl;
}