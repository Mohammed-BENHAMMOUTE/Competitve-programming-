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
    int a; cin >> a;
    vector<int> k(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> k[i];
    };
    a--;
    int maxcount = 0;
    int interval = min(a, n-a);
    int right = a-1;
    int left = a+1;
    if(k[a] == 1) {
        maxcount++;
    };
    while(right >=0 && left<=n-1)
    {
        maxcount+= (k[right]+ k[left] == 2? 2 : 0);
        right--;
        left++;
    };
    while(right >=0)
    {
        maxcount+= k[right];
        right--;
    };
    while(left <n)
    {
        maxcount+= k[left];
        left++;
    };
    cout << maxcount <<endl; 
};

int main()
{
    fastio();
    ll t;
    solve();

    return 0;
}