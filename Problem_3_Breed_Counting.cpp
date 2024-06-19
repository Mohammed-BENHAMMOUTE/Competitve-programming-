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
    int n,q;cin >> n >> q;
    vector<vector<int>> a(n+1, vector<int>(3,0));
    for(int i =1; i <= n ;i++) {
        int x ; cin >> x; 
        a[i] = a[i-1];
        a[i][x-1]++;
    };
    for(int i =0 ; i < q ; i++) {
        int x,y; cin >> x >> y;
        cout << a[y][0] - a[x-1][0] <<" ";
        cout << a[y][1] - a[x-1][1] <<" ";
        cout << a[y][2] - a[x-1][2] << endl;
    };
    
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}