class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, temp = nums[0], check = -1 ;
        for ( int i = 1 ; i < nums.size() ; i++ ){
            while ( i < nums.size() && nums[i] == temp ) {
                nums.erase( nums.begin() + i ) ;
            }

            temp = nums[i] ;
        }


        for ( int i = 1 ; i < nums.size() - 1 ; i++ ){
            if ( check != 0 && nums[i-1] > nums[i] && nums[i+1] > nums[i] ) {
                check = 0 ;
                ans++ ;
            }
            else if ( check != 1 &&nums[i-1] < nums[i] && nums[i+1] < nums[i] ) {
                check = 1 ;
                ans++ ;
            }
        }




        return ans ;
    }
};