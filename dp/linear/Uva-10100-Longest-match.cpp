#include <bits/stdc++.h>
using namespace std;

vector<string> processString(string s) {
    vector<string> words;
    string word;
    
    // Convert all non-alphabetic chars to spaces
    for(int i = 0; i < s.length(); i++) {
        if(!isalpha(s[i])) {
            s[i] = ' ';
        }
    }
    
    // Handle multiple spaces and extract words
    stringstream ss(s);
    while(ss >> word) {
        if(!word.empty()) {
            words.push_back(word);
        }
    }
    return words;
}

int findLCS(vector<string>& s1, vector<string>& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string line1, line2;
    int caseNum = 1;
    
    while(getline(cin, line1)) {
        if(!getline(cin, line2)) break;
        
        // Check if lines contain only whitespace or punctuation
        bool isBlank1 = true, isBlank2 = true;
        for(char c : line1) if(isalpha(c)) isBlank1 = false;
        for(char c : line2) if(isalpha(c)) isBlank2 = false;
        
        cout << setw(2) << setfill(' ') << caseNum++ << ". ";
        
        if(isBlank1 || isBlank2) {
            cout << "Blank!" << endl;
            continue;
        }
        
        vector<string> words1 = processString(line1);
        vector<string> words2 = processString(line2);
        
        int result = findLCS(words1, words2);
        cout << "Length of longest match: " << result << endl;
    }
    return 0;
}