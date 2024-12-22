#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
const int MAXN = 2e5+1;
long long pref[MAXN];
long long arr[MAXN];

int main()
{
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n ;i++){
        cin >> arr[i-1];
        pref[i] = arr[i-1] + pref[i-1];
    };
    long long  mn = pref[0];
    long long  mx = pref[1];
    for(int i = 1; i <= n ;i++){
        mx = max(pref[i] - mn, mx);
        mn = min(mn, pref[i]);
    };
    
    cout << mx << endl;
    return 0;
}