class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size() ;
        vector< vector< bool > > visited( m, vector( n, false ) ) ;
        vector< int > islandSize ;
        islandSize.push_back( 0 ) ; // 0 place
        int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 } ;
        int islandCount = 1, maxSize = 0 ;

        for ( int i = 0 ; i < m ; i++ ) { // run all node
            for ( int j = 0 ; j < n ; j++ ) {
              
              if ( grid[i][j] == 0 || visited[i][j] == true ) ;
              else { // DFS count every island size and save to islandSize
                queue< pair< int, int > > q ;
                int count = 1 ;
                q.push( { i, j }) ;
                visited[i][j] = true ;
                grid[i][j] = islandCount ;
                while( !q.empty() ) {
                    auto temp = q.front() ;
                    q.pop() ;
                    for ( int trl = 0 ; trl < 4 ; trl++ ) {
                        int x = temp.first + dx[trl], y = temp.second + dy[trl] ;
                        if ( x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true || grid[x][y] != 1 ) ;
                        else {
                            //cout << x << " " << y << endl ;
                            q.push( { x, y } ) ;
                            visited[x][y] = true ;
                            grid[x][y] = islandCount ;
                            count++ ;
                        }
                    }
                    //cout << temp.first << " " << temp.second << endl ;


                } // while DFS

                islandCount++ ;
                islandSize.push_back( count ) ;
                maxSize = max( maxSize, count ) ;

              }
            }
        }


   /*     for( int i = 0 ; i < islandSize.size() ; i++ ) 
          cout << islandSize[i] << endl ;*/

        for ( int i = 0 ; i < m ; i++ ) { // check connect
            for ( int j = 0 ; j < n ; j++ ) {
                if ( grid[i][j] == 0 ) {
                    int sum = 1 ;
                    for ( int trl = 0 ; trl < 4 ; trl++ ) {
                        int x = i + dx[trl], y = j + dy[trl] ;
                        if ( x < 0 || x >= m || y < 0 || y >= n || islandSize[grid[x][y]] == 0 ) ;
                        else if ( islandSize[grid[x][y]] > 0 ) {
                            sum += islandSize[grid[x][y]] ;
                            islandSize[grid[x][y]] *= -1 ;
                        }

                    }

                    for ( int trl = 0 ; trl < 4 ; trl++ ) {
                        int x = i + dx[trl], y = j + dy[trl] ;
                        if ( x >= 0 && x < m && y >= 0 && y < n && islandSize[grid[x][y]] < 0 ) {
                            islandSize[grid[x][y]] *= -1 ;
                        }

                    }

                    maxSize = max( maxSize, sum ) ;
                }

                
            }
        }

        return maxSize ;
    }
};