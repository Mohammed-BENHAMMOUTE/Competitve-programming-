string findLongestRegex(string x, string y, string z) {
    int n = x.length();
    string regex = "";
    for (int i = 0; i < n; ++i) {
        set<char> chars;
        // Include all uppercase letters except z[i]
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (c != z[i]) {
                chars.insert(c);
            }
        }
        // If x[i] or y[i] equals z[i], and no other characters are available, return -1
        if ((x[i] == z[i] || y[i] == z[i]) && chars.empty()) {
            return "-1";
        }
        // Build the regex part for position i
        string part = "[";
        for (char c : chars) {
            part += c;
        }
        part += "]";
        regex += part;
    }
    return regex;
}