class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size() ;
        vector< bool > visited( n, false ) ;
        vector< int > depth( n, 1 ) ;
        vector< int > counter( n ) ;
        for( int i = 0 ; i < n ; i++ )
          counter[ favorite[i] ]++ ; 
        
        queue< int > q ; // Topological Sort


        for ( int i = 0 ; i < n ; i++ ) {
            if ( counter[i] == 0 ) {
                q.push( i ) ;
                visited[i] = true ;
            }
        }

        while( !q.empty() ) {
            int current = q.front() ;
            q.pop() ;
            int next = favorite[ current ] ;
            counter[ next ]-- ;
            if ( counter[ next ] == 0 ) {
                q.push( next ) ;
                visited[ next ] = true ;
                
            }

            depth[ next ] = depth[ current ] + 1 ;


        }

        int circle = 0, line = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( visited[i] == true )
              continue ;
            int j = i, count = 0 ;
            while ( visited[j] == false ) {
              count++ ;
              visited[j] = true ;
              j = favorite[j] ;
            } // find circle

            if ( count >= 3 ) // circle
              circle = max( circle, count ) ;
            else if ( count == 2 ) // 2 node circle and 2 line
              line += depth[i] + depth[ favorite[i] ] ;
        }






        return max( line, circle) ;
    }
};