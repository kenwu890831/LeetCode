class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size() ;
        queue< pair<int, int > > temp ;
        vector< vector< int > > result( m, vector< int >( n, -1 ) ) ;
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( mat[i][j] == 0 ) {
                    result[i][j] = 0 ;
                    temp.push( { i, j } ) ;
                }
            }
        }

        int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 } ;
        while( !temp.empty() ) {
            auto[ x, y ] = temp.front() ;
            temp.pop() ;
            for ( int i = 0 ; i < 4 ; i++ ) {
                int newX = x + dx[i], newY = y + dy[i] ;
                if ( newX >=0 && newX < m && newY >= 0 && newY < n && result[newX][newY] == -1 ) {
                    result[newX][newY] = result[x][y] + 1 ;
                    temp.push( { newX, newY } ) ;
                }
            }
        }

        


        return result ;
    }
};