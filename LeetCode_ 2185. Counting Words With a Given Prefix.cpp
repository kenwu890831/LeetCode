class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pSize = pref.size(), result = 0 ;
        for ( int i = 0 ; i < words.size() ; i++ ) {
            bool check = true ;
            for ( int j = 0 ; j < pSize ; j++ ) {
              if ( pref[j] != words[i][j] ) {
                check = false ;
                break ;
              }
            
            }

            if ( check )
              ++result ;
        }


        return result ;
    }
};