class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> firstidx;
        unordered_map<int, int> currfreq;
        int degree = 0, minLength = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (firstidx.find(nums[i]) == firstidx.end()) {
                firstidx[nums[i]] = i;
            }
            freq[nums[i]]++;
            degree = max(degree, freq[nums[i]]);
        }

        for (int i = 0; i < nums.size(); i++) {
            currfreq[nums[i]]++;
            if (currfreq[nums[i]] == degree) {
                int startidx = firstidx[nums[i]];
                minLength = min(minLength, i - startidx + 1);
            }
        }
        return minLength;
    }
};
