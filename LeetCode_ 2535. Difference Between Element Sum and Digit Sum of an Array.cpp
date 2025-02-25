class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digit = 0, element = 0 ;
        for ( int i = 0 ; i < nums.size(); i++ ) {
            element += nums[i] ;
            while( nums[i] > 0 ) {
                digit += ( nums[i] % 10 ) ;
                nums[i] /= 10 ;
            }
        }

        return element - digit ;
    }
};