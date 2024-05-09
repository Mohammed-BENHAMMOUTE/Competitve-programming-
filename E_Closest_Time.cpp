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
bool match(int hour ,int minut,string given){
    int a[]={hour/10,hour%10,minut/10,minut%10};
    char c[]={given[0],given[1],given[3],given[4]};
    for(int i=0;i<4;i++){
        if(c[i]!='?' && c[i]-'0'!=a[i]){
            return false;
        }

    }
    return true;
}
int deparse(string ref){
    return 60*((ref[0]-'0')*10+(ref[1]-'0'))+(ref[3]-'0')*10+(ref[4]-'0');

}

void solve()
{
    string given ,ref;
    cin >> given>>ref;
    int hour=0,minut=0,ans=20000;
    for(int i=0;i<24;i++){
        for(int j=0;j<60;j++){
            if(match(i,j,given)){
                int tmp=60*i+j-deparse(ref);
                if(tmp>0){
                    if(tmp<ans || (deparse(ref)+(24-i)*60-j)<ans){
                        ans=min(tmp,deparse(ref)+(24-i)*60-j);
                        hour=i;
                        minut=j;
                    }

                }
                else{
                    if(-tmp<ans || ((24-(10*(ref[0]-'0')+(ref[1]-'0')))*60-(10*(ref[3]-'0')+(ref[4]-'0'))+60*i+j)<ans){
                        ans=min(-tmp,(24-(10*(ref[0]-'0')+(ref[1]-'0')))*60-(10*(ref[3]-'0')+(ref[4]-'0'))+60*i+j);
                        hour=i;
                        minut=j;

                }


            }
        
        }
    }
    
}
cout<<hour/10<<hour%10<<":"<<minut/10<<minut%10<<endl;
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