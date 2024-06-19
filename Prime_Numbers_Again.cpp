#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MAX_N 10000

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Sieve of Eratosthenes to generate primes up to n
vector<ll> sieve(int n) {
    vector<bool> is(n + 1, true);
    vector<ll> primes;
    is[0] = is[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is[j] = false;
            }
        }
    }
    return primes;
}

// Function to generate primatic numbers
vector<ll> generatePrimatic(int limit) {
    vector<ll> primes = sieve(limit);
    vector<ll> primatic;
    for (ll prime : primes) {
        primatic.push_back(prime);
        ll primePower = pow(prime, prime);
        if (primePower <= limit) {
            primatic.push_back(primePower);
        }
    }
    sort(primatic.begin(), primatic.end());
    primatic.erase(unique(primatic.begin(), primatic.end()), primatic.end());
    return primatic;
}

// Function to precompute minimum number of primatic numbers summing up to each value up to MAX_N
vector<int> precomputeMinPrimatic(const vector<ll>& primatic) {
    vector<int> dp(MAX_N + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= MAX_N; i++) {
        for (ll p : primatic) {
            if (p > i) break;
            if (dp[i - p] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - p] + 1);
            }
        }
    }
    return dp;
}

int main() {
    fastio();
    
    vector<ll> primatic = generatePrimatic(MAX_N);
    vector<int> minPrimatic = precomputeMinPrimatic(primatic);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << minPrimatic[n] << endl;
    }

    return 0;
}
