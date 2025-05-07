class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size() ;
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > q ;
        vector< vector< int > > dp( m, vector<int>( n, INT_MAX )) ;
        int result = 0 ;
        q.push( { 0, 0, 0 } ) ; // count i j 
        dp[0][0] = 0 ;
        vector< vector<int> > d = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }} ;
        while( !q.empty() ) {
             vector< int > temp = q.top() ;
             q.pop() ;
             if ( temp[1] == m - 1 && temp[2] == n - 1) 
                return temp[0];

             int count = dp[temp[1]][temp[2]] ;              
             for( int i = 0 ; i < 4 ; i++ ) {
                int next_i = temp[1] + d[i][0] ;
                int next_j = temp[2] + d[i][1] ;
                if ( next_i >= 0 && next_i < m && next_j >= 0 && next_j < n ) {
                    int nextTime = max( count , moveTime[next_i][next_j]) +1;
                    if ( nextTime < dp[next_i][next_j]) {
                        dp[next_i][next_j] = nextTime;
                        q.push( { nextTime, next_i, next_j}) ;
                    }
                    
                    
                    
                }
             }

        }


        return -1 ;
    }
};