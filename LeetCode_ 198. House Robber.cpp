class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), result = 0 ;
        if ( n == 1 )
            return nums[0] ;
        vector< int > dp( n+1, 0 ) ;
        dp[0] = 0 ;
        dp[1] = nums[0] ;
        if ( n >= 2 )
          dp[2] = nums[1] ;

        for ( int i = 3 ; i <= n ; i++ ) {
            dp[i] = max( dp[i-3] + nums[i-1], dp[i-2] + nums[i-1] ) ;
            //cout << dp[i] << endl ;
        }

        result = max( dp[n], max( dp[n-1], dp[n-2])) ;

        return result ;
    }
};