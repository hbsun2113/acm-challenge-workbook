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

// 注意如果使用原数组，就要从顶向上求
int main(){
    int N;
    cin>>N;
    vector<vector<int>> vec(N+1); // 多开几个不用维持边界问题
    for(int i=1;i<=N;i++){
        vec[i].resize(i+2,0); // 多开几个不用维持边界问题
        for(int j=1;j<=i;j++){
            cin>>vec[i][j];
        }
    }

    for(int i=N-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            vec[i][j]+=max(vec[i+1][j],vec[i+1][j+1]);
        }
    }

    cout<<vec[1][1]<<endl;

    return 0;
}