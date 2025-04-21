class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long result = 0, less = 0, large = 0, temp = 0 ;
        for ( int i = 0 ; i < differences.size() ; i++ ) {
            temp += differences[i] ; 
            large = max( large, temp ) ;
            less = min( less, temp ) ;
        }

        if ( large - less > upper - lower )
            return 0 ;
        result = ( upper - lower ) - ( large - less ) + 1 ;
        return result ;
    }
};