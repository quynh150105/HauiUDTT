#include<bits/stdc++.h>

using namespace std;

struct phone{
    string branch;
    int inch;
    int cost;
};


int main(){
    int s = 20;

    vector<phone> d ={
        {"apple",6,1200},
        {"xiaomi",7,1500},
        {"samsung",5,1300},
        {"realme",9,1100},
        {"poco",4,1400},
        {"oppo",2,1200},
    };

    int n = d.size();

    vector<vector<int>> dp(n+1,  vector<int>(s+1,0));

    for(int i = 1; i<= n; i++){
        for(int j= 1; j<= s; j++){
            dp[i][j] = dp[i-1][j];

            if(d[i-1].inch <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-d[i-1].inch] + d[i-1].cost);
            }

        }
    }
    cout<<"tong gia ban lon nhat la: "<<dp[n][s]<<endl;
    cout<<" bang gia tri: "<<endl;
    for(int i = 0; i<= n; i++){
        for(int j = 0; j<=s; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}