#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int c = image.size();

        for(int row = 0; row < c; row++) {
            for(int col = 0; col < (c+1)/2; col++) {
                int temp = image[row][col] ^ 1;  
                image[row][col] = image[row][c - 1 - col] ^ 1;
                image[row][c - 1 - col] = temp;
            }
        }
        return image;
    }
};