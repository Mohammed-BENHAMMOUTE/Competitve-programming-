#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_operations(int n, int k, vector<int>& pieces) {
    int max_piece = *max_element(pieces.begin(), pieces.end());
    int max_piece_count = count(pieces.begin(), pieces.end(), max_piece);
    int total_operations = 0;

    for (int piece : pieces) {
        if (piece == max_piece && max_piece_count > 1) {
            total_operations += piece - 1; // Breaking the piece into length 1
            --max_piece_count;
        } else if (piece != max_piece) {
            total_operations += piece - 1; // Breaking the piece into length 1
        }
    }

    total_operations += (n - max_piece); // Merging all length 1 pieces with the largest piece

    return total_operations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> pieces(k);

        for (int i = 0; i < k; ++i) {
            cin >> pieces[i];
        }

        cout << minimum_operations(n, k, pieces) << "\n";
    }

    return 0;
}
