#include <bits/stdc++.h>
using namespace std;

class Solution { // Binary Search
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int minRank = ranks[0], maxRank = ranks[0];

        for (int rank : ranks) {
            minRank = min(minRank, rank);
            maxRank = max(maxRank, rank);
        }

        vector<int> freq(maxRank + 1);
        for (int rank : ranks) {
            minRank = min(minRank, rank);
            freq[rank]++;
        }

        long long low = 1, high = 1LL * minRank * cars * cars;

        while (low < high) {
            long long mid = (low + high) / 2;
            long long carsRepaired = 0;

            for (int rank = 1; rank <= maxRank; rank++) {
                carsRepaired +=
                    freq[rank] * (long long)sqrt(mid / (long long)rank);
            }

            if (carsRepaired >= cars) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

class Solution { // Optimised Binary Search
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1LL * cars * cars * ranks[0];
        while (low < high) {
            long long mid = low + (high - low) / 2, carsRepaired = 0;

            for (auto rank : ranks)
                carsRepaired += sqrt(1.0 * mid / rank);
            if (carsRepaired < cars)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

class Solution { // Heap
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int, int> count;
        for (int rank : ranks) {
            count[rank] += 1;
        }

        auto comp = [](vector<long>& a, vector<long>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<long>, vector<vector<long>>, decltype(comp)>
            minHeap(comp);

        for (auto it : count) {
            int rank = it.first;
            minHeap.push({rank, rank, 1, it.second});
        }
        long long time = 0;
        while (cars > 0) {
            vector<long> curr = minHeap.top();
            minHeap.pop();
            time = curr[0];
            int rank = curr[1];
            long n = curr[2];
            int mechCount = curr[3];

            cars -= mechCount;
            n += 1;
            minHeap.push({rank * n * n, rank, n, mechCount});
        }
        return time;
    }
};
