class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector< vector< int > > head ;
        vector< int > ans, temp ;
        int n = mat.size(), m = mat[0].size() ;
        bool check = true ;

        for( int i = 0 ; i < m ; i++ ) {
            head.push_back( { 0, i } ) ;
        }

        for( int i = 1 ; i < n ; i++ ) {
            head.push_back( { i, m - 1 } ) ;
        }

        for ( int i = 0 ; i < head.size() ; i++ ) {
            int x = head[i][0], y = head[i][1] ;
            
            while( ( x >= 0 && x < n ) && ( y >= 0 && y < m ) ) {
                temp.push_back( mat[x][y] ) ;
                x++, y-- ;
            }

            if ( i % 2 == 0 ) {
                reverse( temp.begin(), temp.end() ) ;
            }

            for( int j = 0 ; j < temp.size() ; j++ ) {
                ans.push_back( temp[j] ) ;
            }

            temp.clear() ;
        }


        return ans ;

        

    }
};