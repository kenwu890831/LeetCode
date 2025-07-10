class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0, largestL = 0 ;

        vector< pair< int, int > > temp ;
        vector< int > gap ;

        for( int i = 0 ; i < n ; i++ ) {
            temp.push_back( { startTime[i], endTime[i] } ) ;
        }

        gap.push_back( temp[0].first ); // first
        for( int i = 1 ; i < n ; i++ ) {
            gap.push_back( temp[i].first - temp[i - 1].second ); 
        }

        gap.push_back( eventTime - temp[ n - 1 ].second ); // last

        vector< int > largestR( n + 1, 0 ) ;
        for ( int i = n - 1; i >= 0; i-- )
            largestR[i] = max( largestR[i + 1], gap[i + 1] ) ;

        for ( int i = 1 ; i <= n ; i++ ) {
            int duration = endTime[i - 1] - startTime[i - 1] ;
            bool canFitLeft = largestL >= duration ;
            bool canFitRight = largestR[i] >= duration ;

            if (canFitLeft || canFitRight) {
                int sum = gap[i - 1] + gap[i] + duration;
                ans = max(ans, sum ) ;
            } // find fit gap

            ans = max( ans, gap[i - 1] + gap[i] ) ; // slide move
            largestL = max( largestL, gap[i - 1] ) ;
        }




        return ans ;        
    }
};