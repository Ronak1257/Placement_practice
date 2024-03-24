// pattern
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4;
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int bottom=(2*n-2)-i;
            int right=(2*n-2)-j;
            int left=j;
            cout<<n-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
    return 0;
}