class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e14, mid = 0 ;
        while( left < right ) {
            mid = left + ( right - left ) / 2 ;
            if ( check( ranks, mid, cars ) ) {
                right = mid ;
            }
            else {
                left = mid + 1 ;
            }
        }


        return left ;
    }

    bool check( vector<int>& ranks, long long& mid, int& cars ) {
        long long done = 0 ;
        for ( int i = 0 ; i < ranks.size() ; i++ ) {
            long long temp = mid / ranks[i] ;
            long long carCount = floor( sqrt( temp ) ) ;
            done += carCount ;
        }

        return done >= cars ;
    }
};