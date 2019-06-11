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
vector<int> vec(1000010,0);
// http://www.acmsearch.com/article/show/18030
// 如果一个数n是奇数，则组成它的每个方案中必然都有1，把1减去，就和n-1的方案对应
// 如果是偶数：如果它的方案中有1，则对应n-1；如果没有1,就都是偶数，它的方案就和n/2的方案对应。
int main(){
    int N;
    cin>>N;
//    vec[1]=1;
    vec[0]=1;
    for(int i=1;i<=N;i++){
        if(i&1) vec[i]=vec[i-1];
        else vec[i]=(vec[i-1]+vec[i/2])%mod;
    }
    cout<<vec[N]<<endl;
    return 0;
}