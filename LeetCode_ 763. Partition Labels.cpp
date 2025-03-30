class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map< char , int > last ;
        vector< int > result ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            last[s[i]] = i ;
        }

        int lastIndex = -1, count = 0 ;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            count++ ;
            lastIndex = max( lastIndex, last[s[i]] ) ;
            
            if ( lastIndex == i ) {
                result.push_back( count ) ;
                count = 0 ;
            }

        }


        return result ;
    }
};