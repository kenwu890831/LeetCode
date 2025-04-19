class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort( nums.begin(), nums.end() ) ;
        return lowerCount( nums, upper ) - lowerCount( nums, lower - 1 ) ;
    }

    long long lowerCount( vector<int>& nums, int temp ) {
        long long result = 0 ;
        int n = nums.size(), index = n - 1 ;
        for ( int i = 0 ; i < index ; i++ ) {
            while ( i < index && temp < nums[i] + nums[index] )
                index-- ;
            result += index - i ;
        }


        return result; 
    }
};