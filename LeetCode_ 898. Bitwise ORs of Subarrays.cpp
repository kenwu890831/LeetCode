class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set< int > ans, pre, cur ;
        for ( int i = 0 ; i < arr.size() ; i++ ) {
            
            cur.insert( arr[i] ) ;
            for ( int x : pre ) {
                cur.insert( arr[i] | x ) ;
            }

            pre = cur ;
            ans.insert( cur.begin(), cur.end() ) ;
            cur.clear() ;
            
        }

        return ans.size() ;
    }
};