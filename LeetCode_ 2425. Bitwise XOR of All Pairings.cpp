class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int temp1 = 0, temp2 = 0 ;
        if ( nums1.size() % 2 == 1 ) {
          for ( int i = 0 ; i < nums2.size() ; i++ )
            temp1 ^= nums2[i] ;
        }

        if ( nums2.size() % 2 == 1 ) {
            for ( int i = 0 ; i < nums1.size() ; i++ )
              temp2 ^= nums1[i] ;

        }
        return temp1 ^ temp2 ;
    }
};