class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size() ;
        vector< int > result ;
        for ( int i = 0 ; i < n ; i++ ) {
            
            if ( i == n - 1 && nums[i] != 0 ) {
                result.push_back( nums[i] ) ;
            }
            else if ( i == n - 1 && nums[i] == 0 ) ;
            else if (  nums[i] != nums[i+1] && nums[i] != 0 ) {
                result.push_back( nums[i] ) ;
            }
            else if ( nums[i] == nums[i+1] && nums[i] != 0 ) {
                result.push_back( nums[i]*2 ) ;
                i++ ;
            }
            
        }

        while ( result.size() < n ) {
            result.push_back( 0 ) ;
        }


        return result ;
    }
};