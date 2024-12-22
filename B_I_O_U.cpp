#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int dp[101];

int main()
{
    fastio;
    int n, m; cin >> n >> m;
    int x, y , z;

    for(int i = 0; i< m; i++){
        cin >> x >> y >> z;
        dp[x] += z;
        dp[y] -= z;
    }
    long long ans = 0;
    for(int i = 0; i < 101 ; i++){
        if(dp[i] >0){
            ans+=dp[i];
        }
    }
    cout << ans << endl;
    return 0;
}