class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector< bitset< 100 > > temp( n ) ;
        vector< int > degree( n, 0 ) ; // 
        vector< vector< int > > adj( n ) ; 
        vector< bool > result ;
        queue < int > q ;

        for ( auto& pre : prerequisites ) {
            
            adj[ pre[0] ].push_back( pre[1] ) ;
            temp[pre[1]].set( pre[0] ) ;
            degree[ pre[1] ]++ ;
        }

        for( int i = 0 ; i < degree.size(); i++ ) {
            if ( degree[i] == 0 ) 
              q.push( i ) ;
        }

        while( !q.empty() ) {
            int cur = q.front() ;
            q.pop() ;

            for( int& child : adj[ cur] ) {
                temp[ child ] |= temp[ cur ] ;
                if ( --degree[ child] == 0 )
                  q.push( child ) ;
            }
        }

        for ( auto& a : queries )
            result.push_back( temp[a[1]][a[0]] ); 



        return result ;


        
    }
};