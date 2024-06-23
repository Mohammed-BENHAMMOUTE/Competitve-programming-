// Mohamed Benhammoute
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int strLength, numUpdates;
        cin >> strLength >> numUpdates;

        string originalString;
        cin >> originalString;

        vector<int> updateIndices(numUpdates);
        for (int i = 0; i < numUpdates; i++) {
            cin >> updateIndices[i];
        }

        string updateChars;
        cin >> updateChars;

        // Sort the indices to process them in order
        sort(updateIndices.begin(), updateIndices.end());

        // Use multiset to store update characters in sorted order
        multiset<char> sortedChars(updateChars.begin(), updateChars.end());

        // Array to keep track of used indices
        vector<bool> indexUsed(strLength + 1, false);

        // Apply the updates in sorted order
        for (int i = 0; i < numUpdates; i++) {
            if (indexUsed[updateIndices[i]]) {
                // If the index is already used, remove the largest remaining character
                auto it = sortedChars.rbegin();
                sortedChars.erase(--it.base());
            } else {
                // Otherwise, apply the smallest character to the index
                auto it = sortedChars.begin();
                originalString[updateIndices[i] - 1] = *it;
                sortedChars.erase(it);
                indexUsed[updateIndices[i]] = true;
            }
        }

        // Output the modified string
        cout << originalString << endl;
    }

    return 0;
}
