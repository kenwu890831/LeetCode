class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector< int > temp ;
        int result = 0 ;
        temp.assign( heights.begin(), heights.end() ) ;
        sort( heights.begin(), heights.end() ) ;
        for ( int i = 0 ; i < heights.size() ; i++ ) {
            if ( heights[i] != temp[i] )
                result++ ;
        }

        return result ;
    }
};