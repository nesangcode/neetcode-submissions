class PrefixTree {
public:
    struct Node{
        int cnt=0;
        Node* nxt[26];
    };
    Node* head;

    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
        int itr = 0;
        Node* now = head;
        while(itr < word.size()){
            if(now->nxt[word[itr]-'a'] == nullptr){
                now->nxt[word[itr]-'a'] = new Node();
            }
            now=now->nxt[word[itr]-'a'];
            itr++;
        }

        (now->cnt)++;
    }
    
    bool search(string word) {
        int itr = 0;
        Node* now = head;
        while(itr < word.size()){
            if(now->nxt[word[itr]-'a'] == nullptr){
                return false;
            }
            now=now->nxt[word[itr]-'a'];
            itr++;
        }
        return now->cnt >= 1;
    }
    
    bool startsWith(string prefix) {
        int itr = 0;
        Node* now = head;
        while(itr < prefix.size()){
            if(now->nxt[prefix[itr]-'a'] == nullptr){
                return false;
            }
            now=now->nxt[prefix[itr]-'a'];
            itr++;
        }
        return true;
    }
};
