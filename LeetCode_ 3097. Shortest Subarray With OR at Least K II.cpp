class Solution {
public:
    
    void countBit( vector<int>& bitCount, bitset<32> num, int c ) {
        for ( int i = 0 ; i < 32; i++ ) {
            if ( num.test( i ) ) 
              bitCount[i] += c ;
        }
    } // countBit()
     

    int bitTrans( vector<int>& bitCount ) {
      int temp = 0 ;
      for ( int i = 0 ; i < 32; i++ ) {
        if ( bitCount[i] ) 
        temp |= 1 << i ;
      }

      return temp ;
    }


    int minimumSubarrayLength(vector<int>& nums, int k) { // windows
        int size = nums.size(), result = 2000001 ;

        vector< int > bitCount( 32 ) ;

        for ( int head = 0, tail = 0; tail < size; tail++ ) {
          bitset<32> b(nums[tail]);
          countBit( bitCount, b, 1 ) ;
          while ( head <= tail && bitTrans( bitCount ) >= k ) {
            result = min( result, tail - head + 1 );
            bitset<32> b2(nums[head++]);
            countBit( bitCount, b2, -1 ) ;
          } // while


        } // for

        return result != 2000001 ? result : -1 ;

    }
};