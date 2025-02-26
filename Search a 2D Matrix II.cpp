class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int start = 0, end = col - 1;
        while(start < row && end >= 0){
            if(target == matrix[start][end]){
                return true;
            }
            else if(target < matrix[start][end]){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};
