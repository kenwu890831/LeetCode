class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), result = INT_MAX ;
        int topTemp[6] = {0}, botTemp[6] = {0}, count[6] = {0} ;

        for ( int i = 0 ; i < n ; i++ ) {
            topTemp[tops[i]-1]++ ;
            botTemp[bottoms[i]-1]++ ;
            count[bottoms[i]-1] += ( tops[i]-1 == bottoms[i]-1 ) ;
        }

        for ( int i = 0 ; i < 6 ; i++ ) {
            if ( (topTemp[i] + botTemp[i] - count[i]) == n )
                result = min( result, min( n - topTemp[i], n - botTemp[i] )) ;
        }



        return result == INT_MAX ? -1 : result ;
    }
};