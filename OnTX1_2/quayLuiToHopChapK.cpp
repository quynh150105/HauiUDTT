#include<bits/stdc++.h>

using namespace std;

void view(int a[], int k){
    for(int i = 1; i<=k; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// max: n-k + i
// min : x[i-1] + 1
void Try(int a[], int n, int k, int i){
    // duyet kha nang co the nhan
    for(int j = a[i-1] + 1; j<=n-k+i; j++ ){
            a[i] = j;
            if(i==k){
                view(a,k);
            }else{
                Try(a,n,k,i+1);
            }
    }
}

int main(){
    int a[100];
    Try(a,6,4,1);

    return 0;
}