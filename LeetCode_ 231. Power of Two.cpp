class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> temp = n ;

        if ( n < 0 || temp.count() != 1 )
            return false ;
        return true ;
    }
};