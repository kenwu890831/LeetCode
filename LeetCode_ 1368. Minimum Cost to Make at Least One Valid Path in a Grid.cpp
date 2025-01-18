class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector< vector< int > > temp( m, vector< int >( n, INT_MAX ));
        deque< pair< int, int > > q;
        int dx[4] = { 0, 0, 1, -1 }, dy[4] = {1, -1, 0, 0};
        
        q.push_front( { 0, 0 } ) ; // origin
        temp[ 0 ][ 0 ] = 0 ; // origin

        while ( !q.empty() ) {
            auto [ x, y ] = q.front() ;
            q.pop_front() ;
            int cur = grid[ x ][ y ] - 1 ;

            for ( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i], ny = y + dy[i] ;
                if ( nx < 0 || ny < 0 || nx >= m || ny >= n )  // over 
                    continue ;

                int cost = temp[ x ][ y ] + ( i == cur ? 0 : 1 ) ;
                if ( cost < temp[ nx ][ ny ] ) {
                    temp[ nx ][ ny ] = cost ;
                    if ( i == cur ) 
                       q.push_front( { nx, ny } ) ;
                    else 
                       q.push_back( { nx, ny } ) ;
                }
            }
        }

        return temp[ m - 1 ][ n - 1 ] ;
    }
};