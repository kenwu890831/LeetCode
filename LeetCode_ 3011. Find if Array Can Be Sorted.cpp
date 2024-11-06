class Solution {
public:

    bool checkSort(vector<int>& nums) {
        for ( int i = 0 ; i < nums.size() -1 ; i++ ) {
            if ( nums[i] > nums[i+1])
              return false ;
        }

        return true ;
    }

    bool canSortArray(vector<int>& nums) {
        if ( checkSort( nums ) )
          return true ;

        int nowBit = 0, maxNum = 0, preMax = 0, minNum = 0, preMin = 0 ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            int bitTemp = __builtin_popcount( nums[i] ) ;
            if ( bitTemp != nowBit ) {
              if ( preMax > minNum ) 
                return false ;
              preMax = maxNum ;
              
              preMin = minNum ;
              nowBit = bitTemp ;
              maxNum = nums[i] ;
              minNum = nums[i] ;
            }
            else {
              maxNum = max( nums[i], maxNum) ;
              minNum = min( nums[i], minNum) ;
            }
        } // for

        return preMax < minNum  ;
    }
};