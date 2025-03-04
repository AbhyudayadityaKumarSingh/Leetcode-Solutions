class Solution {
public:
    int dp[205][205][205]; // DP table to store results

    // Function to calculate the cost to make two characters match
    int costToMatch(char a, char b) {
        int diff = abs(a - b);
        return min(diff, 26 - diff); // Wrap-around cost
    }

    // Recursive function to solve the problem
    int solve(string& s, int i, int j, int rem) {
        if (i > j) return 0; // Base case: invalid substring
        if (i == j) return 1; // Base case: single character
        if (dp[i][j][rem] != -1) return dp[i][j][rem]; // Return precomputed result

        int res = 0;
        // Option 1: Skip one of the characters
        res = max(solve(s, i + 1, j, rem), solve(s, i, j - 1, rem));

        // Option 2: Try to match s[i] and s[j] if the cost is within remaining operations
        int changeCost = costToMatch(s[i], s[j]);
        if (changeCost <= rem) {
            res = max(res, 2 + solve(s, i + 1, j - 1, rem - changeCost));
        }

        dp[i][j][rem] = res; // Store the result in the DP table
        return res;
    }

    // Main function to find the longest palindromic subsequence
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
        return solve(s, 0, n - 1, k); // Start solving from the entire string
    }
};