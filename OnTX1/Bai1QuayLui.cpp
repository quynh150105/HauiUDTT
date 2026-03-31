#include<bits/stdc++.h>
using namespace std;

void viewConfig(int n, int x[], char label[], string name[]){
    for(int i = 1; i <= n; i++){
        cout << label[i-1] << "-" << name[x[i]-1] << " ";
    }
    cout << endl;
}

void Try(int k, int n, int x[], int check[], char label[], string name[]){
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            x[k] = i;
            check[i] = 1;

            if(k == n){
                viewConfig(n, x, label, name);
            } else {
                Try(k+1, n, x, check, label, name);
            }

            check[i] = 0;
        }
    }
}

int main(){
    int n = 4;
    char label[] = {'A','B','C','D'};
    string name[] = {"tung","cuc","truc","mai"};

    int x[10] = {0}, check[10] = {0};
    Try(1, n, x, check, label, name);
    return 0;
}
