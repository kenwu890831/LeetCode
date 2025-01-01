class Solution {
public:
    int maxScore(string s) {
        int left = 0, right = 0, result = 0 ;
        if ( s[0] == '0' )
          ++left ;
        for ( int i = 1 ; i < s.size() ; i++ ) {
            if ( s[i] == '1')
              ++right ;
        }

        result = max( result, left+right ) ;

        for ( int i = 1 ; i < s.size()-1 ; i++ ) {
            
            if ( s[i] == '1') {
              --right ;
            }
            else
              ++left ;

            result = max( result, left+right ) ;
              
        }


        return result ;
    }
};