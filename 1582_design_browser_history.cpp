class BrowserHistory {
public:
    stack<string> backward,forwards;
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        backward.push(url);
        while(!forwards.empty()){
            forwards.pop();
        }
    }
    
    string back(int steps) {
        while(steps>0 && backward.size()>1){
            string top = backward.top();
            backward.pop();
            forwards.push(top);
            steps--;
        }
        return backward.top();
    }
    
    string forward(int steps) {
        while(steps>0 && !forwards.empty()){
            string top = forwards.top();
            forwards.pop();
            backward.push(top);
            steps--;
        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */