class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size() ;
        vector< long long > dp( n, -1 ) ;


        return run( 0, questions, dp, n ) ;
    }

    long long run( int i, vector<vector<int>>& questions, vector<long long>& dp, int n ) {
        if( i >= n )
            return 0 ;
        if ( dp[i] != -1 )
            return dp[i] ;


        return dp[i] = max( questions[i][0] + run(i + questions[i][1] + 1, questions, dp, n), run( i+1 , questions, dp, n ) ) ;
    }
};