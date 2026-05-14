#include<bits/stdc++.h>

using namespace std;


int Tong(int a[], int l, int r){
    if(l==r){
        return a[l];
    }

    int m = (l + r)/2;

    int TongTrai = Tong(a,l,m);
    int TongPhai = Tong(a,m+1,r);

    return TongTrai + TongPhai;
}
int main(){
    int n = 10;
    int a[n] = {3,1,2,6,12,11,43,5,9,62};
    cout<<Tong(a,0,n-1)<<endl;
    cout<<"Hello World";
    return 0;
}