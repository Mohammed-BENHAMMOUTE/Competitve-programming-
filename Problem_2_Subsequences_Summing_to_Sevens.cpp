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
    vector<int> vi(7, -1);
    vi[0] = 0;
    int ans = 0;
    int c = 0;
    for(int i = 1; i <= n ; i++){
        int a; cin >> a;
        c = (c+a)%7;
        if(vi[c]!= -1) {
            ans = max(ans, i - vi[c]);
        }else{
            vi[c] = i;
        };
    };
    cout << ans << endl;
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}