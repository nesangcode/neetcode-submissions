/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> v;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(v.size() >= node->val && v[node->val-1] != nullptr) return v[node->val-1];

        while(v.size() < node->val){
            v.emplace_back(nullptr);
        }
        Node* now = v[node->val-1] = new Node(node->val);
        
        for(auto &el: node->neighbors){
            now->neighbors.emplace_back(cloneGraph(el));
        }

        return now;
    }
};
