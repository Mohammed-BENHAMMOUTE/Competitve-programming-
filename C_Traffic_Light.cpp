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
        std::cout.tie(0);
    }
     
    void solve()
    {
        int n; cin >> n;
        char c;cin >> c;
        string st; cin >> st;
        int count = 0;
        st = st + st;
        vector<int> green;
        for(int i =0; i<2*n; i++) {
            if(st[i] == 'g') {
                green.pb(i);
            };
        };
        for(int i = 0; i < n ; i++){
            if(st[i] == c) {
                auto it = lower_bound(green.begin(), green.end(), i);
                count = max(*it - i, count);
            };
        }
        std::cout << count << endl;
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