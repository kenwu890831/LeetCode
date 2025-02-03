class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1, n = nums.size() ;
        int in = 1, de = 1 ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            if ( nums[i] < nums[i+1] ) {
                in++, de = 1 ;
            }
            else if ( nums[i] > nums[i+1] ) {
                in = 1, de++ ;
            }
            else {
                in = 1, de = 1 ;
            }

            result = max( in,  max( de, result ) ) ;
        }


        return result ;
    }
};