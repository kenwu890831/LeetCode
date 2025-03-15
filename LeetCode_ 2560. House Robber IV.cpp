class Solution {
public:
    int n ;
    bool rob( vector< int > & nums, int& mid, int& k ) {
        int count = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( nums[i] <= mid ) {
                count++ ;
                i++ ; // skip
            }
        }

        return count >= k ;
    }

    int minCapability(vector<int>& nums, int k) {
        n = nums.size() ;
        int left = *min_element( nums.begin(), nums.end() ), right = *max_element( nums.begin(), nums.end() ), result = 0 ;
        while ( left <= right ) {
            int mid = left + ( right - left ) / 2 ;
            if ( rob( nums, mid, k ) ) {
                right = mid - 1 ;
                result = mid ;
            }
            else {
                left = mid + 1 ;
            }
        }

        return result ;
    }
};