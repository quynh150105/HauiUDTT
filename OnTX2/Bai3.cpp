#include<bits/stdc++.h>

using namespace std;
struct quat{
    string tenHang;
    string mauSac;
    int giaBan;
};

void sortByCost(vector<quat> &d){
    int size = d.size();

    for(int i = 0; i< size -1; i++){
        for(int j = i + 1; j < size; j++){
            if(d[i].giaBan < d[j].giaBan){
                swap(d[i],d[j]);
            }
        }
    }

}
int main(){
    int p; cout<<"Nhap so tien p: ";cin>>p;

    vector<quat> d = {
        {"Asia", "Den", 350000},
        {"Panasonic", "Trang", 1200000},
        {"Senko", "Xanh", 450000},
        {"Mitsubishi", "Xam", 2100000},
        {"Kangaroo", "Do", 780000},
        {"Hatari", "Hong", 950000}
    };

    sortByCost(d);

    vector<quat> lay;

    int tien = 0;

    for(int i = 0; i< d.size() -1; i++){
        lay.push_back(d[i]);
        tien += d[i].giaBan;

        if(tien > p){
            break;
        }

    }

    cout<<"can lay it nhatL "<< lay.size()<<endl;
     cout<<"Lay cac quat la: "<<endl;
    for(quat x : lay){
        cout<<"Hang san Xuat: "<< x.tenHang << " gia ban: "<<x.giaBan<<endl;
    }
  

    return 0;
}