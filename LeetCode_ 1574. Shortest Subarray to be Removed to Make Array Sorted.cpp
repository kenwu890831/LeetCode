class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size = arr.size() ;
        if ( size == 1 )
          return 0 ;
        int head = 0, tail = size - 1 ;
        while ( head < size -1 && arr[head] <= arr[head+1] ) {
          head++ ;
        } // while
        
        if ( head == size - 1 ) 
          return 0 ;


        while ( tail >= 1 && arr[tail] >= arr[tail-1] ) {
            tail-- ;
        } // while 

        
        int windows = min( size - head - 1, tail);
        int left = 0, right = tail ;

        while ( left <= head && right < size ) {
            if ( arr[left] <= arr[right]) {
                windows = min( windows, right - left -1 ) ;
                left++ ;
            }
            else {
                right++ ;
            }
        }
        return windows ;
    }
};