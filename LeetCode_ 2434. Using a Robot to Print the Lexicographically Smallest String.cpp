class Solution {
public:
    string robotWithString(string input) {
        vector< int > h( 26, 0 ) ;
        stack< char > s ;
        int n = input.size() ;
        string result = "" ;
        for ( int i = 0 ; i < n ; i++ ) {
            h[input[i]-'a']++ ;
        }

        for ( char c : input ) {
            s.push( c ) ;
            h[c-'a']-- ;

            while( !s.empty() && s.top() <= minChar( h ) ) {
                result += s.top() ;
                s.pop() ;
            }
        }

        while( !s.empty() ) {
            result += s.top() ;
            s.pop() ;
        }

        return result ;
    }

    char minChar( vector< int > & h ) {
        for( int i = 0 ; i < 26 ; i++ ) {
            if ( h[i] > 0 )
                return 'a' + i ;
        }

        return 'a' ;
    }
};