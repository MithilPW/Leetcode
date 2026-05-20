class Solution {
public:

    void Solve(int x,long long &y){

        if(x == 0){
            return;
        }

        int digit = x%10;
        y = y * 10 + digit;        
        Solve(x/10,y);


    }
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long y = 0;

        Solve(x,y);

        return x == y;
    }
};