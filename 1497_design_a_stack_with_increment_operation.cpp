class CustomStack {
public:
    int size;
    stack<int> s1,s2;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(s1.size() < size){
            s1.push(x);
        }
    }
    
    int pop() {
        int top = -1;
        if(!s1.empty()){
            top = s1.top();
            s1.pop();
        }
        return top;
    }
    
    void increment(int k, int val) {
        if(s2.empty()){
            int k1 = max(0,(int) s1.size()-k);
            int k2 = min(k,(int) s1.size());
            while(k1 && k1>0){
                s2.push(s1.top());
                s1.pop();
                k1--;
            }
            while(k2 && k2>0){
                s2.push(val+s1.top());
                s1.pop();
                k2--;
            }
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */