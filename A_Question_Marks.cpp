#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solve_test_case() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> count(4, 0);
    int question_marks = 0;
    
    for (char c : s) {
        if (c == '?') {
            question_marks++;
        } else {
            count[c - 'A']++;
        }
    }
    
    int correct = 0;
    int remaining = 4 * n;
    
    for (int i = 0; i < 4; i++) {
        int correct_for_letter = min(count[i], n);
        correct += correct_for_letter;
        remaining -= count[i];
    }
    
    int additional_correct = min(question_marks, remaining);
    return correct + additional_correct;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cout << solve_test_case() << endl;
    }
    
    return 0;
}