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

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> degree(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    int max_degree = *max_element(degree.begin(), degree.end());

    vector<int> max_degree_vertices;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == max_degree) {
            max_degree_vertices.push_back(i + 1);  // +1 because vertices are 1-indexed
        }
    }

    for (int i = 0; i < max_degree_vertices.size(); ++i) {
        cout << max_degree_vertices[i];
        if (i < max_degree_vertices.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}