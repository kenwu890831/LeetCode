class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long good = 0 ;
        long long n = nums.size() ;
        unordered_map< int, int > temp ;


        for ( int i = 0 ; i < n ; i++ ) {
            int k = nums[i] - i ;
            good += temp[k] ;//check same
            temp[k]++ ;
        }



        return  n * ( n - 1 ) / 2  - good ; // C n 2
    }
};