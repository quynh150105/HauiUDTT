#include<bits/stdc++.h>

using namespace std;

struct laptop{
    string branch;
    string config;
    int cost;
};

int char_in_string(char x, string S){
    int n = S.length();
    for(int i = 0; i < n; i++){
        if(S[i] == x) return i;
    }
    return -1;
}

int BMH(string P, string T){
    int v = P.length();
    int i = v-1;
    while(i < T.length()){
        int k = v-1;
        int j = i;
        while(k > -1 && P[k] == T[j]){
            j--,k--;
        }
        if(k < 0){
            return j + 1;
        }
        else{
            int x = char_in_string(T[j], P);
            if(x < 0) i = i + v;
            else i = i + v -x -1;
        }
    }
    return -1;
}

int main(){
    laptop ds[] = {
        {"HP"," CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 1200},
        {"Dell"," CPU 2.5GHz upto 3.5GHz-RAM 8-HDD 512GB", 1300},
        {"Acer"," CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 512GB", 1100},
        {"Asus"," CPU 2.5GHz upto 3.5GHz-RAM 32GB-SSD 512GB", 1000},
        {"SamSung"," CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 1200},
    };
    int n = 5;

    vector<int> dsRam16;
    vector<int> dsSSD;

    for(int i = 0; i< n; i++){
        if(BMH("RAM 16GB",ds[i].config) != -1){
            dsRam16.push_back(i);
        }
    }

    cout<<"So laptop Ram 16GB la: "<<dsRam16.size()<<endl;
    cout<<"Bao gom: "<<endl;
    for(int i = 0; i< dsRam16.size(); i++){
        int pos = dsRam16[i];
        cout<<"branch: "<<ds[pos].branch<<" config: "<<ds[pos].config<<" cost: "<<ds[pos].cost<<endl;
    }


    return 0;
}