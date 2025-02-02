class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), first = nums[0], count = 0 ;
        for ( int i = 0 ; i < n-1 ; i++ ) {
          if ( nums[i] > nums[i+1] ) {
            count++ ;
            if ( count > 1 )
              return false ;
          }
        }

        if ( nums[n-1] > first && count == 1 )
          return false ;

        return true ;
    }
};