class Solution {
public:
    string pushDominoes(string dominoes) {
        if ( dominoes.size() == 1 ) 
            return dominoes ;

        while( move( dominoes ) ) ;


        return dominoes ;
    }


    bool move( string &dominoes ) {
        int n = dominoes.size() ;
        string temp( n, '.') ;
        int count = 0 ;
        temp[0] = dominoes[0] ;
        temp[n-1] = dominoes[n-1] ;
        // head
        if ( dominoes[1] == 'L' && dominoes[0] == '.')
            temp[0] = 'L' ;
        // tail
        if ( dominoes[n-2] == 'R' && dominoes[n-1] == '.' )
            temp[n-1] = 'R' ;
        
        if ( n > 2 ) {
            char left = dominoes[0], right = dominoes[2];
            for ( int i = 1 ; i <= n -2 ; i++ ) {
                if ( dominoes[i] == 'L' || dominoes[i] == 'R' )
                    temp[i] = dominoes[i] ;
                else {
                    if ( dominoes[i-1] == 'R' && dominoes[i+1] == 'L' ) ;
                    else {
                        if ( dominoes[i-1] == 'R' ) {
                            temp[i] = dominoes[i-1] ;
                            count++ ;
                        }                  
                        else if ( dominoes[i+1] == 'L' ) {
                            temp[i] = dominoes[i+1] ;
                            count++ ;
                        }
                            
                    }
                }
                
            }
        }

        dominoes = temp ;
        if ( count == 0 )
            return false ;
        return true ;

    }
};