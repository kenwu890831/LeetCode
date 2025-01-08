class Solution {
public:
    bool isPrefixAndSuffix(string& str1, string& str2) {
        if ( str1.size() > str2.size() )
          return false ;
        
        return ( str2.substr(0, str1.size() ) == str1 ) && ( str2.substr( str2.size() - str1.size() ) == str1 ) ;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int result = 0 ;
        for ( int i = 0 ; i < words.size()-1 ; i++ ) {
            for ( int j = i + 1 ; j < words.size() ; j++ ) {
              if ( isPrefixAndSuffix( words[i], words[j] ) ) {
                result++ ;
              }
            }
        }


        return result ;
    }
};