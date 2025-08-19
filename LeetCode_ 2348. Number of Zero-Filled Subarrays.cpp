class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0 ;
        int n = nums.size(), count = 0 ;
        unordered_map< int, int > h ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( nums[i] == 0 )
                count++ ;
            else {
                h[count]++ ;
                count = 0 ;
            }
        }

        if ( count != 0 )
            h[count]++ ;

        for( auto temp : h ) {
            ans += (long long )temp.first * ( temp.first + 1 ) / 2 * temp.second ;
        }

        return ans ;
    }
};