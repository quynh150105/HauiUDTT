#include<bits/stdc++.h>

using namespace std;


int char_in_string(char ch, string S){
    int x = 0;
    while(S[x] != '\0'){ // '\0' ký tự kết thúc chuỗi => duyệt đến hết chuỗi
        if(S[x]== ch) return x;
        x++;
    }
    return -1;
}

vector<int> BMH(string P, string T){
    vector<int> pos;
    int v = P.length(), i = v-1;
    while(i < T.length()){
        int k = v-1;
        int j = i;
        while(k > -1 && T[j] == P[k]){
            k--, j--;
        }
        if(k < 0) {
            pos.push_back(j + 1);
            i = i + v;
        }
        else{
            int x = char_in_string(T[i], P);
            if(x < 0) i = i + v;
            else i = i + v -x -1;
        }
    }
    return pos;
}


int main(){

    string s;
    getline(cin,s);
    string pattern = "1000";

    vector<int> poss = BMH(pattern, s);

    cout<<" so lan xuat hien: "<<poss.size()<<endl;

    string result = "";
    int i = 0;

    while(i < s.length()){
        // kiểm tra từ i còn đủ 4 ký tự ko
        // và lấy 4 ký tự bắt đầu từ i
        if(i + 3 < s.length() && s.substr(i,4) =="1000"){
            result += "mot nghin";
            i += 4;
        }
        else{
            result  += s[i];
            i++;
        }
    }
    cout<<result<<endl;
    return 0;
}