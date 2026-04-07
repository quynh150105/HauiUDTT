#include<bits/stdc++.h>

using namespace std;

// de quy
int countDeQuy(int a[], int n){
    if(n<=1) return 0;

    int count = 0;

    for(int j = 1; j< n; j ++){
            if(a[0] > a[j]){
            cout << "(" << a[0] << ", " << a[j] << ")\n";
                count++;
            }
    }
    return count + countDeQuy(a+1,n-1);
}

// chia de tri
long long merge_and_count(int a[], int l, int m, int r){
    vector<int> left(a+l,a+m+1);
    vector<int> right(a+m+1, a + r + 1);

    int i = 0, j = 0, k = l;
    long long count = 0;

    while(i < left.size() && j < right.size()){
    if(left[i] <= right[j]){
        a[k++] = left[i++];
    }
    else{
        for(int x = i; x < left.size(); x++){
            cout << "(" << left[x] << ", " << right[j] << ")\n";
        }
        count += (left.size() - i);
        a[k++] = right[j++];
    }
}
    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];

    return count;
}

long long chia_de_tri(int a[], int l, int r){
    if(l>=r) return 0;

    int m = (l + r)/2;

    long long count = 0;

    count += chia_de_tri(a,l,m);
    count += chia_de_tri(a,m+1,r);
    count += merge_and_count(a,l,m,r);

    return count;
}


int main(){

    int a[12] = {3,1,23,123,4,8,2,5,34,12,43,11};

    // cout<<countDeQuy(a,12);

    cout<<chia_de_tri(a,0,12);
    return 0;
}