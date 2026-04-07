#include<bits/stdc++.h>

using namespace std;

void view(int a[], int n ){
    for(int i = 1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void init(int a[], int n){
    for(int i = 1; i<= n; i++){
        a[i] = i;
    }
}

bool nextConfig(int a[], int n){
    int i = n-1;
    while(i>=1 && a[i] > a[i+1]){
        i--;
    }
    if(i==0) return false;
    int j = n;
    while( a[j] < a[i]){
        j--;
    }
    swap(a[i],a[j]);
    reverse(a+i+1, a+n+1);
    return  true;
}

int main(){
    int n = 3;
    int a[n+1];
    init(a,n);
    do{
        view(a,n);
    }while(nextConfig(a,n));
    return 0;
}