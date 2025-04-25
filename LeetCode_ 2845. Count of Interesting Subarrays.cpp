class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size(), pre = 0 ;
        long long result = 0 ;
        unordered_map< int , long long > temp ;
        temp[0] = 1 ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( nums[i] % modulo == k ) {
                pre++ ;
            }

            int mod = pre % modulo ;
            int target = ( mod - k + modulo ) % modulo ;
            result += temp[target] ;
            temp[mod]++ ;
        }


        return result ;
    }
};