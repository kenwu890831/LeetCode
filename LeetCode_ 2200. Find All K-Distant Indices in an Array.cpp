class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size() ;
        vector< int > temp, ans ;// key index, result
        for( int i = 0 ; i < n ; i++ ) {
            if ( key == nums[i] )
                temp.push_back( i ) ;
        }

        for( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < temp.size() ; j++ ) {
                if ( abs( i - temp[j] ) <= k ) {
                    ans.push_back( i ) ;
                    break ;
                }
            }
        }

        return ans ;
    }
};