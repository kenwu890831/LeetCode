class Solution {
public:

    bool run (int& n, vector<int>& quantities, int max ) {
      if ( max == 0 )
        return false ;
      int storeCount = 0 ;

      for ( auto x : quantities ) {
        storeCount += ( x -1 ) / max + 1 ; // ceil
        if ( storeCount > n ) 
          return false ;
      }


      return true ;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxNum = *max_element(quantities.begin(), quantities.end()), minNum = 0, result = 0  ;

        while ( minNum <= maxNum ) {
            int mid = ( maxNum + minNum ) / 2 ;
            if ( run( n, quantities, mid ) ) {
                result = mid;
                maxNum = mid - 1;
            }
            else {
                minNum = mid + 1 ;
            }
        }
        



        return result ;

    }
};