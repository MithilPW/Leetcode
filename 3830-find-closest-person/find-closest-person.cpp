class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1;
        int d2;
        if(z > x){
            d1 = z-x;
        }
        else{
            d1 = x -z;
        }

   
        if(z > y){
            d2 = z -y;
        }
        else{
            d2 = y -z;
        }   

        if(d1 < d2){
            return 1;
        }
        else if(d1 == d2){
            return 0;
        }
        else{
            return 2;
        }

    }
};