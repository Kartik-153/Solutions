#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int bitCnt = 0;
        int num = n;

        while (num > 0) {
            bitCnt++;
            num = num >> 1;
        }

        // for a number which is a complete power of '2' i.e., it can be written
        // as pow(2, n), if we
        // subtract '1' from such a number, we get a number which has 'n' least
        // significant bits set to '1'. For example, '4' which is a complete
        // power of '2', and '3' (which is one less than 4) has a binary
        // representation of '11' i.e., it has '2' least significant bits set to
        // '1'

        int all_bits_set = pow(2, bitCnt) - 1;
        if (n == 0)
            return 1;
        return n ^ all_bits_set;
    }
};