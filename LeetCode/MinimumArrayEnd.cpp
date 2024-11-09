#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Approach 1: Consecutive ORing
class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        while(--n) {
            res = (res + 1) | x;
        }

        return res;
    }
};


// Approach 2: Bit Manipulation and Binary Construction
class Solution {
public:
    long long minEnd(int n, int x) {
        ll result = 0, bit;
        // Reducing n by 1 to exclude x from the iteration
        --n;

        // Step 1: Initialize vectors to hold the binary representation of x and
        // n-1
        vector<int> binaryX(64, 0);  // Binary representation of x
        vector<int> binaryN(64, 0);  // Binary representation of n-1

        ll longX = x;  // Convert x to long long for 64-bit manipulation
        ll longN = n;  // Convert n-1 to long long for 64-bit manipulation

        // Step 2: Build binary representations of x and n-1
        for (int i = 0; i < 64; ++i) {
            bit = (longX >> i) & 1;  // Extract i-th bit of x
            binaryX[i] = bit;

            bit = (longN >> i) & 1;  // Extract i-th bit of n-1
            binaryN[i] = bit;
        }

        int posX = 0, posN = 0;

        // Step 3: Combine binary representation of x and n-1
        while (posX < 63) {
            // Traverse binaryX until we find a 0 bit
            while (binaryX[posX] != 0 && posX < 63) {
                ++posX;
            }
            // Copy bits from binaryN (n-1) into binaryX (x) starting from the
            // first 0
            binaryX[posX] = binaryN[posN];
            ++posX;
            ++posN;
        }

        // Step 4: Rebuild the final result from the combined binary
        // representation
        for (int i = 0; i < 64; ++i) {
            if (binaryX[i] == 1) {
                // convert binary bit to decimal value
                result += pow(2, i);
            }
        }

        return result;
    }
};

// Approach 3: Bitmasking with Logical Operations
class Solution {
public:
    long long minEnd(int n, int x) {
        ll result = x, mask;
        --n;

        for(mask = 1; n > 0; mask <<=1) {
            if((mask & x) == 0) {
                result |= (n&1) * mask;
                n >>=1;
            }
        }

        return result;
    }
};