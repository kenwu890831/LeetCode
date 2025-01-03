class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long  right = 0, left = 0 ;
        int result = 0 ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            left += nums[i] ;
        }

        for ( int i = 0 ; i < nums.size()-1 ; i++ ) {
            left -= nums[i] ;
            right += nums[i] ;

            if ( right >= left )
              ++result ;
        }


        return result ;
    }
};