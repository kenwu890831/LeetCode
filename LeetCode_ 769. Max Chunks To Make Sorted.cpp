class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int now = 0, except = 0, result = 0 ;
        for ( int i = 0 ; i < arr.size() ; i++ ) {
          except += i ;
          now += arr[i] ;
          if ( except == now )
            ++result ;
        }
        return result  ;
    }
};