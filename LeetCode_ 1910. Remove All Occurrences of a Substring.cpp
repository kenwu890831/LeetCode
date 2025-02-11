class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n1 = s.size(), n2 = part.size(), check = 0  ;
        char last = part.back() ;
        string result = "" ;


        for ( int i = 0 ; i < n1 ; i++ ) {
          result.push_back( s[i] ) ;
          if ( s[i] == last && result.size() >= n2 ) {
            //cout << result.substr( result.size() - n2 ) << endl ;
            if ( result.substr( result.size() - n2 ) == part )
                result.erase( result.size() - n2 ) ;
          }

            
          
          //cout << result << endl ;
          
        }


        return  result ;
    }
};