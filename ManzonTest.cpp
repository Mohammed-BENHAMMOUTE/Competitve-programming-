#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getMaximumCategoryMaxCount(const string &categories) {
    int n = categories.size();
    int freq[26] = {0};
    int maxCounts[26] = {0};
    int *freqCount = new int[n + 1]();
    freqCount[0] = 26; 
    int maxFreq = 0;

    for(int i = 0; i < n; i++) {
        int idx = categories[i] - 'a';
        int oldFreq = freq[idx];
        freq[idx]++;
        int newFreq = oldFreq + 1;

        freqCount[oldFreq]--;
        freqCount[newFreq]++;

        if(newFreq > maxFreq) {
            maxFreq = newFreq;
        }
        
        if(freqCount[maxFreq] == 1) {
            maxCounts[idx]++;
        } else {
            for(int c = 0; c < 26; c++) {
                if(freq[c] == maxFreq) {
                    maxCounts[c]++;
                }
            }
        }
    }
    int result = 0;
    for(int i = 0; i < 26; i++) {
        result = max(result, maxCounts[i]);
    }

    delete[] freqCount;
    return result;
}

int main() {
    string categories;
    cin >> categories;
    cout << getMaximumCategoryMaxCount(categories) << endl;
    return 0;
}
