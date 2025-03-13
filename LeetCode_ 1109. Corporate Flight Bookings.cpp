class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector< int > temp( n + 2 ) ;
        for ( int i = 0 ; i < bookings.size() ; i++ ) {
            int head = bookings[i][0], tail = bookings[i][1],seat = bookings[i][2] ;
            temp[head] += seat ;
            temp[tail+1] -= seat ;
        }

        vector< int > result ;
        int temp2 = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            temp2 += temp[i] ;
            result.push_back( temp2 ) ;
        }

        return result ;
    }
};