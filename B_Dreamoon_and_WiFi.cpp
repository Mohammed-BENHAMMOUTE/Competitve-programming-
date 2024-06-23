#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
double combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k); 
    double c = 1;
    for (int i = 0; i < k; ++i) {
        c = c * (n - i) / (i + 1);
    }
    return c;
}

int main() {
    string original, received;
    cin >> original >> received;
    int plus_original = 0, minus_original = 0;
    for (char c : original) {
        if (c == '+') plus_original++;
        else if (c == '-') minus_original++;
    };
    int plus_received = 0, minus_received = 0, question_marks = 0;
    for (char c : received) {
        if (c == '+') plus_received++;
        else if (c == '-') minus_received++;
        else if (c == '?') question_marks++;
    };
    int final_original = plus_original - minus_original;
    int final_received = plus_received - minus_received;
    int delta = final_original - final_received;
    if ((question_marks + delta) % 2 != 0 || abs(delta) > question_marks) {
        cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    };
    int p = (question_marks + delta) / 2;
    if (p < 0 || p > question_marks) {
        cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    };
    double favorable_cases = combination(question_marks, p);
    double total_cases = pow(2, question_marks);
    double probability = favorable_cases / total_cases;

    cout << fixed << setprecision(12) << probability << endl;

    return 0;
}