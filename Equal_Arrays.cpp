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
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	ll sum1 ,sum2;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum1 += a[i];
	};
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		sum2 += b[i];
	};
	if(sum1 != sum2) {
		cout << -1 << endl;
		return;
	};
	
	
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