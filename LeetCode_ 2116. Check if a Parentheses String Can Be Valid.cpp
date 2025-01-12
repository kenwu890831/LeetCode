class Solution {
public:
    bool canBeValid(string s, string locked) {
        if ( s.size() % 2 == 1 ) 
          return false ;
        stack<int> temp, canChange ;
        
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( locked[i] == '1' ) {
                if ( s[i] == '(' ) 
                  temp.push( i ) ;
                else {
                  if ( temp.empty() ) {
                    if ( canChange.empty() )
                      return false ;
                    else {
                      canChange.pop() ;
                    }
                  }
                  else
                    temp.pop() ;
                }
                  
            }

            else {
                canChange.push( i ) ;
            }
            
        }

        while( !temp.empty() && !canChange.empty() && temp.top() < canChange.top() ) {
            temp.pop() ;
            canChange.pop() ;

        }

        if ( canChange.size() % 2 == 1 )
          return false ;

        return temp.empty() ;
        
    }
};