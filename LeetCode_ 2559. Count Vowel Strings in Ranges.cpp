class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result ;
        vector<char> vowel = { 'a', 'e', 'i', 'o', 'u' } ;
        int temp[100005] = {0} ;
        for ( int i = 0 ; i < words.size(); i++ ) {
            bool first = false, end = false ;
            for ( int j = 0 ; j < 5 ; j++ ) {
              if ( words[i][0] == vowel[j] )
                first = true ;
              if ( words[i][words[i].size()-1] == vowel[j] )
                end = true ;
            }

            if ( first == true && end == true ) 
              temp[i+1] = temp[i] + 1 ;
            else
              temp[i+1] = temp[i] ;
        }


        for ( int i = 0 ; i < queries.size() ; i++ ) {
              int temp1 = temp[queries[i][1]+1] - temp[queries[i][0]] ;
              result.push_back( temp1 ) ;

        }

        return result ;
        
    }
};