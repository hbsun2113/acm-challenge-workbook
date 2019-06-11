#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include"math.h"
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const long long mod=1e9;

// 这道题目感觉理解得不是很透彻
int main(){
    int T,W;
    cin>>T>>W;
    vector<vector<int>> dp(T+1,vector<int>(W+1,0)); // dp[i][j]代表是时间t时，经过了j次转换，能拿到的最大值
    vector<int> vec(T+1);
    for(int t=1;t<=T;t++){
        cin>>vec[t];
        dp[t][0]=dp[t-1][0]+(vec[t]==1); // 若转移数为0，那么i时刻内得到的苹果是第一棵树掉落的苹果总数
    }

    //for(int i=1;i<=W;i++) dp[1][i]=1;  // 转移一次以上，那么第一分钟内的都可以得到1个苹果

    for(int t=1;t<=T;t++){
        for(int w=1;w<=W;w++){  // vec[t]==w%2+1是当前能不能得到这个苹果。 w%2+1是看当前转移了w次后在哪棵树下
            int move=dp[t-1][w]+(vec[t]==w%2+1);  // 没有经过转换，到达了该树
            int not_move=dp[t-1][w-1]+(vec[t]==w%2+1); // 经过转换到达了该树
            dp[t][w]=max(move,not_move);
        }
    }

    // 背包：因为初始化为0，所以最大值肯定在末尾
    cout<<dp[T][W]<<endl;
    return 0;
}