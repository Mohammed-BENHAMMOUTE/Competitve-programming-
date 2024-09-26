#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    
    int n;
    cin >> n;
    
    vector<int> freq(100001, 0);
    int max_side = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freq[num]++;
        max_side = max(max_side, num);
    }
    
    long long count = 0;
    int pairs = 0;
    long long sum_pairs = 0;
    
    for (int i = 1; i <= max_side; i++) {
        if (freq[i] >= 4) {
            count++;  
        }
        if (freq[i] >= 2) {
            count += pairs;  
            sum_pairs += pairs;
            pairs++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}