class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map< int, int > m ;
        vector<vector<int>> result ;
        for ( int i = 0 ; i < nums1.size() ; i++ ) {
            m[nums1[i][0]] += nums1[i][1] ;
        }

        for ( int i = 0 ; i < nums2.size() ; i++ ) {
            m[nums2[i][0]] += nums2[i][1] ;
        }

        for ( auto &temp : m ) {
            result.push_back( { temp.first, temp.second } ) ; 
        }



        return result ;
    }
};