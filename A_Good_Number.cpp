#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        set<ll> a;
        for(char x : s){
            a.insert((ll)(x-'0'));
        };
        int count =0;
        if(a.size() >= k)
        {
            for(auto x : a)
            {
                if(x <=k)count++;
            };
        };
        if(count > k) ans++;
    };

    cout << ans << endl;
}

int main() {
    // Assuming GOGOGO and BYEBYE are placeholders, replace them with actual code if necessary
    solve();
    return 0;
}