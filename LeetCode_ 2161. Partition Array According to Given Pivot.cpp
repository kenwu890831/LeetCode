class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector< int > result,large ;
        int pCount = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] < pivot ) {
                result.push_back( nums[i] ) ;
            }
            else if ( nums[i] == pivot ) {
                pCount++ ;
            }
            else {
                large.push_back( nums[i] ) ;
            }
        }

        for ( int i = 0 ; i < pCount ; i++ ) {
            result.push_back( pivot ) ;
        }

        result.insert( result.end(), large.begin(), large.end());

        return result ;
    }
};