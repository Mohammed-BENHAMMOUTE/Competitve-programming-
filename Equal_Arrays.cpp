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
    int n,m; cin >> n >> m;
	if(n==m) {
		for(int i =0; i< n; i++) {
			if (a[i] != b[i]){
				cout << -1 <<endl;
				return;
			}
		};
	};
	vector<int> a(n) , b(n);
	for(int i =0 ; i<n; i++) {
		cin >> a[i];
	};
	for(int i = 0; i<m; i++) {
		cin >> b[i];
	};
	if(n > m) {
		int j = 0;
		while(j <m){
			int ans =0;
			for(int i = 0; i< m ; i++) {
				if(ans + a[i]<){
                    ans+= a[i];
                };
                if(ans+a[i] == b[j]){
                    j++;
                }
			}
		}		
	}

};
int main() {
	fastio();
	int t; cin >> t;

	for(int i= 1; i<=t; i++) {
		solve();
	};
	return 0;
}

