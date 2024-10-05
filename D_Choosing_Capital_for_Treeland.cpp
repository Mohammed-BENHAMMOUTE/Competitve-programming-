#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;


#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 2e5 + 20;
int n;
vector <pii> g[N];

int dp[N];

void dfs1(int v, int par = -1) {
		for (pii p: g[v]) {
				int u = p.F, w = p.S;

				if (u == par) continue;

				dp[0] += w;
				dfs1(u, v);
		}
}

void dfs2(int v, int par = -1) {

		for (pii p: g[v]) {
				int u = p.F, w = p.S;

				if (u == par) continue;

				dp[u] = dp[v] + (!w ? 1 : -1);
				dfs2(u, v);
		}
}

int main() {
		ios::sync_with_stdio(false);
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
				int u, v;
				cin >> u >> v;
				u--, v--;

				g[u].pb({v, 0});
				g[v].pb({u, 1});
		}

		dfs1(0);
		dfs2(0);

		vector <int> vec;

		for (int i = 0; i < n; i++) {
				if (vec.empty() || dp[i] < dp[vec[0]]) {
						vec.clear();
						vec.pb(i);
				}
				else if (dp[i] == dp[vec[0]]) vec.pb(i);
		}

		cout << dp[vec[0]] << '\n';
		for (int x: vec) cout << x + 1 << ' ';
		cout << '\n';
}
