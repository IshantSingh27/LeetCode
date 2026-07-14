struct Node{
    Node *links[26];
    bool flag = false;
    bool contains(char c){
        return links[c - 'a'] != NULL;
    }
    void put(char c , Node* node){
        links[c - 'a'] = node;
    }
    Node* get(char c){
        return links[c - 'a'];
    }
    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* node = root;
        int n = s.size();
        for(int i=0 ; i<n ; i++){
            if(!node->contains(s[i])){
                node->put(s[i] , new Node());
            }
            node = node->get(s[i]);
        }
        node->setend();
    }
    
    bool search(string s) {
        int n = s.size();
        Node* node = root;
        for(int i=0 ; i<n ; i++){
            if(!node->contains(s[i])) return false;
            node = node->get(s[i]);
        }
        return node->isend();
    }
    
    bool startsWith(string s) {
        int n = s.size();
        Node* node = root;
        for(int i=0 ; i<n ; i++){
            if(!node->contains(s[i])) return false;
            node = node->get(s[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */