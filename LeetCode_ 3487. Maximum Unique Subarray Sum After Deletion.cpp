class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size(), left = 0, right = 0, temp = 0 ;
        unordered_map< int, int > h ;



        while( left < n ) {
            ans = max( ans, nums[left] ) ;
            for( ; right < n ; right++ ) {
                if ( nums[right] >= 0 && h.find( nums[right] ) == 0) {
                    temp += nums[right] ;
                    
                    h[nums[right]] = 1 ;
                    ans = max( ans, temp ) ;
                }
                else {
                    right++ ;
                    break ;
                }
                    
                



            }

            h[nums[left]] = 0 ;
            left++ ;
        }



        return ans ;
    }
};