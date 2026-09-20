class BrowserHistory {
    struct UrlNode {
        string url;
        UrlNode* prev;
        UrlNode* next;
        UrlNode(string u, UrlNode* p = nullptr, UrlNode* n = nullptr)
            : url(std::move(u)), prev(p), next(n) {}
    };

    UrlNode* curr;

    // Helper: delete the whole forward chain starting from `node`
    void clearForward(UrlNode* node) {
        while (node) {
            UrlNode* nxt = node->next;
            delete node;
            node = nxt;
        }
    }

public:
    BrowserHistory(string homepage) {
        curr = new UrlNode(std::move(homepage));
    }

    ~BrowserHistory() {
        // Walk back to the oldest page, then delete everything forward
        while (curr->prev) curr = curr->prev;
        clearForward(curr);
    }

    void visit(string url) {
        // Discard any existing forward history
        clearForward(curr->next);
        curr->next = nullptr;

        UrlNode* newNode = new UrlNode(std::move(url), curr);
        curr->next = newNode;
        curr = newNode;
    }

    string back(int steps) {
        while (steps > 0 && curr->prev) {
            curr = curr->prev;
            --steps;
        }
        return curr->url;
    }

    string forward(int steps) {
        while (steps > 0 && curr->next) {
            curr = curr->next;
            --steps;
        }
        return curr->url;
    }
};