class Solution {
public:
    bool isSafe(int newX,int newY,vector<vector<char>> &grid,map<pair<int,int> , bool> & vis){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && !vis[{newX,newY}]){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(int srcX,int srcY,vector<vector<char>> &grid,map<pair<int,int>,bool >&vis){
        queue<pair<int,int>> q;

        //initial state
        q.push({srcX,srcY});
        vis[{srcX,srcY}] = true;

        while(!q.empty()){
            pair<int,int> frontNodePair = q.front();
            q.pop();

            int tempX = frontNodePair.first;
            int tempY = frontNodePair.second;


            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i = 0;i<4;i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if(isSafe(newX,newY,grid,vis)){
                    q.push({newX,newY});
                    vis[{newX,newY}] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        map<pair<int,int>,bool> vis;
        int count = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(!vis[{i,j}] && grid[i][j] == '1'){
                    bfs(i,j,grid,vis);
                    count++;
                }
            }
        }

        return count;

    }
};