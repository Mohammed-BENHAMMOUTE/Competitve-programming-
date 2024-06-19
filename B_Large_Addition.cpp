#include <iostream>
#include <string>
using namespace std;

bool canBeSumOfTwoLargeNumbers(string x) {
    int n = x.size();
    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        int digit = x[i] - '0' -carry +10;
        if(i == 0 ){
            if(digit !=10){
                return false;
            }else{
                return true;
            }
        }
        carry = 0;
        if(digit >18 || digit < 10){
            return false;
        }else{
            carry =1;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        if (canBeSumOfTwoLargeNumbers(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
