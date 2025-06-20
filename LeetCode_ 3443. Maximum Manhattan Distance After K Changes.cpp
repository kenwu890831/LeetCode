class Solution {
public:
    int maxDistance(string s, int k) {
        int N = 0, E = 0, S = 0, W = 0, result = 0 ;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == 'N')
                N++ ;
            else if ( s[i] == 'E' ) 
                E++ ;
            else if ( s[i] == 'W' ) 
                W++ ;
            else if ( s[i] == 'S' ) 
                S++ ;

            int dis = abs( N - S ) + abs( E - W ) ;     
            dis = dis + min( 2 * k, i + 1 - dis ) ;
            result = max( result, dis ) ;

            
        }

        return result ;
    }
};