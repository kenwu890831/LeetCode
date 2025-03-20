class Solution {
public:
    vector<int> parent, minEdgeCost;

    int findParent ( int node ) {
        if ( parent [ node ] != node ) {
            parent [ node ] = findParent ( parent [ node ] ); 
        }
        return parent [ node ];
    }

    vector<int> minimumCost ( int n, vector<vector<int>> & edges, vector<vector<int>> & queries ) {
        parent.resize ( n );
        minEdgeCost.assign ( n, -1 );
        
        for ( int i = 0; i < n; i++ ) parent [ i ] = i;

        for ( auto & edge : edges ) {
            int nodeA = edge [ 0 ], nodeB = edge [ 1 ], edgeWeight = edge [ 2 ];
            int rootA = findParent ( nodeA );
            int rootB = findParent ( nodeB );

            if ( minEdgeCost [ rootA ] == -1 ) minEdgeCost [ rootA ] = edgeWeight;
            else minEdgeCost [ rootA ] &= edgeWeight;

            if ( minEdgeCost [ rootB ] == -1 ) minEdgeCost [ rootB ] = edgeWeight;
            else minEdgeCost [ rootB ] &= edgeWeight;

            if ( rootA != rootB ) {
                parent [ rootA ] = rootB;
                minEdgeCost [ rootB ] &= minEdgeCost [ rootA ];
            }
        }

        vector<int> result;
        for ( auto & query : queries ) {
            int startNode = query [ 0 ], endNode = query [ 1 ];

            if ( startNode == endNode ) result.push_back ( 0 );
            else if ( findParent ( startNode ) != findParent ( endNode ) ) result.push_back ( -1 );
            else result.push_back ( minEdgeCost [ findParent ( startNode ) ] );
        }

        return result;
    }
};
