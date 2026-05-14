#include<bits/stdc++.h>

using namespace std;

int char_in_string(char ch, string P){
    int n = P.length();
    for(int i = 0; i< n; i++){
        if(P[i] == ch) return i;
    }
    return -1;
}

bool BMH(string P, string T){
    int v = P.length();
    int i = v-1;
    while(i<T.length()){
        int k = v-1;
        while(k > -1 && T[i] == P[k]){
            i--;
            k--;
        }
        if(k < 0) return true;
        else{
            int x = char_in_string(T[i], P);
            if(x < 0) i = i + v;
            else i = i + v - x -1;
        }
    }
    return false;
}

vector<int> thamlam(int a[], int n, int &m, int c){
    vector<int> ans;

    m = 0;

    for(int i = 0; i< n; i++){
        if(m + a[i] <= c){
            m += a[i];
            ans.push_back(a[i]);
        }
    }
    return ans;
}

int main(){
    int n = 9;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int c = 15;
    string Q = "deptrai";
    string P = "quynhdeptraivocung";

    int m;
    vector<int> get = thamlam(a,n,m,c);

    int d = get.size();

    cout<<"so luong phan tu d nhieu nhat co the lay la: "<<d<<endl;
    cout<<"gia tri m la: "<<m<<endl;
    cout<<"gia tri c la: "<<c<<endl;
    cout<<"cac gia tri da lay la: "<<endl;
    for(int x : get){
        cout<<x<<" ";
    }
    cout<<endl;


    if(BMH(Q,P)){
        cout<<"chuoi Q la chuoi con cua chuoi P!"<<endl;
    }else{
        cout<<"chuoi Q khong la chuoi con cua chuoi P!"<<endl;
    }
    
    return 0;
}