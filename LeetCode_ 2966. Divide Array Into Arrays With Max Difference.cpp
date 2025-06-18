class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort( nums.begin(), nums.end() ) ;
        vector< vector< int > > result ;
        for ( int i = 0 ; i < n - 2 ; i+=3 ) {
            if ( nums[i+1] - nums[i] <= k && nums[i+2] - nums[i] <= k && nums[i+2] - nums[i+1] <= k ) {
                    
                result.push_back( { nums[i], nums[i+1], nums[i+2] } ) ;
            }
            else{
                return {} ;
            }
        }

            
        return result ;
    }
};