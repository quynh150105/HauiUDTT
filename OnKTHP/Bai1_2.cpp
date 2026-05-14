#include<bits/stdc++.h>

using namespace std;

int tongLe(int a[], int n){
    if(n==0) return 0;

    if(a[n-1] % 2!=0){
        return a[n-1] + tongLe(a,n-1);
    }

    return tongLe(a,n-1);

}

int main(){
    int a[] = {1,2,3,4,5,6};
    int n = 6;
    int tong = tongLe(a,n);
    cout<<"tong le la: "<<tong<<endl;
    return 0;
}