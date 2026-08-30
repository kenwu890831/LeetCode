class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIndex = 0, minIndex = 0, n = nums.size() ;
        if ( n == 1 ) 
            return 1 ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( nums[i] > nums[maxIndex] )
                maxIndex = i ;
            if ( nums[i] < nums[minIndex] )
                minIndex = i ;
        }

        if ( minIndex > maxIndex )
            swap( minIndex, maxIndex ) ;
        
        return min((( n - maxIndex ) + min( minIndex + 1, maxIndex - minIndex )), (( minIndex + 1 ) + min( n - maxIndex, maxIndex - minIndex ))) ;
    }
};