class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), result = 0 ;
        vector< bool > temp( 100, false ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( nums[i] < k )
                return -1 ;

            if ( temp[nums[i]] == false && nums[i] != k ) {
                result++ ;
                temp[nums[i]] = true ;
            }

            
            
        }

        return result ;


    }
};