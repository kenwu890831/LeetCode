class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count1 = 0, count2 = 0, n = nums.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( nums[i] > 0 ) {
                count1++ ;
            }
            else if ( nums[i] < 0 ) {
                count2++ ;
            }

        }

        return max( count1, count2 ) ;
    }
};