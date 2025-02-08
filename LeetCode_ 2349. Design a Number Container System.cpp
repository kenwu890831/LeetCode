class NumberContainers {
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> temp;
    unordered_map<int, int> value;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        temp[number].push( index ) ;
        value[index] = number ;
    }
    
    int find(int number) {
        while( !temp[number].empty() && value[temp[number].top()] != number ) {
            temp[number].pop() ;
        }

        return temp[number].empty() ? -1 : temp[number].top() ;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */