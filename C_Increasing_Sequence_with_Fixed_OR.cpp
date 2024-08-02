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
void solve() {
    ll n;
    cin >> n;
    
    vector<ll> ans;
    int count = 0;
    ll temp = n;

    // Count the number of set bits
    while (temp != 0) {
        temp = temp & (temp - 1);
        count++;
    }
    if(count ==1){
        cout<<1<<endl;
        cout << n << endl;
        return;
    }

    cout << count + 1 << endl; 

    ans.push_back(n);  
    // set bits to from 0 to 
    for (int i = 0; i < 63 && ans.size() < count + 1; i++) {
        if (n & (1LL << i)) {
            ll next = n & ~(1LL << i);  
            ans.push_back(next);
        }
    }
    sort(ans.begin(), ans.end());
    for (ll num : ans) {
        cout << num << " ";
    }
    cout << endl;
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