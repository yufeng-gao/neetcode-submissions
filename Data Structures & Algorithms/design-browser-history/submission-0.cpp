class BrowserHistory {
    struct UrlNode {
        UrlNode* prev;
        UrlNode* next;
        string url;
        UrlNode(string url, UrlNode* prev = nullptr, UrlNode* next = nullptr)
            : url(url), prev(prev), next(next){}
    };
public:
UrlNode* curr;

    BrowserHistory(string homepage) {
        UrlNode* newNode = new UrlNode(homepage);
        curr = newNode;
    }
    
    void visit(string url) {
        UrlNode* newNode = new UrlNode(url, curr);
        curr->next = newNode;
        curr = curr->next;
    }
    
    string back(int steps) {
        for (int i = 1; i<= steps; i++) {
            if (curr->prev){
                UrlNode* prev = curr->prev;
                curr = prev;
            }
            else return curr -> url;
        }
        return curr -> url;

    }
    
    string forward(int steps) {
        for (int i = 1; i<= steps; i++) {
            if (curr->next){
                UrlNode* next = curr->next;
                curr = next;
            }
            else return curr -> url;
        }
        return curr -> url;
    }
    
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */