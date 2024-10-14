
//The prefix function computes for every position i the length of the longest proper prefix of s[0...i] that is also a suffix.
vector<int> prefix_function(string s) {
    int n = s.size();              // Length of the string
    vector<int> pi(n,0);             // Create a pi array to store prefix function values
    for (int i = 1; i < n; i++) {  // Start from the second character
        int j = pi[i - 1];         // j is the length of the best proper prefix that is also a suffix for s[0...i-1]
        while (j > 0 && s[i] != s[j]) // If mismatch, follow the previous best prefix
            j = pi[j - 1];          // Try shorter prefixes
        if (s[i] == s[j])           // If a match, extend the best prefix
            j++;
        pi[i] = j;                  // Store the result in pi[i]
    }
    return pi;                      // Return the pi array
}

void KMP(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> pi = prefix_function(pattern); // Compute the prefix function for the pattern
    for (int i = 0, j = 0; i < n; i++) {      // Traverse the text
        while (j > 0 && text[i] != pattern[j])// If mismatch, use the pi array to shift the pattern
            j = pi[j - 1];
        if (text[i] == pattern[j])            // If match, move forward in both text and pattern
            j++;
        if (j == m) {                         // If entire pattern is found
            cout << "Pattern found at index " << i - m + 1 << endl; // Output the starting index
            j = pi[j - 1];                    // Reset j for the next match
        }
    }
}

//The Z-algorithm computes the Z-array for a given string s, where Z[i] is the length of the longest substring starting from i that is also a prefix of s.
vector<int> z_function(string s) {
    int n = s.size();              // Length of the string
    vector<int> z(n);              // Create a Z array to store Z values
    for (int i = 1, l = 0, r = 0; i < n; i++) { // Start from the second character
        if (i <= r)                // If i is within the current Z-box
            z[i] = min(r - i + 1, z[i - l]);  // Copy the value from the Z-box
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) // Try to extend the Z-box
            z[i]++;
        if (i + z[i] - 1 > r)      // Update the Z-box boundaries
            l = i, r = i + z[i] - 1;
    }
    return z;
}
// here l is from i and r is rightmost known index
