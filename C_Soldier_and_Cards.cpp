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
    int k1; cin >> k1;
    queue<int> q1;
    for(int i = 0; i < k1; i++) {
        int x; cin >> x;
        q1.push(x);
    }
    int k2; cin >> k2;
    queue<int> q2;
    for(int i = 0; i < k2; i++) {
        int x; cin >> x;
        q2.push(x);
    }
    int ans = 0;
    while(!q1.empty() && !q2.empty()) {
        int x = q1.front();
        int y = q2.front();
        q1.pop();
        q2.pop();
        if(x > y) {
            q1.push(y);
            q1.push(x);
        }else{
            q2.push(x);
            q2.push(y);
        }
        ans++;
        if(ans > 1000) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << " ";
    if(q1.empty()) {
        cout << 2 << endl;
    }else{
        cout << 1 << endl;
    }
}

int main()
{
    fastio();
    solve();

    return 0;
}