#include<bits/stdc++.h>

using namespace std;


void merge(vector<int>&a, int l, int m, int r){
    int i = l, j = m+1;
    vector<int> temp;
    while(i<=m && j<=r){
        if(a[i]<a[j]){
            temp.push_back(a[i]);
            i++;
        }else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=m){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(a[j]);
        j++;
    }
    for(int k = 0; k<temp.size(); k++){
        a[l+k] = temp[k];
    }
}

void mergeSort(vector<int> &a, int l, int r){
    if(l>=r) return;
    int m = (l + r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}


int main(){
    vector<int> a = {2,12,312,317,4,123,46,213,435,345};
    mergeSort(a,0,a.size()-1);
    for(int x : a){
        cout<<x<<" ";
    }
    return 0;
}