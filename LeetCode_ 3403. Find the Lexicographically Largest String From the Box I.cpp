class Solution {
public:
    string answerString(string word, int numFriends) {
        string result = "" ;
        if ( numFriends == 1 )
            return word ;
        
        for ( int i = 0 ; i < word.size() ; i++ ) {
            result = max( result, word.substr( i, word.size() - numFriends + 1 ) ) ;
        }


        return result ;
    }
};