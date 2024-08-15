#include<bits/stdc++.h>
using namespace std;

/** 
* Forward declaration of guess API.
* @param  num   your guess
* @return 	     -1 if num is higher than the picked number
*			      1 if num is lower than the picked number
*               otherwise return 0
* int guess(int num);
*/
class Solution {
public:
  long guessNumber(int n) {
    long low = 0;
    long high = n;

    while(low <= high) {
      long mid = (high + low) / 2;
      long res = guess(mid);
      if(res == 0) 
        return mid;
      else if(res < 0) 
        high = mid - 1;
      else 
        low = mid + 1;
    }
    
  }
};
