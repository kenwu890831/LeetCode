class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0 ;

        vector< int > temp ;
        int start = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            temp.push_back( startTime[i] - start ) ;
            start = endTime[i] ;
        }

        temp.push_back( eventTime - start ) ;

        int sum = 0 ;
        for ( int i = 0 ; i <= k ; i++ ) {
            sum += temp[i] ;
        }

        ans = max( ans, sum ) ;

        int head = 0, tail = k ;
        while( tail < n ) {
            sum -= temp[head++] ;
            sum += temp[++tail] ;
            ans = max( ans, sum ) ;
        }





        return ans ;
    }
};