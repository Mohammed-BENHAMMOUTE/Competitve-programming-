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
    int n;cin >>n;
    string s;cin >>s;
    int AliceBob = 1;
    while(s.size()>0){
        bool flag = false;
        for(int i= 0; i<s.size(); i++) {
            if(s[i] == 'U' ){
                flag = true;
                if(s.size() >2){
                    s[(i-1+s.size())%s.size()] = (s[(i-1+s.size())%s.size()] == 'U'?'D':'U');
                    s[(i+1)%s.size()] = (s[(i+1)%s.size()] == 'U'?'D':'U');
                    s.erase(s.begin()+i);
                    // cout << s <<endl;
                }else if(s.size() == 2){
                    s.erase(s.begin()+i);
                }else{
                    // cout<< "here"<<endl;
                    cout<<(AliceBob%2 == 1? "YES" : "NO")<<endl;
                    return;
                };
                break;
            }
        }
        if(!flag){
            cout<<(AliceBob%2 == 1? "NO" : "YES")<<endl;
            return;
        }
        AliceBob++;
    }
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