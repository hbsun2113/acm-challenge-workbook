#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include <sstream>
#include <cstdio>
using namespace std;
vector<int> vec(15);
int ans;
int size;
vector<int> D(2); // 时间卡得特别死，它如果是局部变量，就TLE!

int v2i(int l, int r){ //[l,r)
    if(l>r) return -1;
    if(vec[l]==0 && l+1<r) return -1;
    int res=0;
    for(int i=l;i<r;i++){
        res*=10;
        res+=vec[i];
    }
    return res;
}

int main(){
    int W;
    cin>>W;
    cin.get();
    for(int w=0;w<W;w++){
        ans=1000000000;
        size=0;
        string s;
        getline(cin, s);
        stringstream ins(s);
        while(ins>>vec[size]) size++; // 竟然可以把string转化成int
        do{
            D[0]=size/2;
            D[1]=(size+1)/2; // 要么均分，要么差一个，是一个trick
            for(int d=0;d<2;d++){
                if(d==1 && D[0]==D[1]) continue;
                int a=v2i(0,D[d]);
                int b=v2i(D[d],size);
                if(a==-1 || b==-1) continue;
                ans=min(ans,abs(a-b));
            }
        }while(next_permutation(vec.begin(),vec.begin()+size));

        cout<<ans<<endl;
    }

    return 0;
}
