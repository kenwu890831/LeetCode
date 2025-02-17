class FindSumPairs {
public:
    vector< int > nums1, nums2 ;
    unordered_map< int, int > temp ; // 
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1 ;
        this -> nums2 = nums2 ;
        for ( int i = 0 ; i < nums2.size() ; i++ ) {
            temp[nums2[i]]++ ;
        }
    }

    
    void add(int index, int val) {
        temp[nums2[index]]-- ;
        nums2[index] += val ;
        temp[nums2[index]]++ ;

    }
    
    int count(int tot) {
        int result = 0 ;
        for ( int i = 0 ; i < nums1.size() ; i++ ) {
            if( temp.find(tot - nums1[i]) != temp.end() ) {
                result += temp[tot - nums1[i]] ;
            }
            
        }

        return result ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */