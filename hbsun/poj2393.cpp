#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include"math.h"
#include<set>
using namespace std;
vector<int> C(10010);
vector<int> Y(10010);
// �����ǰ�ܵ�����ֻ���Լ����㣬Ȼ��ȥ���������������㵽δ��ʲôʱ���Ա�֤��������
int main(){
    int N,S;
    cin>>N>>S;
    for(int n=0;n<N;n++){
        scanf("%d%d", &C[n], &Y[n]);
    }
    long long ans=0;
    int i=0;
    while(i<N){
        ans+=C[i]*Y[i];
        int j=i+1;
        while(j<N && (0ll+j-i)*S<=(0ll+C[j]-C[i])){
            ans+=(Y[j])*(0ll+C[i]+S*(j-i+0ll));
            //Y[j]=0;
            j++;
        }
        i=j;
    }
    printf("%lld\n", ans);
    return 0;
}