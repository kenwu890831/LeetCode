class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort( nums.begin(), nums.end() ) ;
        int n = nums.size(), result = 1, temp = nums[0] ;

        for( int i = 1 ; i < n ; i++ ) {
            if ( nums[i] - temp > k ) {
                result++ ;
                temp = nums[i] ;
            }

        }

        return result ;
    }
};