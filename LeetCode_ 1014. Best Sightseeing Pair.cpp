class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), result = 0 ;
        int i_temp = values[0] ;
        for ( int i = 1 ; i < n ; i++ ) {
            result = max( result, i_temp + values[i] - i ) ;
            i_temp = max( i_temp, values[i]+i ) ;

        }

        return result ;
    }
};