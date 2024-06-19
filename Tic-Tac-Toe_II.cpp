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
};
vector<int> BFS(int a, string& s){
    
}

void solve()
{
   string s;
   cin>>s;
   while(s!= "end"){
         vector<int> a(9);
         for(int i = 0; i < 9; i++){
              a[i] = s[i] == 'X' ? 1 : (s[i] == 'O' ? -1 : 0);
         };
         vector<int> b = BFS(1,s);
         cout << b[0] << " " << b[1] << endl;
         cin >> s;
   } 
}

int main()
{
    fastio();
    solve();
    return 0;
}