class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, maxSum = 0 ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            maxSum = max( nums[i], maxSum + nums[i] ) ;
            result = max( result, maxSum ) ;
        }

        return result ;
    }
};