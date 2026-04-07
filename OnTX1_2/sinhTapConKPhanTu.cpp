#include<bits/stdc++.h>

using namespace std;

void view(int a[], int k){
    for(int i = 1; i<=k; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void init(int a[],int n, int k){
    for(int i = 1; i<=k; i++){
        a[i] = i;
    }
}

bool listConfig(int a[], int k, int n){
    int i = k;
    do{
        // duyet tu cuoi len dau mang
        while(i>=1 && a[i] == n-k+i){
            i--;
        }
        // cau hinh cuoi
        if(i==0) return false;
        // chua max => tang len
        a[i]++;
        // reset lai phan sau
        for(int j = i+1; j <k; j++){
            a[j] = a[j-1] + 1;
        }
        return true;
    }while(i>0);
}

int main(){
    int n = 5, k = 4;
    int a[10];
    init(a,n,k);
    do{
        view(a,k);
    }while(listConfig(a,k,n));
    return 0;
}