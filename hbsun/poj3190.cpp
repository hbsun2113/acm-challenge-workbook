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
// ���˵��Ҳͦ���ף�https://www.cnblogs.com/demian/p/6560860.html
// �����䰴��˵���������С��ά��ÿ��ţ�������Ҷ˵����ꡣ
// ����ÿͷţ��������˵���ڶѶ�Ԫ�أ�����Բ����Ԫ�ض�Ӧ��ţ�������¶ѣ������½�ţ����
// ˵��ΪʲôҪ���¶�:��Ϊһ�������ţ������ţ�����ұ߽�ͱ��ˡ�

struct cow{
    int first,second;
    int id;
    bool operator< (const cow &other) const{
        return first<other.first;
    }
};
vector<cow> vec(50010);

int main(){
    int N;
    cin>>N;
    for(int n=0;n<N;n++){
        scanf("%d%d", &vec[n].first, &vec[n].second);
        vec[n].id=n;
    }

    sort(vec.begin(),vec.begin()+N);

    int cnt=0;
    vector<int> ans(N);
    // (�ұ߽磬id)
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    for(int n=0;n<N;n++){
        if(p.empty() || vec[n].first<=p.top().first){
            ans[vec[n].id]= ++cnt;
            p.push(make_pair(vec[n].second,vec[n].id));
        }
        else{
            ans[vec[n].id]=ans[p.top().second];
            p.pop(); // ע��Ҫ���¶�
            p.push(make_pair(vec[n].second,vec[n].id));
        }
    }

    printf("%d\n", cnt);
    for(int n=0;n<N;n++)
        printf("%d\n", ans[n]);
    return 0;
}