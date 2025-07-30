class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, _max = 0 ;

        for ( int head = 0, tail = 0 ; tail < n ; tail++ ) {
            while ( tail < n && nums[tail] == _max ) {
                tail++ ;
            }

            if ( tail == n || nums[tail] < _max ) {
                ans = max( ans, tail - head ) ;
                head = tail + 1 ;
            }
            else {
                _max = nums[tail] ;
                ans = 1 ;
                head = tail ;
            }
        }

        return ans ;
    }
};