class Solution {
public:

    int cal(vector<vector<int>>& edges) {
        int n = edges.size() + 1 ; 
        vector<int> temp( n, 0 ) ;
        vector< vector<int> > adj ( n ) ;
        for ( auto& i : edges ) {
            int x = i[0], y = i[1] ;
            adj[x].push_back( y ) ;
            adj[y].push_back( x ) ;
            temp[x]++, temp[y]++ ;
        } // 紀錄關係


        queue< int > q ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( temp[i] == 1 ) 
              q.push( i ) ;
        } // 建立queue

        int level = 0, node = n ;
        for ( ; node > 2 ; level++ ) {
            int qsize = q.size() ;
            node -= qsize ; // 扣一層
            for ( int i = 0 ; i < qsize ; i++ ) {
                int x = q.front() ;
                q.pop() ;
                for ( int y : adj[x] ) {// 找下個外層
                    if ( --temp[y] == 1 )
                      q.push( y ) ;
                }
            }

        } // 逐層撥離



        return ( node == 2 ) ? 2 * level + 1 : 2 * level;




    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = cal( edges1 ), d2 = cal( edges2 ) ;
        return max( { d1, d2, ( d1+1 )/2+( d2+1 )/2+1 } );
        
    }
};


