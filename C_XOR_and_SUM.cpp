#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll solve(ll n) {
    ll pairs = (n) / 2;  
    ll sum = pairs * 3;  
    
    if (n % 2 != 0) {
        sum += 2; 
    }
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    
    return 0;
}