class Solution {
public:
    int mod = 1e9 + 7 ;
    int lengthAfterTransformations(string s, int t) {
        vector< int > count( 26, 0 ) ;
        int result = 0 ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            count[s[i] -'a']++ ;
        }

        for ( int i = 0 ; i < t ; i++ ) {
            vector< int > temp( 26, 0 ) ;
            for ( int j = 0 ; j < 26 ; j++ ) {
                if ( j == 25 ) {
                    temp[0] = ( temp[0] + count[j]) % mod ;
                    temp[1] = ( temp[1] + count[j]) % mod ;
                    
                }
                else {
                    temp[j + 1] = ( temp[j + 1] + count[j]) % mod ;
                }
            }

            count = temp ;
        }

        for ( int i = 0 ; i < 26 ; i++ ) {
            result = ( result + count[i] ) % mod ;
        }

        return result ;
    }
};