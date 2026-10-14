class Solution {
public:
    int ladderLength(string s, string e, vector<string>& arr) {
        queue<pair<string , int>> q;
        q.push({s , 1});
        unordered_set<string> st(arr.begin() , arr.end());
        st.erase(s);

        while(!q.empty()){
            string word = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(word == e) return cnt;

            for(int i=0 ; i<word.size() ; i++){
                char ch = word[i];
                for(char c='a' ; c<='z' ; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push({word , cnt + 1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }

        return 0;
    }
};