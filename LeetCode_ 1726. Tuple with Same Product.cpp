class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        vector< int > temp ;
        int result = 0, n = nums.size(), walk = 0, count = 0 ;
        for ( int i = 0 ; i < n - 1 ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                temp.push_back( nums[i]* nums[j] ) ;
            }
        }

        sort( temp.begin(), temp.end() ) ;

        for ( int i = 1 ; i < temp.size() ; i++ ) {
            if ( temp[i] == temp[walk] )
              count++ ;
            else {
                if ( count > 1 )
                  result += 4*count*(count-1) ;
                walk = i ;
                count = 1 ;
            }
        }




        return result ;
    }
};