class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int temp = 0 ;
        int large[100], small[100] ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            temp = max( nums[i], temp ) ;
            large[i] = temp ;
        }

        for ( int i = nums.size()-1 ; i >= 0 ; i-- ) {
            temp = min( nums[i], temp ) ;
            small[i] = temp ;
        }

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( large[i] - small[i] <= k )
                return i ;
        }

        return -1 ;
    }
};