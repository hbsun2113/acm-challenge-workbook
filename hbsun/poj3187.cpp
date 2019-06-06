#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include <sstream>
#include <cstdio>
#include "math.h"
using namespace std;


int main(){
    int N,S;
    cin>>N>>S;
    vector<int> vec(N);
    for(int i=0;i<N;i++) vec[i]=i+1;
    do{
        vector<int> t1=vec;
        for(int i=N-1;i>=1;i--) {
            for (int j = 0; j < i; j++) {
                t1[j] += t1[j + 1];
            }
        }
        if(t1[0]==S) break;
    }while(next_permutation(vec.begin(),vec.end()));

    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
