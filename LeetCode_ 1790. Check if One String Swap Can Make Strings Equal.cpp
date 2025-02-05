class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0, n = s1.size() ;
        char temp1, temp2 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( s1[i] != s2[i] ) {
                count++ ;
                if ( count == 1 ) {
                    temp1 = s1[i] ;
                    temp2 = s2[i] ;
                }
                else if ( count == 2 ) {
                    if ( temp1 != s2[i] )
                      return false ;
                    if ( temp2 != s1[i] )
                      return false ;
                }
                else {
                    return false ;
                }
            }
        }

        if ( count == 1 )
          return false ;
        return true ;
    }
};