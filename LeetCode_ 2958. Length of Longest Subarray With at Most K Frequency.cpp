class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int head = 0, tail = 0, ans = 0 ;
        unordered_map< int, int > m ;
        for (; tail < nums.size() ; tail++ ) {
            int temp = nums[tail] ;
            m[temp]++ ;
            if ( m[temp] > k ) {
                while( m[temp] > k ) {
                    m[nums[head]]-- ; 
                    head++ ;
                }
            }

            ans = max(ans, tail - head + 1 ) ;

        }



        return  ans ;
    }
};