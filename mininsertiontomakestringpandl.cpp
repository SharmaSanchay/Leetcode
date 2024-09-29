// leetcode ->1312 Dynamic programming
class Solution {
public:
    int minInsertions(string str) {
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        int n = str.size();
        vector<std::vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Building the DP table to find the length of the longest palindromic subsequence
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i - 1] == revStr[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of the longest palindromic subsequence
        int lpsLength = dp[n][n];
        // Minimum insertions needed
        return n - lpsLength;
    }
};
/*Time complexity -> O(N^2)
space complexity -> O(N^2)*/
