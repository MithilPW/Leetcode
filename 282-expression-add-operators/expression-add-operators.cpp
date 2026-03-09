class Solution {
public:
    
    void dfs(string num, int target, int pos, long curr, long prev, string path, vector<string>& res){
        
        if(pos == num.size()){
            if(curr == target)
                res.push_back(path);
            return;
        }

        for(int i = pos; i < num.size(); i++){

            if(i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i - pos + 1);
            long val = stol(part);

            if(pos == 0){
                dfs(num, target, i+1, val, val, part, res);
            }
            else{

                dfs(num, target, i+1, curr + val, val, path + "+" + part, res);

                dfs(num, target, i+1, curr - val, -val, path + "-" + part, res);

                dfs(num, target, i+1, curr - prev + prev * val, prev * val, path + "*" + part, res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
};