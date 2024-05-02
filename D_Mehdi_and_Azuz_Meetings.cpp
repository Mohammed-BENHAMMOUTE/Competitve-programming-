#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int parseTime(string strTime) {
    int h, m;
    stringstream ss(strTime);
    char ch;
    ss >> h >> ch >> m;
    return h * 60 + m;
}

vector<int> buildAvailability(vector<string> schedules) {
    vector<int> available(1440, 0);
    for (auto schedule : schedules) {
        stringstream ss(schedule);
        string startStr, endStr;
        getline(ss, startStr, '-');
        getline(ss, endStr);
        int start = parseTime(startStr);
        int end = parseTime(endStr);
        available[start]++;
        if (end + 1 != 1440) {
            available[end + 1]--;
        }
    }

    for (int i = 1; i < 1440; i++) {
        available[i] += available[i - 1];
    }

    return available;
}

bool isPossible(vector<int>& availabilityA, vector<int>& availabilityB) {
    for (int i = 0; i < 1440 - 30; i++) {
        int j = i;
        while (j <= i + 30 && j < 1440 && availabilityA[j] && availabilityB[j]) {
            j++;
        }
        if (j == i + 31) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> schedulesA(n);
        for (int i = 0; i < n; i++) {
            cin >> schedulesA[i];
        }
        vector<int> availabilityA = buildAvailability(schedulesA);

        int m;
        cin >> m;
        vector<string> schedulesB(m);
        for (int i = 0; i < m; i++) {
            cin >> schedulesB[i];
        }
        vector<int> availabilityB = buildAvailability(schedulesB);

        cout << (isPossible(availabilityA, availabilityB) ? "YES" : "NO") << endl;
    }

    return 0;
}
