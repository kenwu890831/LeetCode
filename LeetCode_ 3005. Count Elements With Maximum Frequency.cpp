class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size(), res = 0, maxfrq = 0, count = 0 ;
        unordered_map< int, int > h ;

        for ( int i = 0 ; i < n ; i++ ) {
            h[nums[i]]++ ;
        }

        for ( auto& i : h ) {
            if ( i.second > maxfrq ) {
                maxfrq = i.second ;
                count = 1 ;
            }
            else if ( i.second == maxfrq ) {
                count++ ;
            }
        }

        return count*maxfrq ;
    }
};