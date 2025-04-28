class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size(), head = 0 ; 
        long long result = 0, sum = 0 ;

        for( int tail = 0; tail < n ; tail++ ) {
            sum += nums[tail] ;

            while( ( long long ) sum * ( tail - head + 1 ) >= k ) {
                sum -= nums[head] ;
                head++ ;
            }

            result += ( tail - head + 1 ) ;
        }

        return result ;
    }
};