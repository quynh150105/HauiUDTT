#include<bits/stdc++.h>

using namespace std;


void sapXep(string ds[], int n){
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j < n; j++){
            if(ds[i].length() < ds[j].length()){
                swap(ds[i],ds[j]);
            }
        }
    }
}



int char_in_string(char x, string S){
    int n = S.length();
    for(int i = 0; i< n; i++){
        if(S[i] == x) return i;
    }
    return -1;
}

bool BMH(string P, string T){
    int v = P.length();
    int i = v-1;
    while( i < T.length()){
        int k = v-1;
        while( k > -1 && P[k] == T[i]){
            i--,k--;
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

int main(){
    string ds[] = {
        "qweqwe",
        "qwewedsa",
        "rterchilltert",
        "tyuytu",
        "fghchillfgh"
    };

    int n = 5;

    int k;
    cout<<"Nhap chieu dai k";cin>>k;

    sapXep(ds,n);
    string ans = "";
    vector<int> get;
    for(int i = 0; i< n; i++){
        if(ans.length() + ds[i].length() <= k){
            ans += ds[i];
            get.push_back(i);
        }
    }

    cout<<"so ky tu can lay it nhat la: "<<get.size()<<" bao gom cac xau: "<<endl;
    for(int  i = 0; i< get.size(); i++){
        int index = get[i];
        cout<<ds[index]<<endl;
    }


    vector<int> pos;
    for(int i = 0; i< n; i++){
        if(BMH("chill",ds[i])){
            pos.push_back(i);
        }
    }

    cout<<"So xau xuat hien tu chill la: "<<pos.size()<<" bao gom cac xau: "<<endl;
    for(int i = 0; i< pos.size(); i++){
        int index = pos[i];
        cout<<ds[index]<<endl;
    }

    return 0;
}