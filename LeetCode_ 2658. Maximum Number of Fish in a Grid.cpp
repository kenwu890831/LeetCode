class Solution {
public:
    int DFS( vector<vector<int>>& grid, vector< vector< bool > >& visited, int& x, int& y ) {
        queue< pair<int,int> > q ;
        int m = grid.size(), n = grid[0].size() ;
        q.push( { x, y }) ;
        int dx[] = {  1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 } ;
        int sum = grid[x][y] ;
        visited[x][y] = true ;
        while( !q.empty() ) {
          auto current = q.front() ;
          q.pop() ;
          for ( int i = 0 ; i < 4 ; i++ ) {
            int tempX = current.first + dx[i], tempY = current.second + dy[i] ;
            if( tempX < 0 || tempX >= m ||tempY < 0 || tempY >= n || grid[tempX][tempY] == 0 || visited[tempX][tempY] == true ) ;
            else {
                sum += grid[tempX][tempY] ;
                visited[tempX][tempY] = true ;
                q.push( { tempX, tempY } ) ;
            }
          }
        }
        return sum ;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0 ;
        vector< vector< bool > > visited( m, vector< bool > ( n, false )) ;

        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( grid[i][j] == 0 || visited[i][j] == true )
                  continue ;
                else {
                    result = max( result, DFS( grid, visited, i, j )) ;
                }
            }
        }

        return result ;
    }
};