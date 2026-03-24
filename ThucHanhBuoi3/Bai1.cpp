#include<bits/stdc++.h>

using namespace std;

struct hocSinh{
	string ten;
	string hodem;
	int namsinh;
	string diachi;
};

bool cmp(hocSinh a, hocSinh b){
	return a.ten < b.ten;
}

void merge(vector<hocSinh>& list, int l, int m, int r){
	
	vector<hocSinh> temp;
	
	int i = l, j = m+1;
	
	while(i<=m && j<= r){
		if(cmp(list[i], list[j])){
			temp.push_back(list[i++]);
		}
		else{
			temp.push_back(list[j++]);
		}
	}
	
	while(i <= m) temp.push_back(list[i++]);
	while(j <= r) temp.push_back(list[j++]);
	
	for(int k = 0; k< temp.size(); k++){
		list[l+k] = temp[k];
	}
}

void mergeSort(vector<hocSinh>& a, int l, int r){
	if(l>=r) return;
	
	int m = (l + r)/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1, r);
	merge(a,l,m,r);
}

int binarySearch(vector<hocSinh>& a, string name){
	int l = 0, r = a.size() -1;
	while(l<=r){
		int m = (l + r)/2;
		if(a[m].ten == name) return m;
		if(a[m].ten < name) l = m+1;
		else r = m-1;
	}
	return-1;
}

int main(){
	vector<hocSinh> ds = {  
        {"Cuong", "Le Van", 2006,"ha noi"},
        {"Dung", "Pham Van", 2005,"ha noi"},
        {"Lan", "Tran Thi", 2005,"ha noi"},
        {"An", "Nguyen Van", 2005,"ha noi"},
        {"Hoa", "Nguyen Thi", 2004,"ha noi"},
        {"Binh", "Tran Van", 2004,"ha noi"}
    };
    
    mergeSort(ds, 0, ds.size() -1);
    
    for(int i = 0; i< ds.size(); i++){
    	cout<<ds[i].hodem<<" "<<ds[i].ten<<" "<<ds[i].namsinh<<" "<<ds[i].diachi<<endl;
	}
    
    string ten;
    cout<<"Nhap ten can tim: ";
    cin>> ten;
    
    int pos = binarySearch(ds,ten);
    if(pos == -1){
    	cout<<"Khong tim thay hoc sinh co ten " << ten<<endl;
	}
	else{
		cout<<"Tim thay: "<<ds[pos].hodem<<" "<<ds[pos].ten;
	}
	
	return 0;
}
