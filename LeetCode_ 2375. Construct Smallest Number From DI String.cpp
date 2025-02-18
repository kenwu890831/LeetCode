class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size() ;
        string result = "" ;
        stack< int > s ;
        for ( int i = 0 ; i <= n ; i++ ) {
            s.push( i+1 ) ;
            if ( i == n || pattern[i] == 'I' ) {
                while( !s.empty() ) {
                    result += ( '0' + s.top() ) ;
                    s.pop() ;
                }
            }
        }

        return result ;
    }
};