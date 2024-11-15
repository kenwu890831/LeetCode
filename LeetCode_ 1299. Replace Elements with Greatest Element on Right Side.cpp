class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result(arr.size(),-1) ;
        int maxNum = arr[arr.size() -1] ; 
        
        for ( int i = arr.size() -2 ; i >= 0 ; i-- ) {
            result[i] = maxNum ;
            maxNum = max( maxNum, arr[i] ) ;
            
        }

        return result ;
    }
};