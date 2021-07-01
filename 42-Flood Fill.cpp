#include<bits/stdc++.h>
using namespace std;

int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};
void solve(int sr,int sc,int m,int n,int newColor,vector<vector<int>>& image,int oldcolor)
{
    if(sr<0 || sc<0 || sr>=m || sc>=n || oldcolor!=image[sr][sc]){
        return;
    }
    image[sr][sc]=newColor;
    for(int i=0;i<4;i++){
         solve(sr+x[i],sc+y[i],m,n,newColor,image,oldcolor);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor){
   if(newColor==image[sr][sc]){  
            return image;
    }
    int m=image.size();
    int n=image[0].size();
    int oldcolor=image[sr][sc];
    solve(sr,sc,m,n,newColor,image,oldcolor);
    return image;
}