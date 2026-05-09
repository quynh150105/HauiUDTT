#include<bits/stdc++.h>

using  namespace std;

struct hoiThao{
    string chuDe;
    int begin;
    int end;
};

void sapXep(hoiThao ds[], int n){
    for(int i = 0; i< n -1; i++){
        for(int j = i + 1; j< n; j++){
            if(ds[i].end > ds[j].end){
                swap(ds[i],ds[j]);
            }
        }
    }
}

int main(){ 

     // Khởi tạo danh sách hội thảo
    hoiThao ds[] = {
        {"Tim viec", 1, 3},
        {"Ky nang mem", 2, 5},
        {"AI", 4, 6},
        {"Lap trinh", 6, 8},
        {"Marketing", 5, 7}
    };

    int n = 5;

    sapXep(ds, n);

    hoiThao ketqua[100];

    int count = 0;

    //lay hoi thao dau tien
    ketqua[count++] = ds[0];
    // biến lưu thời gian kết thúc các hội thảo
    int lastEnd = ds[0].end;

    for(int i = 1; i< n; i++){
        if(ds[i].begin >= lastEnd){
            ketqua[count++] = ds[i];
            lastEnd = ds[i].end;
        }
    }

    cout<<"so hoi thao tham gia la: "<<count<<endl;

    cout<<"cac hoi thao da la: "<<endl;
    for(int i = 0; i< count; i++){
        cout<<ketqua[i].chuDe<<" begin: "<<ketqua[i].begin<<" end: "<<ketqua[i].end<<endl;
    }

   


    return 0;
}