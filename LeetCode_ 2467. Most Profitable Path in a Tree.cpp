class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size() ;
        vector< vector<int> > adj( n ) ;

        int result = INT_MIN;
        for( int i = 0 ; i < edges.size(); i++ ) {
            adj[edges[i][0]].push_back( edges[i][1] ) ;
            adj[edges[i][1]].push_back( edges[i][0] ) ;
        }

        vector< int > bobPath( n, -1 ) ;
        bobPath[ bob ] = 0 ;
        bobTrl( adj, bob, bobPath, 1 ) ;

        vector< bool > alicePath( n, false ) ;
        queue< vector<int> > q ;
        q.push( { 0, 0, 0 } ) ;
        while( !q.empty() ) {

            int cur = q.front()[0], cost = q.front()[1], time = q.front()[2] ;
            q.pop() ;
            alicePath[cur] = true ;
            if ( bobPath[cur] == -1 ) {
                cost += amount[cur] ;
            }
            else {
                
                if ( time == bobPath[cur] )
                    cost += ( amount[cur] / 2 ) ;
                else if ( time < bobPath[cur] ) {
                    cost += amount[cur] ;
                }
            }

            if( adj[cur].size() == 1 && cur != 0 )
                result = max( result, cost ) ;
            else {
                for ( int i = 0 ; i < adj[cur].size() ; i++ ) {
                    if ( !alicePath[adj[cur][i]] )
                        q.push( { adj[cur][i], cost, time+1 } ) ;
                }
            }
            
        }
        return result ;
    }


    bool bobTrl( vector<vector<int>>& adj, int place, vector< int >& path, int time ) {
        if ( place == 0 )
            return true;
        
        for ( int i = 0 ; i < adj[place].size() ; i++ ) {
            //cout << adj[place][i] << endl ;
            if ( path[ adj[place][i] ] == -1 ) {
                path[ adj[place][i] ] = time ;
                if ( bobTrl( adj, adj[place][i], path, time+1 ) )
                 return true ;
                path[ adj[place][i] ] = -1 ;
            }
            
        }

        return false ;
    }
};