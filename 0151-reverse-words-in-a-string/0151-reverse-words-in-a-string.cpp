class Solution {
public:
    string reverseWords(string s) {
        vector<char> temp;
        string ans;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == ' '){
                if(i == 0) continue;
                else if(s[i - 1] == ' ') continue;
                else{
                    for(int j=temp.size() - 1 ; j>=0 ; j--){
                        ans += temp[j];
                    }
                    ans += ' ';
                }
                temp = {};
            }

            else{
                temp.push_back(s[i]);
            }
        }

        if(!temp.empty()){
            for(int j=temp.size() - 1 ; j>=0 ; j--){
                ans += temp[j];
            }
        }

        if(ans[ans.size() - 1] == ' ') ans.pop_back();
        reverse(ans.begin() , ans.end());
        return ans;
    }
};