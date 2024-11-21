class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int result = 0 ;
        vector< vector<int> > arr( m, vector<int>(n,0)) ;

        for ( auto& x : walls ) {
            arr[x[0]][x[1]] = 1 ;
        }

        for ( auto& x : guards ) {
            arr[x[0]][x[1]] = 2 ;

        }

        for ( auto& x : guards ) {
            // north
            int tempX = x[0], tempY = x[1] ;

            while ( tempX > 0 ) {
              tempX-- ;
              if ( arr[tempX][tempY] == 1 || arr[tempX][tempY] == 2 )
                break ;
              arr[tempX][tempY] = 3 ;
            }
            // west
            tempX = x[0], tempY = x[1] ;

            while ( tempY > 0 ) {
              tempY-- ;
              if ( arr[tempX][tempY] == 1 || arr[tempX][tempY] == 2 )
                break ;
              arr[tempX][tempY] = 3 ;
            }

            // east
            tempX = x[0], tempY = x[1] ;

            while ( tempY < n-1 ) {
              tempY++ ;
              if ( arr[tempX][tempY] == 1 || arr[tempX][tempY] == 2 )
                break ;
              arr[tempX][tempY] = 3 ;
            }

            // south

            tempX = x[0], tempY = x[1] ;

            while ( tempX < m-1 ) {
              tempX++ ;
              if ( arr[tempX][tempY] == 1 || arr[tempX][tempY] == 2 )
                break ;
              arr[tempX][tempY] = 3 ;
            }


        }        
        for ( auto& x : arr) {
            for ( int y: x) {
                if ( y == 0)
                  result++ ;
            }
        }

        



        return result ;
        
    }
};