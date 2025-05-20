class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() ;
        vector< int > dp( n + 1, 0 ) ;
        for ( int i = 0 ; i < queries.size() ; i++ ) {
            dp[queries[i][0]]++ ;
            dp[queries[i][1]+1]-- ;
        }

        int temp = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            temp += dp[i] ;
            if ( nums[i] > temp )
                return false ;
        }
        return true ;
    }
};