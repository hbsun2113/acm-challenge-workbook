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
const int mod=1000000;  // 如果是long long 就会超时

int a[10050];
int dp[1005][10050]; // dp[i][j]代表前i种物品组成j个的方案数






// 最暴力的解法
// https://blog.csdn.net/burglarbyexplorers/article/details/23204445

// 应该是还有一个优化版本
// http://www.hankcs.com/program/cpp/poj-3046-ant-counting-problem-solution-challenge-programming-contest-2nd-edition.html
int main1(){
    int T,A,S,B;
    scanf("%d%d%d%d",&T,&A,&S,&B);
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    int t;
    for(int i=0;i<A;i++){
        scanf("%d",&t);
        a[t]++;
    }

    for(int i=0;i<=a[1];i++) dp[1][i]=1; // 这个初始化条件太特殊了

    for(int t=1;t<=T;t++){
        for(int j=0;j<=B;j++){  // 注意j要从0开始
            for(int k=0;k<=min(j,a[t]);k++){  // k代表第t个物品有k个，所以k的上界是min(j,a[t])
                dp[t][j]=(dp[t][j]+dp[t-1][j-k])%mod;
            }
        }
    }

    int ans=0;
    for(int i=S;i<=B;i++) ans=(ans+dp[T][i])%mod;
    cout<<ans<<endl;
    return 0;
}



