#include <bits/stdc++.h>
using namespace std;

class Knapsack
{
public:
    int solveKnapSack(vector<int> &profits, vector<int> &weights, int capacity)
    {
        // return knapSackBruteforce(profits, weights, capacity, 0);
        vector<vector<int>> memo(profits.size(), vector<int>(capacity + 1, -1));
        return knapSackMemo(profits, weights, capacity, 0, memo);
    }

    int solveKnapsackBottomUp(vector<int> &profits, vector<int> &weights, int capacity)
    { // O(n*capacity)
        int n = profits.size();

        if (capacity <= 0 || n == 0 || weights.size() != n)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for (int c = 0; c <= capacity; c++)
        {
            if (weights[0] <= c)
            {
                dp[0][c] = profits[0];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int c = 1; c <= capacity; c++)
            {
                int profitWithItem = 0;
                int profitWithOutItem = 0;

                if (weights[i] <= c)
                {
                    profitWithItem = profits[i] + dp[i - 1][c - weights[i]];
                }
                profitWithOutItem = dp[i - 1][c];

                dp[i][c] = max(profitWithItem, profitWithOutItem);
            }
        }
        printSelectedItems(dp, weights, profits, capacity);
        return dp[n - 1][capacity];
    }

private:
    int solveKnapsackOptimal(const vector<int> &profits, const vector<int> &weights, int capacity) // Space O(capacity)
    {
        int n = profits.size();

        if (capacity <= 0 || n == 0 || weights.size() != n)
            return 0;

        vector<vector<int>> dp(2, vector<int>(capacity + 1, 0));

        // If we have only one weight, we will take it if it is not more than the capacity
        for (int c = 0; c <= capacity; c++)
        {
            if (weights[0] <= c)
            {
                dp[0][c] = dp[1][c] = profits[0];
            }
        }

        // Process all sub-arrays for all the capacities
        for (int i = 1; i < n; i++)
        {
            for (int c = 1; c <= capacity; c++)
            {
                int profitWithI = 0;
                int profitMinusI = dp[(i - 1) % 2][c];

                // Include the item if it's not more than the capacity
                if (weights[i] <= c)
                {
                    profitWithI = profits[i] + dp[(i - 1) % 2][c - weights[i]];
                }

                // Take the maximum
                dp[i % 2][c] = max(profitWithI, profitMinusI);
            }
        }

        // Function to print the set of items included in the knapsack
        string selectedWeights = "";
        int totalProfit = dp[(n - 1) % 2][capacity];
        int remainingCapacity = capacity;

        for (int i = n - 1; i > 0; i--)
        {
            if (totalProfit != dp[(i - 1) % 2][remainingCapacity])
            {
                selectedWeights = "{" + to_string(weights[i]) + "lbs @ $" + to_string(profits[i]) + "}" + selectedWeights;
                remainingCapacity -= weights[i];
                totalProfit -= profits[i];
            }
        }

        if (totalProfit != 0)
        {
            selectedWeights = to_string(weights[0]) + " " + selectedWeights;
        }

        cout << "Selected weights: " << selectedWeights << " with Total knapsack profit of ---> $ " << dp[(n - 1) % 2][capacity] << endl;

        // Maximum profit will be at the bottom-right corner
        return dp[(n - 1) % 2][capacity];
    }

    void printSelectedItems(const vector<vector<int>> &dp, const vector<int> &weights, const vector<int> &profits, int capacity)
    {
        int totalProfit = dp[weights.size() - 1][capacity];
        int remainingCapacity = capacity;
        string selectedWeights = "";

        for (int i = weights.size() - 1; i > 0; i--)
        {
            if (totalProfit != dp[i - 1][remainingCapacity])
            {
                selectedWeights = "{" + to_string(weights[i]) + " lbs @ $" + to_string(profits[i]) + "} " + selectedWeights;
                remainingCapacity -= weights[i];
                totalProfit -= profits[i];
            }
        }

        // If the first item is included, add it to the selected items
        if (totalProfit != 0)
        {
            selectedWeights = "{" + to_string(weights[0]) + " lbs @ $" + to_string(profits[0]) + "} " + selectedWeights;
        }

        cout << "Selected weights: " << selectedWeights << " with Total knapsack profit of ---> $" << dp[weights.size() - 1][capacity] << endl;
    }

    int KnapSackSpaceOptimization(vector<int> &profits, vector<int> &weights, int capacity)
    {
        int n = profits.size();

        if (capacity <= 0 || n == 0 || weights.size() != n)
            return 0;
        vector<int> dp(capacity + 1, 0);
        for (int c = 0; c <= capacity; c++)
        {
            if (weights[0] <= c)
            {
                dp[c] = profits[0];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int c = capacity; c >= 0; c--)
            {
                int profitWithI = 0;
                if (weights[i] <= c)
                {
                    profitWithI = profits[i] + dp[c - weights[i]];
                }
            }
        }
        return dp[capacity];
    }

    int knapSackBruteforce(vector<int> &profits, vector<int> &weights, int capacity, int currIndex)
    { // O(2^n) where n is the size of the weights or profits
        if (capacity <= 0 || currIndex >= profits.size())
        {
            return 0;
        }

        int profit1 = 0;
        if (weights[currIndex] <= capacity)
        {
            profit1 = profits[currIndex] + knapSackBruteforce(profits, weights, capacity - weights[currIndex], currIndex + 1);
        }

        int profit2 = knapSackBruteforce(profits, weights, capacity, currIndex + 1);
        return max(profit1, profit2);
    }

    int knapSackMemo(vector<int> &profits, vector<int> &weights, int capacity, int currIndex, vector<vector<int>> &memo)
    { // O(n * capacity)
        if (capacity <= 0 || currIndex >= profits.size())
        {
            return 0;
        }

        if (memo[currIndex][capacity] != -1)
        {
            return memo[currIndex][capacity];
        }

        int profit1 = 0;
        if (weights[currIndex] <= capacity)
        {
            profit1 = profits[currIndex] + knapSackMemo(profits, weights, capacity - weights[currIndex], currIndex + 1, memo);
        }

        int profit2 = knapSackMemo(profits, weights, capacity, currIndex + 1, memo);
        memo[currIndex][capacity] = max(profit1, profit2);
        return memo[currIndex][capacity];
    }
};

int main()
{
    Knapsack ks;
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};

    cout << "Total knapsack profit: ---> $" << ks.solveKnapSack(profits, weights, 7) << endl;
    cout << "Total knapsack profit: ---> $" << ks.solveKnapSack(profits, weights, 6) << endl;

    return 0;
}
