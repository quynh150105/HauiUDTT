#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m;

    cout << "Nhap n: ";
    cin >> n;

    vector<int> a(n + 1);

    cout << "Nhap day a: ";
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << "Nhap m: ";
    cin >> m;

    vector<int> b(m + 1);

    cout << "Nhap day b: ";
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Quy hoach dong
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Do dai day con chung dai nhat la: ";
    cout << dp[n][m] << endl;

    // Truy vet
    vector<int> c;

    int i = n;
    int j = m;

    while(i > 0 && j > 0){

        if(a[i] == b[j]){
            c.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(c.begin(), c.end());

    cout << "Day con chung dai nhat la:\n";

    for(int x : c){
        cout << x << " ";
    }

    return 0;
}