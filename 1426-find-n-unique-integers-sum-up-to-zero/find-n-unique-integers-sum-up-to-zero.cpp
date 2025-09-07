class Solution {
public:
    vector<int> sumZero(int n) {
         vector<int> ans;
        if(n%2==0){
            for(int i=-n;i<=n;i+=2){
                if(i==0){
                    continue;
                }
                ans.push_back(i);
            }
        }else {
            for(int i=-n+2;i<=n-2;i+=2){
               ans.push_back(i);
            }
            ans.push_back(0);
        }
        return ans;
    }
};