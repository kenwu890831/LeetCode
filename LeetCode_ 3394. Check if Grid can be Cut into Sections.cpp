class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector< vector< int > > x_temp, y_temp ;
        for ( int i = 0 ; i < rectangles.size() ; i++ ) {
            x_temp.push_back( { rectangles[i][0], rectangles[i][2] }) ;
            y_temp.push_back( { rectangles[i][1], rectangles[i][3] }) ;
        }


        return check( x_temp ) || check( y_temp ) ;
    }

    bool check( vector< vector< int > >& input ) {
        sort( input.begin(), input.end() ) ;
        int max_end = input[0][1];
        int count = 0 ;
        for ( int i = 0 ; i < input.size() ; i++ ) {
            int s = input[i][0], e = input[i][1] ;
            if ( max_end <= s ) 
                count++ ;

            max_end = max( max_end, e ) ;
        }

        return count >= 2 ;
    }
};