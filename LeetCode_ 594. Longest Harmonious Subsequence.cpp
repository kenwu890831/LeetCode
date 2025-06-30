class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size(), ans = 0 ;
        unordered_map< int, int > h ;
        for ( int i = 0 ; i < n ; i++ ) {
            h[nums[i]]++ ;
        }


        for ( auto& temp : h ) {
            if ( h.count( temp.first + 1 ) ) {
                ans = max( ans, temp.second + h[temp.first + 1] ) ;
            }

        }
        return ans ;
    }
};