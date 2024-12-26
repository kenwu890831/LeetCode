class Solution {
public:
    void find( vector<int>& nums, int& target, int& result, int temp, int place ) {
        if ( place >= nums.size() ) {

            if ( temp == target )
              result++ ;


            return ;
        
        }
        else {
            find( nums, target, result, temp+nums[place], place+1 ) ;
            find( nums, target, result, temp-nums[place], place+1 ) ;
        }

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0 ;


        find( nums, target, result, 0, 0 ) ;

        return result ;
        
    }
};