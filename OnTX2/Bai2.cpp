#include<bits/stdc++.h>

using namespace std;

struct quat{
    string hangSanXuat;
    string mauSac;
    int giaBan;
};

void sortDesByCost(vector<quat>&d){
    int n = d.size();

    for(int i = 0; i< n-1; i++){
        for(int j = i + 1; j< n; j++){
            if(d[i].giaBan < d[j].giaBan){
                swap(d[i],d[j]);
            }
        }
    }

}

vector<quat> current;
vector<quat> best;

void backtrack(int index, int tong, int p, vector<quat> &d){

      cout << "\n------------------\n";
    cout << "Index: " << index << endl;
    cout << "Tong : " << tong << endl;

    cout << "Current: ";

    for(quat x : current){
        cout << x.hangSanXuat << " ";
    }

    cout << endl;

    if(tong == p){

                cout << ">>> TIM THAY DAP AN\n";


        // chưa có đáp án hoặc hiện tại dùng ít quạt hơn 
        if(best.empty() || current.size() < best.size()){
            // cập nhật đáp án tốt nhất
            best = current;

                        cout << ">>> CAP NHAT BEST\n";

        }
        return;
    }

    // số tiền hiện tại lớn hơn tổng cần sét
    if(tong > p){
                cout << "Vuot p -> return\n";

        return;
    }

    // sét hết danh sách
    if(index >= d.size()){
                cout << "Het danh sach -> return\n";

        return;
    }

    // nếu có đáp án tốt và số quạt hiện tại còn nhiều hơn => không tối ưu
    if(!best.empty() && current.size() >= best.size()){
                cout << "Cat tia\n";

        return;
    }


      // CHỌN
    cout << "Chon: "
         << d[index].hangSanXuat
         << endl;
    // Nhánh chọn quạt hiện tại, thêm vào danh sách đang chọn
    current.push_back(d[index]);

    // đệ quy sang quạt tiếp theo
    backtrack(index + 1, tong + d[index].giaBan, p, d);

    // bỏ quạt vừa chon ra (quay lui)
     // QUAY LUI
    cout << "Quay lui: "
         << d[index].hangSanXuat
         << endl;
    current.pop_back();

     // KHÔNG CHỌN
    cout << "Khong chon: "
         << d[index].hangSanXuat
         << endl;
    // nhánh không chọn, không lấy quạt hiện tại, xét quạt tiếp
    backtrack(index + 1, tong, p, d);

}

int main(){
    int p;
    cout<<"nhap so tien P: ";cin>>p;

    
    vector<quat> d = {
        {"Asia", "Den", 350000},
        {"Panasonic", "Trang", 1200000},
        {"Senko", "Xanh", 450000},
        {"Mitsubishi", "Xam", 2100000},
        {"Kangaroo", "Do", 780000},
        {"Hatari", "Hong", 950000}
    };

    sortDesByCost(d);
   
    backtrack(0,0,p,d);

    if(best.empty()){
        cout<<"khong tim thay"<<endl;
    }
    else{
        int tong = 0;
        cout<<"danh sach cac quat la: "<<endl;
            for(quat x : best){
                cout<<"hang san xuat: "<<x.hangSanXuat<<" gia ban: "<<x.giaBan<<endl;
                tong += x.giaBan;
            }
            cout<<"tong so tien la: "<< tong;
    }

    return 0;
}