class Solution {
public:
    bool canConstruct(string s, int k) {
        if ( s.size() < k )
          return false ;
        int temp[26] = {0} ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
          temp[ s[i] - 'a' ]++ ;
        }

        int odd = 0 ;

        for ( int i = 0 ; i < 26 ; i++ ) {
          temp[i] = temp[i] % 2 ;
        }

        for ( int i = 0 ; i < 26 ; i++ ) {
          if ( temp[i] % 2 == 1 )
            ++odd ;
        }


        if ( odd > k )
          return false ;



        return true ;

    }
};