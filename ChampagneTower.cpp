class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101] = {0.0};
        dp[0][0] = poured;
        for (size_t i = 0; i <= query_row; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                if (dp[i][j] > 1) {
                    double pourDown = (dp[i][j] - 1.0) / 2.0;
                    dp[i + 1][j] += pourDown;
                    dp[i + 1][j + 1] += pourDown;
                    dp[i][j] = 1.0;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};
