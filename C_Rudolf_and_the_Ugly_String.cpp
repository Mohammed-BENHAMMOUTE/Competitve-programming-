 
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count =0;
    for(int i = 0; i<n-2 ; i++) {
        if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") 
        {
            count++;
            i +=2;
        };
    };
    cout << count << endl;
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