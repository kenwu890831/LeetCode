class Solution {
public:
    int numTilePossibilities(string tiles) {
        int result = 0, n = tiles.size() ;
        vector< int > temp( 26, 0 ) ;
        for ( int i = 0 ; i < n ; i++ ) {
            temp[tiles[i]-'A']++ ;
        }

        



        return trl( tiles, temp ) ;
    }

    int trl( string tiles, vector< int >& temp) {
        int count = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( temp[i] == 0 )
                continue ; 
            temp[i]-- ;
            count = count + 1 + trl( tiles, temp ) ;
            temp[i]++ ;
        }

        return count ;
    }

    
};