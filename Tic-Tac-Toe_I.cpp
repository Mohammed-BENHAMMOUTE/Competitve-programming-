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
    vector<string> board(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> board[i];
    };
    int x = 0, o = 0, e = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
            {
                x++;
            }
            else if (board[i][j] == 'O')
            {
                o++;
            }
            else
            {
                e++;
            }
        }
    };
    if(o > x || x-o >1) {
        cout << "no\n";
    }else{
        bool xwin = false, owin = false;
        for (int i = 0; i < 3; i++)
        {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] == 'X'){
                    xwin = true;
                }else if(board[i][0] == 'O'){
                    owin = true;
                }
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X'){
                    xwin = true;
                }else if(board[0][i] == 'O'){
                    owin = true;
                }
            }
        };
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[0][0] == 'X'){
                xwin = true;
            }else if(board[0][0] == 'O'){
                owin = true;
            }
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[0][2] == 'X'){
                xwin = true;
            }else if(board[0][2] == 'O'){
                owin = true;
            }
        }
        if(xwin && owin){
            cout << "no\n";
        }else if(xwin && x == o){
            cout << "no\n";
        }else if(owin && x > o){
            cout << "no\n";
        }else{
            cout << "yes\n";
        }
    }
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