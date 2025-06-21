class Solution {
public:
    int minimumDeletions(string word, int k) {
        int temp[26] = { 0 } ;
        int result = word.size(), minIndex = 0, minFrq = 0 ;
        for ( int i = 0 ; i < word.size() ; i++ ) {
            temp[ word[i] - 'a' ]++ ;
        }

        sort( temp ,temp+ 26 ) ;

        for ( int i = 0  ; i < 26 ; i++ ) {
            if ( temp[i] != 0 ) {
                minIndex = i ;
                minFrq = temp[i] ;
                break ;
            }
                
        }



        for ( int i = minIndex ; i < 26 ; i++ ) { // frq 0 ~ max
            int sum = 0, line = temp[i] ;
            for ( int j = minIndex ; j < 26 ; j++ ) {
                if ( temp[j] < line )
                    sum += temp[j] ;
                else if( temp[j] >= ( line + k ) )
                    sum += (temp[j] - ( line + k )) ;

            }

            
            result = min( result, sum ) ;
        }


        return result ;
    }
};                                        