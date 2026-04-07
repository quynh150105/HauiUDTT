#include<bits/stdc++.h>

using namespace std;

void view(int a[], int n){
    for(int i = 1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int a[], int n, int k){
    for(int i = 0; i<=1; i++){
        a[k] = i;
        if(k==n){
            view(a,n);
        }else{
            Try(a,n,k+1);
        }
        
    }
}


int main(){
    int n;
    cout<<"Nhap n: ";cin>>n;
    int a[100];
    Try(a,n,1);
    return 0;
}