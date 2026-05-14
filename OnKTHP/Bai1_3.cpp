#include<bits/stdc++.h>

using namespace std;

float tong(float a[], int n, int l, int r){
    if(l == r){
        if(a[l] >= 0) return a[l];
        return 0;
    }
   
        int m = (l + r)/2;

        float tongTrai = tong(a,n,l,m);
        float tongPhai = tong(a,n,m+1,r);
    
        return tongTrai + tongPhai;

}

int main(){ 
    int n = 10;
    float a[n] = {1.2,2.3,-4.2,5.4,-6.4,7.6,-9.7,12.1,2.1,3.2};

    float sum = tong(a,n,0,n-1);

    cout<<sum;
    return 0;
}