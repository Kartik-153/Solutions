#include <bits/stdc++.h>
using namespace std;

class Solution { // BFS
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<int>> cellHeights(rows, vector<int>(cols, -1));
        queue<pair<int, int>> cellQueue;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (isWater[x][y]) {
                    cellQueue.push({x, y});
                    cellHeights[x][y] = 0;
                }
            }
        }

        int heightOfNextLayer = 1;
        while (!cellQueue.empty()) {
            int layerSize = cellQueue.size();

            for (int i = 0; i < layerSize; i++) {
                pair<int, int> currCell = cellQueue.front();
                cellQueue.pop();

                for (int d = 0; d < 4; d++) {
                    pair<int, int> neighborCell = {currCell.first + dx[d],
                                                   currCell.second + dy[d]};
                    if (isValidCell(neighborCell, rows, cols) &&
                        cellHeights[neighborCell.first][neighborCell.second] ==
                            -1) {
                        cellHeights[neighborCell.first][neighborCell.second] =
                            heightOfNextLayer;
                        cellQueue.push(neighborCell);
                    }
                }
            }
            heightOfNextLayer++;
        }
        return cellHeights;
    }

private:
    bool isValidCell(pair<int, int> cell, int rows, int cols) {
        return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
               cell.second < cols;
    }
};

class Solution { // Dynamic Programming
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int columns = isWater[0].size();
        const int INF = rows * columns;
        vector<vector<int>> cellHeights(rows, vector<int>(columns, INF));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (isWater[row][col]) {
                    cellHeights[row][col] = 0;
                }
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                int minNeighborDistance = INF;
                int neighborRow = row - 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                neighborRow = row;
                neighborCol = col - 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = columns - 1; col >= 0; col--) {
                int minNeighborDistance = INF;
                int neighborRow = row + 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                neighborRow = row;
                neighborCol = col + 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }
        return cellHeights;
    }

private:
    bool isValidCell(int row, int col, int rows, int columns) {
        return row >= 0 && col >= 0 && row < rows && col < columns;
    }
};
