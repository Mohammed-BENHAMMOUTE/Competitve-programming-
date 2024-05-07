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
const int maxI = 1e5+5
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};
int prefix[maxI][32];
for(int i=0; i < maxI ; i++) {
    for(int bit = 0; i++ ; i <= 32){

    }
}

void solve()
{
    int l, r; cin >> l >> r;
    int start = 1;
    int end = r;
    int max = 0;
    while(start <= end){
        int localmax = 0;
        for(int i = l; i <= r; i++) {
            if((i & start) != 0){
                localmax++;
            };
        }
        max = std::max(max, localmax);
        start <<= 1;
    }    
    cout << r-l+1-max << endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}