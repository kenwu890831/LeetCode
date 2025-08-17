class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if ( k == 0 || n >= k + maxPts ) 
            return 1.0 ;

        vector< double > temp( n + 1, 0.0 ) ;
        temp[0] = 1.0 ;
        double window = 1.0, result = 0.0 ;

        for ( int score = 1 ; score <= n ; score++ ) {
            temp[score] = window / maxPts ;

            if ( score < k ) {
                window += temp[score] ; 
            } else {
                result += temp[score] ;
            }

            if ( score - maxPts >= 0 ) {
                window -= temp[ score - maxPts ] ;
            }
        }

        return result ;
    }
};
