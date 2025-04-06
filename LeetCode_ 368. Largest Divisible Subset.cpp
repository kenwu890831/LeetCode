class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort( nums.begin(), nums.end() ) ;
        int n = nums.size(), maIndex = 0 ;
        vector< int > result ;
        vector< int > dp( n, 0 ) ;
        vector< int > pre( n, -1 ) ;
        for ( int i = 1 ; i < n ; i++ ) {
            for ( int j = 0 ; j < i ; j++ ) {
                if ( nums[i] % nums[j] == 0 && dp[i] < dp[j]+1 ) {
                    dp[i] = dp[j] + 1 ;
                    pre[i] = j ;
                }
            }

            if ( dp[i] > dp[maIndex] )
                maIndex = i ;
        }

        for ( int i = maIndex ; i >= 0 ; i = pre[i] ) {
            result.push_back( nums[i] ) ;
            if ( pre[i] == -1 )
                break ;
        }



        return result ;
    }
};