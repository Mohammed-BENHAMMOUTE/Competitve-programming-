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

bool isWinner(const string &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[3 * i] == player && board[3 * i + 1] == player && board[3 * i + 2] == player) return true; // rows
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) return true; // columns
    }
    if (board[0] == player && board[4] == player && board[8] == player) return true; // diagonal
    if (board[2] == player && board[4] == player && board[6] == player) return true; // diagonal
    return false;
}

bool validTicTacToe(string &s)
{
    int cx = 0, co = 0;
    for (int i = 0; i < 9; i++)
    {
        if (s[i] == 'X') cx++;
        if (s[i] == 'O') co++;
    }
    if (cx < co || cx > co + 1) return false;

    bool xwin = isWinner(s, 'X');
    bool owin = isWinner(s, 'O');

    if (xwin && owin) return false;
    if (xwin && cx == co) return false;
    if (owin && cx > co) return false;
    return true;
}

void solve(string &s)
{
    if (!validTicTacToe(s))
    {
        cout << "invalid" << endl;
        return;
    };
    int countpoint =0;
    for(int i = 0; i < 9; i++){
        if(s[i] == '.') countpoint++;
    };
    if(countpoint == 0) {
        cout << "valid" << endl;
        return;
    };

    set<string> visited;
    queue<pair<string, int>> q;
    string start = ".........";
    q.push({start, 0});

    while (!q.empty())
    {
        string c = q.front().first;
        if(isWinner(c, 'X') || isWinner(c, 'O')) {
            q.pop();
            if (c == s)
            {
                cout << "valid" << endl;
                return;
            }
            continue;
        };
        int r = q.front().second;
        q.pop();
        for (int i = 0; i < 9; i++)
        {
            if (c[i] == '.')
            {
                string next = c;
                next[i] = (r % 2 == 0) ? 'X' : 'O';
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    q.push({next, r + 1});
                }
            }
        }
    }
    cout << "invalid" << endl;
}

int main()
{
    fastio();
    string s;
    while (cin >> s && s != "end")
    {
        solve(s);
    }
    return 0;
}