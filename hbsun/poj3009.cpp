//#include"bits/stdc++.h"
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int sx,sy,gx,gy;
int H,W;
int ans; // 还是全局变量好使啊


void dfs(vector<vector<int>> &vec, int x, int y, int move){
    if(move>=10) return;

    for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
        if(!(xx>=0 && xx<H && yy>=0 && yy<W && vec[xx][yy]!=1)) continue;

        while(xx>=0 && xx<H && yy>=0 && yy<W && vec[xx][yy]!=1){
            if(xx==gx && yy==gy){
                ans=min(ans,move+1);
                return ;
            }
            xx+=dx[k];
            yy+=dy[k];
        }

        if(!(xx>=0 && xx<H && yy>=0 && yy<W)) continue;

        vec[xx][yy]=0;
        dfs(vec,xx-dx[k],yy-dy[k],move+1);
        vec[xx][yy]=1;
    }

    return ;
}


int main(){

    while(cin>>W>>H, W!=0&&H!=0) {
        ans=11;
        vector<vector<int>> vec(H, vector<int>(W));
        for (int h = 0; h < H; h++)
            for (int w = 0; w < W; w++)
                cin >> vec[h][w];



        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if(vec[h][w]==2){
                    sx=h,sy=w;
                }
                else if(vec[h][w]==3){
                    gx=h,gy=w;
                }
            }
        }

//        cout<<sx<<" "<<sy<<endl;
//        cout<<gx<<" "<<gy<<endl;

        dfs(vec,sx,sy,0);
        if(ans<=10) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
