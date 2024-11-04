#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Define a large constant for modulo operations to prevent overflow
const int MOD = 1e9 + 7;

// Memoization table
// dp[pos][tight][other_state_variables...]
long long dp[20][2][/* other dimensions based on problem requirements */];

// Recursive Digit DP function
// Parameters:
// pos: Current position in the digit string
// tight: Flag indicating if the current prefix is tight (matches the prefix of the upper bound)
// other_state_variables: Additional state variables as required by the specific problem
long long digitDP(int pos, bool tight, /* other state variables */, const string &num) {
    // Base case: If all positions are processed
    if (pos == num.size()) {
        // Check if the current number satisfies the problem's condition
        // Return 1 if it does, otherwise return 0
        return /* condition */ ? 1 : 0;
    }

    // Check if the result for this state is already computed
    if (dp[pos][tight][/* other state variables */] != -1) {
        return dp[pos][tight][/* other state variables */];
    }

    // Determine the upper limit for the current digit
    int limit = tight ? (num[pos] - '0') : 9;
    long long res = 0;

    // Iterate over all possible digits for the current position
    for (int digit = 0; digit <= limit; ++digit) {
        // Update the tight flag for the next position
        bool newTight = tight && (digit == limit);

        // Update other state variables based on the current digit and position
        // For example, updating sum of digits, count of certain digits, etc.
        /* update other state variables */

        // Recursive call for the next position
        res = (res + digitDP(pos + 1, newTight, /* updated state variables */, num)) % MOD;
    }

    // Store the result in the memoization table
    return dp[pos][tight][/* other state variables */] = res;
}

// Function to count numbers up to a given number that satisfy the problem's condition
long long countValidNumbers(const string &num) {
    // Initialize the memoization table with -1
    memset(dp, -1, sizeof(dp));

    // Start the recursive Digit DP from position 0 with tight flag set to true
    // Initialize other state variables as required
    return digitDP(0, true, /* initial state variables */, num);
}

int main() {
    string a, b;
    cin >> a >> b;

    // Count valid numbers up to b
    long long countB = countValidNumbers(b);

    // Count valid numbers up to a
    long long countA = countValidNumbers(a);

    // Result is the difference
    long long result = (countB - countA + MOD) % MOD;

    cout << result << endl;
    return 0;
}
