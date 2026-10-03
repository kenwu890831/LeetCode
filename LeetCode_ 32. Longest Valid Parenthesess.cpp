class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0 ;
        if ( n < 2 )
            return 0 ;

        stack< int > stk ;
        vector< int > dp( n, 0 ) ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] == '(' ) {
                stk.push( i ) ;
            }
            else {
                if ( !stk.empty() ) {
                    int temp = stk.top() ;
                    dp[i] = i - temp + 1 ;
                    if ( temp >= 1 )
                        dp[i] += dp[temp-1] ;
                    
                    stk.pop() ;
                }

                ans = max( ans, dp[i] ) ;

            }          
        }

        return ans ;

    }
};