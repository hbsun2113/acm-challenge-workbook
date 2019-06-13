#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include"math.h"
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const long long mod=1e9;

// https://github.com/hbsun2113/acm-challenge-workbook/blob/master/src/poj1742.cpp
// 注意和上面的代码 有点不同，最后没有使用for循环统计ans信息，想想为什么我这么写也可以？
// 这道题目和之前的动规不同，dp不是代表最后的答案，而是代表需要的数量，这样就可以把它和C进行对比，进而改变状态
// dp[i]代表组成i时，最少需要多少个n.
// d[i][j]表示使用前i种硬币组成总价j时，使用第i种硬币的最小数量
// 若d[i-1][j]合法，d[i][j]=0(说明不使用第i种硬币就成)
// 否则若d[i][j-Ai]<Ci(说明还可以使用第i种硬币)，d[i][j]=d[i][j-Ai]+1。滚动数组降维。
int main(){
    int N,M;
    int dp[100010];
    int a[110];
    int c[110];
    while(cin>>N>>M){
        if(N==0 && M==0) break;

        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int ans=0;
        for(int n=0;n<N;n++) cin>>a[n];
        for(int n=0;n<N;n++) cin>>c[n];

        for(int n=0;n<N;n++){
            for(int v=0;v<=M;v++){  // 注意顺序一定是由小到大。 v不可以从a[n]开始，因为dp[i]代表组成i时，最少需要多少个n。
                if(dp[v]!=-1) dp[v]=0;  // 说明不需要第n个coin参与,也可以组成v
                else{
                    if(v>=a[n] && dp[v-a[n]]!=-1 && dp[v-a[n]]<c[n]){
                        ans++;
                        dp[v]=dp[v-a[n]]+1;
                    }
                }
            }
        }

        cout<<ans<<endl;
    };

    return 0;
}




// https://www.cnblogs.com/demian/p/7355600.html
int main1(){
    int N,M;
    int dp[100010];
    int limit[100010];
    int a[110];
    int c[110];
    while(cin>>N>>M){
        if(N==0 && M==0) break;

        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int ans=0;
        for(int n=0;n<N;n++) cin>>a[n];
        for(int n=0;n<N;n++) cin>>c[n];

        for(int n=0;n<N;n++){
            memset(limit,0,sizeof(limit));
            for(int v=a[n];v<=M;v++){
                if(dp[v-a[n]]==1 && dp[v]==0 && limit[v-a[n]]<c[n]){
                    ans++;
                    dp[v]=1;
                    limit[v]=limit[v-a[n]]+1;
                }
            }
        }

        cout<<ans<<endl;
    };

    return 0;
}