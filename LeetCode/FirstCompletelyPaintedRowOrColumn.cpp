#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size(), numCols = mat[0].size();
        unordered_map<int, pair<int, int>> numToPos;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos[value] = {row, col};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            pair<int, int> tmp = numToPos[num];
            int row = tmp.first;
            int col = tmp.second;
            mat[row][col] = -mat[row][col];
            if (checkRow(row, mat) || checkColumn(col, mat)) {
                return i;
            }
        }
        return -1;
    }

private:
    bool checkRow(int row, vector<vector<int>>& mat) {
        for (int col = 0; col < mat[0].size(); col++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }

    bool checkColumn(int col, vector<vector<int>>& mat) {
        for (int row = 0; row < mat.size(); row++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size(), numCols = mat[0].size();
        vector<int> rowCount(numRows), colCount(numCols);
        unordered_map<int, pair<int, int>> numToPos;

        for(int row = 0; row < numRows; row++) {
            for(int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos[value] = {row,col};
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            pair<int, int> tmp = numToPos[num];
            int row = tmp.first;
            int col = tmp.second;

            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row] == numRows || colCount[col] == numRows) return i;
        }
        return -1;
    }
};
