class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size() ;
        vector< int > LIS(size ,1), LDS(size ,1) ;
        for ( int i = 0 ; i < size ; i++ ) {
            for ( int j = i +1 ; j < size ; j++ ) {
              if ( nums[i] < nums[j] )
                LIS[j] = max( LIS[j], LIS[i]+1 ) ;
            }
        }

        for ( int i = size-1 ; i >= 1 ; i-- ) {
            for ( int j = i - 1 ; j >= 0 ; j-- ) {
              if ( nums[i] < nums[j] )
                LDS[j] = max( LDS[j], LDS[i]+1 ) ;
            }
        }

        int maxL = 0 ;
        for ( int i = 0 ; i < size ; i++ ) {
            if ( LIS[i] != 1 &&  LDS[i] != 1 )
              maxL = max(maxL, LIS[i] + LDS[i] - 1); ;
              
        } // 

        return size - maxL;
    }
};