class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int pre = 1 , post = 1 , n = arr.size() , ans = -1e9;
        for(int i=0 ; i<n ; i++){
            if(pre == 0) pre = 1;
            if(post == 0) post = 1;
            pre *= arr[i];
            post *= arr[n - i - 1];
            ans = max(ans , max(pre , post));
            // cout<<"pre: "<<pre<<" post: "<<post<<endl;
        }
        return ans;
    }
};