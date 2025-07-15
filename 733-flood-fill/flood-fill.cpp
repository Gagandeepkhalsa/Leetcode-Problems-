class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int oldColor=image[sr][sc];
        image[sr][sc]=color;
        
        while(!q.empty()){
          auto temp=q.front();
          q.pop();
          int x[]={1,-1,0,0};
          int y[]={0,0,-1,1};

          for(int k=0;k<4;k++){
            int nx=temp.first+x[k];
            int ny=temp.second+y[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==oldColor && !visited[nx][ny]){
                visited[nx][ny]=1;
                q.push({nx,ny});
                image[nx][ny]=color;
            }
          }
        }
        return image;
    }
};