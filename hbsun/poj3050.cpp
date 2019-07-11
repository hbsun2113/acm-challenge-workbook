#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include <sstream>
#include <cstdio>
#include "math.h"
#include"set"
using namespace std;


int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<vector<int>> vec(5,vector<int>(5));
// 内存和时间限制，只能使用数组，不可以使用set<string>
bool f[1000000];


void dfs(int tmp, int x, int y, int count){
    if(count==6){
        f[tmp]=true;
        return;
    }
    for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
        if(xx<0 || xx>=5 || yy<0 || yy>=5) continue;
        dfs(tmp*10+vec[xx][yy],xx,yy,count+1);
    }
}
int main(){

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>vec[i][j];

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            dfs(vec[i][j],i,j,1);

    int ans=0;
    for(int i=0;i<1000000;i++)
        if(f[i]) ans++;
    cout<<ans<<endl;

    return 0;
}
