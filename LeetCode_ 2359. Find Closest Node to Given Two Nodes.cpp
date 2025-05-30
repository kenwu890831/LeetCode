class Solution {
public:
    int closestMeetingNode( vector<int>& edges, int node1, int node2) {
        int n = edges.size(), count = 1, next1 = 0, next2 = 0, dis = INT_MAX, result = -1 ;
        vector< int > vis1( n, 0 ), vis2( n, 0 ), record1( n, -1 ), record2( n, -1 ) ;

        distance( edges, vis1, record1, node1 ) ;
        distance( edges, vis2, record2, node2 ) ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( record1[i] != -1 && record2[i] != -1 ) {
                if ( dis > record1[i] && dis > record2[i] )  {
                    dis = max ( record1[i] ,record2[i] ) ;
                    result = i ;
                }
            }
        }

        return result ; 
    }


    void distance( vector<int>& edges, vector<int>& vis, vector<int>& record, int node ) {
        int count = 0 ;
        while( node != -1 && record[node] == -1 ) {
            record[node] = count ;
            node = edges[node] ;
            count++ ;
        }

    }
};