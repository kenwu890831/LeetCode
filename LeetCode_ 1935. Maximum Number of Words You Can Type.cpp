class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0 ;

        bool check = true ;
        for( auto& i : text ) {
            if ( i == ' ' ) {
                if ( check ) {
                    ans++ ;
                }

                check = true ;
            }

            for ( auto& j : brokenLetters ) {
                if ( i == j ) {
                    check = false ;
                    break ;
                }
            }
        }

        if ( check ) {
            ans++ ;
        }

        return ans ;
    }
};