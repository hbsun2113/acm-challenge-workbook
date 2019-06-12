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
int a[210];

int main(){
    int N,M;
    cin>>N>>M;
    string s;
    cin>>s;

    char c;
    int x,y;
    for(int n=0;n<N;n++){
        cin>>c>>x>>y;
        a[c]=min(x,y);
    }

    vector<vector<int>> dp(M+1, vector<int>(M+1,0));
    for(int k=2;k<=s.size();k++){ // 注意k从2开始的
        for(int i=0;i+k-1<s.size();i++){
            int j=i+k-1;
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            else{
                dp[i][j]=0x3f3f3f3f;
                dp[i][j]=min(dp[i][j], dp[i+1][j]+a[s[i]]);
                dp[i][j]=min(dp[i][j], dp[i][j-1]+a[s[j]]);
            }
        }
    }
    cout<<dp[0][s.size()-1]<<endl;
    return 0;
}