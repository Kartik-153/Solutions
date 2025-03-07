#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int upperLimit = right;
        vector<int> sieveArray = sieve(upperLimit);
        vector<int> primeNumber;
        for(int num = left; num <= right; num++) {
            if(sieveArray[num] == 1) {
                primeNumber.push_back(num);
            }
        }
        if(primeNumber.size() < 2) {
            return {-1, -1};
        }
        int minDiff = INT_MAX;
        vector<int> closestPair(2 , -1);
        
        for(int idx = 1; idx < primeNumber.size(); idx++) {
            int diff = primeNumber[idx] - primeNumber[idx-1];
            if(diff < minDiff) {
                minDiff = diff;
                closestPair[0] = primeNumber[idx-1];
                closestPair[1] = primeNumber[idx];
            }
        }
        return closestPair;
    }
private:
    vector<int> sieve(int upperLimit) {
        vector<int> sieve(upperLimit + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;

        for(int num = 2; num*num <= upperLimit; num++) {
            if(sieve[num] == 1) {
                for(int p = num*num; p <= upperLimit; p+=num) {
                    sieve[p] = 0;
                }
            }
        }
        return sieve;
    }
};

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primeNumbers;

        for(int i = left; i <= right; i++) {
            if(i % 2 == 0 and i > 2) continue;
            if(isPrime(i)) {
                if(!primeNumbers.empty() && i <= primeNumbers.back() + 2) {
                    return {primeNumbers.back(), i};
                }
                primeNumbers.push_back(i);
            }
        }

        if(primeNumbers.size() < 2) return {-1, -1};

        vector<int> closestPair = {-1, -1};
        int minDiff = 1e6;

        for(int idx = 1; idx < primeNumbers.size(); idx++) {
            int diff = primeNumbers[idx] - primeNumbers[idx - 1];
            if(diff < minDiff) {
                minDiff = diff;
                closestPair = {primeNumbers[idx - 1], primeNumbers[idx]};
            }
        }
        return closestPair;
    }

private:
    bool isPrime(int number) {
        if(number == 1) return false;
        for(int i = 2; i <= sqrt(number); i++) {
            if(number % i == 0) return false;
        }
        return true;
    }
};

vector<bool> sieve(int upper_limit) {
    vector<bool> is_prime(upper_limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int num = 2; num * num <= upper_limit; num++) {
        if (is_prime[num]) {
            for (int multiple = num * num; multiple <= upper_limit; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    const int limit = 1000000;
    vector<bool> primes = sieve(limit);

    vector<int> twin_primes;
    // Collect all twin primes
    for (int num = 2; num <= limit - 2; num++) {
        if (primes[num] && primes[num + 2]) {
            twin_primes.push_back(num);
        }
    }
    int max_distance = 0;
    pair<int, int> max_twin_pair = {-1, -1};
    // Find the largest gap between consecutive twin primes
    for (int i = 1; i < twin_primes.size(); i++) {
        int distance = twin_primes[i] - twin_primes[i - 1];
        if (distance > max_distance) {
            max_distance = distance;
            max_twin_pair = {twin_primes[i - 1], twin_primes[i]};
        }
    }
    cout << "Twin primes with maximum distance: (" << max_twin_pair.first 
         << ", " << max_twin_pair.second << ")" << endl;
    cout << "Maximum twin prime distance: " << max_distance << endl;
    return 0;
}