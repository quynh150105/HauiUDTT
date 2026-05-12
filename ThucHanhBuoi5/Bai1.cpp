#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n = 6;
    int m;
    cout<<"Nhap khoi luong toi da m: ";cin>>m;
    int w[7] = {0,2,3,5,1,6,4};
    int v[7] = {0,1,5,3,2,4,6};

    int dp[n+1][100];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //  truy vet
    int j = m;
    vector<int> selected;

    for(int i = n; i>=1; i--){
        if(dp[i][j] != dp[i-1][j]){
            selected.push_back(i);
            j -=w[i];
        }
    }

    // in ket qua
    int tolW  = 0, tolV = 0;

    for(int i = selected.size() -1; i>= 0; i--){
        int index = selected[i];
        cout<<"Goi "<<index<<" - w = "<<w[index]<<" - v = "<<v[index]<<endl;
         tolW += w[index];
        tolV += v[index];
    }

    cout<<"Tong so goi: "<<selected.size()<<endl;
    cout<<"Tong khoi luong: "<<tolW<<endl;
    cout<<"Tong gia tri: "<<tolV<<endl;

    return 0;
}