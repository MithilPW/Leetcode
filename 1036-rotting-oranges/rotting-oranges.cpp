class Solution {
public:

    bool isSafe(int newX,int newY,vector<vector<int>> temp){
        if(newX >=0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {

        //pair <int , int> -> coordinates
        //second member -> int ->time
        queue <pair<pair<int,int> , int >> q;
        vector <vector<int>> temp = grid;
        int minTime = 0;


        //find all rotten oranges and put them in queue
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(temp[i][j] == 2){
                    //every src mode ka time set karrhe h
                    q.push({{i,j} , 0});
                }
            }
        }

        //bfs logic

        while(!q.empty()){
            auto frontNodePair = q.front();
            q.pop();

            auto frontNodeCoordinates = frontNodePair.first;
            int frontNodeTime = frontNodePair.second;
            int tempX = frontNodeCoordinates.first;
            int tempY = frontNodeCoordinates.second;


            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i = 0;i<4;i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];


                if(isSafe(newX,newY,temp)){
                    q.push({{newX,newY} , frontNodeTime + 1});
                    minTime = max(minTime,frontNodeTime+1);
                    //mark this node as rotten

                    temp[newX][newY] = 2;
                }
            }
        }
        //yaha tak jitne orange rotten karne the
        //apne karliya h
        // ab i want to check k kya maine saare orange rotten kardiye?

        int freshOrangeCount = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(temp[i][j] == 1){
                    return -1;
                }
            }
        }
        return minTime;
    }
};