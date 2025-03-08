class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0, wMin = INT_MAX ;
        for ( int i = 0 ; i < k ; i++ ) {
            if ( blocks[i] == 'W' )
                w++ ;
        }

        if ( w == 0 )
            return 0 ;
        else
            wMin = min( wMin, w ) ;

        for ( int i = k ; i < blocks.size() ; i++ ) {
            if ( blocks[i] == 'W' && blocks[i-k] == 'B' ) 
                w++ ;
            else if ( blocks[i] == 'B' && blocks[i-k] == 'W' ) {
                w-- ;
                wMin = min( wMin, w ) ;
            }
                
        }

        return wMin ;
    }
};