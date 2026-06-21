class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0, tail = s.size() - 1 ;
        while ( head < tail ) {
            if ( s[head] == ' ' || check( s[head]) ) {
                head++ ;
                continue ;
            }

            if ( s[tail] == ' ' || check( s[tail]) ) {
                tail-- ;
                continue ;
            }

            if ( s[head] >= 65 && s[head] <= 90 )
                s[head] += 32 ;
            if ( s[tail] >= 65 && s[tail] <= 90 )
                s[tail] += 32 ;

            if ( s[head] != s[tail] )
                return false ;
            else {
                head++, tail-- ;
            }
        }

        return true ;
    }

    bool check( char input ) {
        if ( input >= 'A' && input <= 'Z' )
            return false ;
        else if ( input >= 'a' && input <= 'z' )
            return false ;
        else if ( input >= '0' && input <= '9' )
            return false ;

        return true ;
    }
};