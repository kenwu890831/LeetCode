class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector< int > temp ;
        int pre = grid[0][0], result = 0 ;
        for ( int i = 0 ; i < grid.size() ; i++ ) {
            for ( int j = 0 ; j < grid[i].size() ; j++ ) {
                if ( ( grid[i][j] - pre ) % x != 0 )
                    return -1 ;
                else {
                    temp.push_back( grid[i][j] ) ;
                    pre = grid[i][j] ;
                }
                    
            } 
        } // for 

        sort( temp.begin(), temp.end() ) ;

        int mid = temp[temp.size()/2]  ;



        for ( int i = 0 ; i < temp.size() ; i++ ) {
            result += abs( temp[i] - mid ) / x ;
        }




        return result ;
        
    }
};