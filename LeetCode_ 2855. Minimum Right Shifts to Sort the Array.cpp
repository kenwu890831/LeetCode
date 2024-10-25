class Solution {
public:

    bool check ( vector<int>& nums ) {
        for ( int i = 0 ; i < nums.size() -1 ; i++ ) {
            if ( nums[i] > nums[i+1])
              return false ;
        }

        return true ;

    } // check

    int minimumRightShifts(vector<int>& nums) {
        int count = 0 ;
        if ( check( nums ) )
          return 0 ;

        while ( count < nums.size() ) {
            nums.insert( nums.begin(), nums.back() ) ;
            nums.pop_back() ;
            count++ ;

            if ( check( nums ) )
              break ;
            
        }
         
        if ( count == nums.size() )
          return -1 ;
          
        return count ;
    }
};