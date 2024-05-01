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
static int lastPowOfTwo(int n)
{
    int power = 1;
    while (power * 2 <= n)
    {
        power *= 2;
    }
    return power;
};

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};
int lowBit(int x){
    return x & -x;
};
void solve() {
    int sum, limit;
    cin >> sum >> limit;

    vector<int> result;
    for (int i = limit; i >= 1; i--) {
        int lowBit = i & -i;
        if (sum >= lowBit) {
            sum -= lowBit;
            result.push_back(i);
        }
    }

    if (sum > 0) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};
int main()
{
    fastio();
    solve();
    return 0;
}