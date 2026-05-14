#include<bits/stdc++.h>

using namespace std;

int char_in_string(char ch, string P){
    int n = P.length();
    for(int i = 0; i< n; i++){
        if(P[i] == ch) return i;
    }
    return -1;
}

int BMH(string P, string Q){
    int v = P.size();
    int i = v-1;
    while(i< Q.length()){
        int k = v-1;
        int j = i;
        while(k > -1 && P[k] == Q[j]){
            k--;
            j--;
        }
        if(k <  0){
            return j + 1;
        }
        else{
            int x = char_in_string(Q[j],P);
            if(x < 0) i = i + v;
            else i = i + v - x -1;
        }
    }
    return -1;
}

void sapXepGiam(float a[], int n){
    for(int i = 0; i< n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

vector<float> thamlam(float a[], int n, float &m, float c){
    m = 0;
    // float tong = 0;
    vector<float> get;
    for(int i = 0; i< n; i++){
        get.push_back(a[i]);
        m += a[i];
        if(m > c){
            break;
        }
    }
    return get;
}

int main(){
    int n = 8;
    float a[n] = {1.2,2.3,4.2,5.4,6.4,7.6,9.7,12.1};
    float c = 14.5;
    string P = "quynh";
    string Q = "khong ai dep trai bang quynh ca";

    float m;
    sapXepGiam(a,n);
    vector<float> get = thamlam(a,n,m,c);

    if(get.size() > 0){
        cout<<"so luong phan tu it nhat co the lay d la: "<<get.size()<<endl;
        cout<<"gia tri m la: "<<m<<endl;
        cout<<"gia tri c la: "<<c<<endl;
        cout<<"cac phan tu da lay trong a la: "<<endl;
        for(float x : get){
            cout<<x <<" ";
        }
    }else{
        cout<<"khong co phan tu thoa man"<<endl;
    }
    cout<<endl;
    cout<<"P la: "<<P<<endl;
    cout<<"Q la: "<<Q<<endl;
    cout<<"vi tri xuat hien cua P trong Q la: "<<BMH(P,Q)<<endl;

    return 0;
}