#include<bits/stdc++.h>

using namespace std;


// quay lui
// void SinhNhiPhan(int k, int a[], int n){
//     for(int i = 0; i<=1; i++){
//         a[k] = i;
//         if(k==n) view(a,n);
//         else{
//             SinhNhiPhan(k+1,a,n);
//         }
//     }
// }

void view(int a[], int n){
    for(int i = 1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void next(int a[], int n, int i){
    a[i] = 1;
    i++;
    while(i<=n){
        a[i] = 0;
        i++;
    }
}

void listConfig(int n){
    int a[n+1] = {0};
    int i;
    do{
        view(a,n);
        i = n;  
        while(i>0 && a[i] == 1){
            i--;
        }
        if(i>0){
            next(a,n,i);
        }
    }while(i>0);
}

int main(){
    int n;
    cout<<"Nhap n: ";cin>>n;
    int a[100];
    listConfig(n);
    return 0;
}