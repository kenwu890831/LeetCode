class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;

        result.push_back( folder[0]) ;
        string last = folder[0] +"/";

        for ( int i = 1 ; i < folder.size() ; i++ ) {
        
          if ( folder[i].compare( 0, last.size(), last ) != 0 ) {
            result.push_back(folder[i]);
            last = folder[i] +"/";

          } // if
        } // for

        return result ;
    }
};