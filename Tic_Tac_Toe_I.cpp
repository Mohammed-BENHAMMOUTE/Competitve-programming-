#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> valid_states;

bool check_win(const string& board, char player) {
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i*3] == player && board[i*3+1] == player && board[i*3+2] == player) return true;
        if (board[i] == player && board[i+3] == player && board[i+6] == player) return true;
    }
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;
    return false;
}

void generate_states(string& board, int turn = 0) {
    valid_states.insert(board);
    
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            board[i] = (turn % 2 == 0) ? 'X' : 'O';
            if (valid_states.find(board) == valid_states.end()) {
                generate_states(board, turn + 1);
            }
            board[i] = '.';
        }
    }
}

bool is_valid_state(const string& board) {
    int x_count = 0, o_count = 0;
    for (char c : board) {
        if (c == 'X') ++x_count;
        else if (c == 'O') ++o_count;
    }
    
    // Check if counts are valid
    if (x_count < o_count || x_count > o_count + 1) return false;
    
    // Check if both players are winning
    bool x_win = check_win(board, 'X');
    bool o_win = check_win(board, 'O');
    
    // If X wins, O count should be less than X count
    if (x_win && o_count >= x_count) return false;
    
    // If O wins, counts should be equal
    if (o_win && x_count != o_count) return false;
    
    // Both players can't win
    if (x_win && o_win) return false;
    
    return valid_states.count(board);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string initial_board = ".........";
    generate_states(initial_board);
    
    int t;
    cin >> t;
    
    while (t--) {
        string board;
        for (int i = 0; i < 3; ++i) {
            string row;
            cin >> row;
            board += row;
        }
        
        cout << (is_valid_state(board) ? "yes" : "no") << '\n';
        cin.ignore();
    }
    
    return 0;
}