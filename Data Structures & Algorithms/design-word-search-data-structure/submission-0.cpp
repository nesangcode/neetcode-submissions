class WordDictionary {
public:
    struct Node{
        int cnt=0;
        Node* nxt[26];
    };

    Node* head;

    WordDictionary() {
        head = new Node();        
    }
    
    void addWord(string word) {
        int itr = 0;
        Node* now = head;
        while(itr < word.size()){
            if(now->nxt[word[itr]-'a'] == nullptr){
                now->nxt[word[itr]-'a'] = new Node();
            }
            now=now->nxt[word[itr]-'a'];
            itr++;
        }
        ++(now->cnt);
    }
    
    bool search(string word) {
        stack<pair<Node*, int>> st;
        st.emplace(head, 0);

        while(!st.empty()){
            auto [now, it] = st.top();
            st.pop();
            if(it==word.size()){
                if(now->cnt>=1) return true;
                continue;
            }
            if(word[it] == '.'){
                for(int i = 0; i < 26; i++){
                    if(now->nxt[i] != nullptr){
                        st.emplace(now->nxt[i], it+1);
                    }
                }
            } else {
                if(now->nxt[word[it]-'a'] != nullptr){
                    st.emplace(now->nxt[word[it]-'a'], it+1);
                }
            }
        }
        return false;
    }
};
