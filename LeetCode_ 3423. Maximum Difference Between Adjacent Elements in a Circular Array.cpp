class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size() ;
        int result = abs( nums[0] - nums[n-1] ) ;
        for( int i = 0 ; i < nums.size() - 1; i++ ) {
            result = max( result, abs( nums[i] - nums[i+1] ) ) ;
        }

        return result ;
    }
};