#include<bits/stdc++.h>

using namespace std;

struct item{
    float v;
    int m;
};

void sapXepTang(item ds[], int n){
    for(int i = 0; i< n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].v > ds[j].v){
                swap(ds[i],ds[j]);
            }
        }
    }
}

vector<int> thamlam(item ds[], int n, float c, float &p){
    vector<int> get;
    p = 0;
    for(int i = 0; i< n; i++){
        if(p + ds[i].v <= c){
            p += ds[i].v;
            get.push_back(i);
        }
    }
    return get;
}

int main(){
    int n = 8;
    float c = 13.2;

    item ds[8] = {
    {2.5, 10},
    {1.2, 5},
    {3.8, 15},
    {4.1, 20},
    {0.9, 3},
    {5.0, 25},
    {2.7, 12},
    {1.5, 7}
    };

    float p;
    sapXepTang(ds,n);
    vector<int> indexs = thamlam(ds,n,c,p);


    int d = indexs.size();
    cout<<"danh sach sau khi sap xep la: "<<endl;
    for(int i = 0; i< n; i++){
        cout<<"goi hang thu: "<<i <<" co gia tri: "<< ds[i].v<< " va khoi luong: "<<ds[i].m<<endl;
    }
    cout<<"gia tri c la: "<<c<<endl;
    cout<<"gia tri p la: "<<p<<endl;
    cout<<"so luong goi hang nhieu nhat co the lay la: "<<d<<endl;
    cout<<"cac goi hang da lay la: "<<endl;
    for(int x : indexs){
        cout<<"goi hang thu: "<< x + 1 <<" co gia tri: "<< ds[x].v<< " va khoi luong: "<<ds[x].m<<endl;
    }

    int M = 50;
    vector<vector<float>> dp(n+1,vector<float>(M + 1,0));

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = dp[i-1][j];
            if(ds[i-1].m <= j){
                dp[i][j] = max(dp[i][j],  dp[i-1][j-ds[i-1].m] + ds[i-1].v);
            }
        }
    }

    // for(int i= 0; i<= n; i++){
    //     for(int j = 0; j <= M; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"gia tri lon nhat la: "<<dp[n][M]<<endl;

    cout<<"cac goi hang da lay la: "<<endl;
    int j = M;
    for(int i = n; i>=1; i--){
        if(dp[i][j] != dp[i-1][j]){
            cout << "Goi hang thu " << i
                 << " co gia tri: " << ds[i - 1].v
                 << " va khoi luong: " << ds[i - 1].m
                 << endl;
            j -= ds[i-1].m;
        }
    }

    return 0;
}