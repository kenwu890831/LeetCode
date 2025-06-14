class Solution {
public:
    int minMaxDifference(int num) {
        string max = "", min = "", s = to_string( num ) ;
        int n = s.size() ;

        char change = '0' ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] != '9' ) {
                change = s[i] ;
                break ;
            }
        }

        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] == change )
                max += '9' ;
            else
                max += s[i] ;
        }

        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[0] == s[i] )
                min += '0' ;
            else
                min += s[i] ;
        }

        return stoi( max ) - stoi( min ) ;
    }
};