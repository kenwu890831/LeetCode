class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), sum = nums[0], result = nums[0] ;
        if ( n == 1 )
          return result ;
        
        for( int i = 0 ; i < n - 1 ; i++ ) {
            if ( nums[i] >= nums[i+1] ) {
              result = max( result, sum ) ;
              sum = 0 ;
            }

            sum += nums[i+1] ;
        }

        result = max( result, sum ) ;

        return result ;
    }
};