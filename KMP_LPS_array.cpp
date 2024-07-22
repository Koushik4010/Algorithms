// Function to create the lookup table (also called the "LPS" array)
    void computeLPSArray(string& pat, int M, vector<int>& lps) {
        int len = 0; // length of the previous longest prefix suffix
        lps[0] = 0; // lps[0] is always 0
        int i = 1;
        
        // the loop calculates lps[i] for i = 1 to M-1
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else { // (pat[i] != pat[len])
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    // KMP algorithm for pattern matching
    bool KMP(string& txt, string& pat) {
        int N = txt.size();
        int M = pat.size();
        
        vector<int> lps(M);
        computeLPSArray(pat, M, lps);
        
        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            
            if (j == M) {
                cout << "Pattern found at index " << i - j << endl;
                j = lps[j - 1];
                return true; // Return true if pattern is found
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false; // Return false if pattern is not found
    }
