#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

int main()
{
    fastio;
    int n, a ,b; cin >> n >> a >>b;
    vector<pair<int,int>> va;
    for(int i =0 ; i < n; i++){
        int x, y; cin >> x >> y;
        va.push_back({x, y});
    };
    vector<bool> visited(n, false);
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            ++ans;
            visited[i] = true;
            for(int j = i + 1; j < n ; j++) {
                // Check if points are on the same line using cross product
                // (x1-x0)(y2-y0) = (y1-y0)(x2-x0)
                if((va[i].first - a) * (va[j].second - b) == 
                   (va[i].second - b) * (va[j].first - a)) {
                    visited[j] = true;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}