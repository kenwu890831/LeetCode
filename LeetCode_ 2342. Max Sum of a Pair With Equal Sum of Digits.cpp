class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map< int, int > hash ;
        int result = 0, n = nums.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            int con = 0, temp = nums[i] ;
            while( temp > 0 ) {
                con += temp % 10 ;
                temp /= 10 ;
            }

            if ( hash[con] != 0 ) {
                result = max( result, nums[i]+hash[con] ) ;

            }

            hash[con] = max( hash[con], nums[i] ) ;
        }

        return result == 0 ? -1 : result ;
    }
};