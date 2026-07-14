constexpr int mod = 1000000007;
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 0));
        dp[0][0] = 1;
        for (int x: nums) {
            auto ndp = dp;
            for (size_t g1 = 0; g1 <= mx; g1 += 1) {
                for (size_t g2 = 0; g2 <= mx; g2 += 1) {
                    if (dp[g1][g2] == 0) continue;
                    int n1 = gcd(g1, x), n2 = gcd(g2, x);
                    ndp[n1][g2] = (ndp[n1][g2] + dp[g1][g2]) % mod;
                    ndp[g1][n2] = (ndp[g1][n2] + dp[g1][g2]) % mod;
                }
            }
            dp = ndp;
        }
        int ans = 0;
        for (size_t g = 1; g <= mx; g++) {
            ans = (ans + dp[g][g]) % mod;
        }
        return ans;
    }
};
