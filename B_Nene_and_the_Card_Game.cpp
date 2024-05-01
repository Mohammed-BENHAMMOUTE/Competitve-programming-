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

void solve()
{
    int n; cin >> n;
    vector<int> A(n);
    set<int> s;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        if(s.find(A[i]) != s.end()){
            s.erase(A[i]);
        }else{
            s.insert(A[i]);
        };
    };
    int ans =  (n - s.size())/2;
    cout << ans << endl;
    return;
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