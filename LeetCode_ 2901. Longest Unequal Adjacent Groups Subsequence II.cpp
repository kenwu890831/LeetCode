class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), manLength = -1 ;
        vector< string > result ;
        vector< int > dp( n, 1 ), pre( n, -1 ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < i ; j++ ) {
                if ( groups[i] != groups[j] && charCheck( words[i], words[j] ) && dp[i] < dp[j] + 1 ) {
                    dp[i] = dp[j] + 1 ;
                    pre[i] = j ;
                }
            }

            manLength = max( manLength, dp[i] ) ;
        }

        
        for ( int i = 0 ; i < n ; i++ ) {
            if ( manLength == dp[i] ) {
                while( i != -1 ) {
                    result.push_back( words[i] ) ;
                    i = pre[i] ;
                }

                break ;
            }
        }


        reverse( result.begin(), result.end() );
        return result ;
    }

    bool charCheck(string input1, string input2 ) {
        if ( input1.size() != input2.size() ) 
            return false;
        int count = 0 ;
        for ( int i = 0 ; i < input1.size() ; i++ ) {
            if ( input1[i] != input2[i] )
                count++ ;
        }

        return count == 1 ;
    }
};