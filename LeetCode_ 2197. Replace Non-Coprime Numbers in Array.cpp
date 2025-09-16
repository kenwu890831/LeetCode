class Solution {
public:
    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> s ;

        for ( int x : nums ) {
            int cur = x ;
            while ( !s.empty() ) {
                
                int g = gcd( s.back(), cur ) ;
                if ( g == 1 ) 
                    break ;  
                cur = 1LL * s.back() / g * cur ;
                s.pop_back() ;
            }
            
            s.push_back(cur) ;
        }
        return s;
    }
};
