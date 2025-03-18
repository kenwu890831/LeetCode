class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int head = 0, temp = 0, n = nums.size(), result = 0 ;
        if ( n == 1 )
            return 1 ;
        
        for ( int tail = 0 ; tail < n ; tail++ ) {
            while( (temp & nums[tail]) != 0 ) {
                temp ^= nums[head] ;
                head++ ;
            }


            temp |= nums[tail] ;
            
            result = max( result, tail - head + 1) ;
        }


        return result ;
    }
};