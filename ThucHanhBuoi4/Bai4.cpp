#include<bits/stdc++.h>

using namespace std;



void sapXep(int a[], int n){
	for(int i = 0; i< n-1; i++){
		int maxIndex = i;
		for(int j = i+1; j< n; j++){
			if(a[j] > a[maxIndex]){
				maxIndex = j;
			}
		}
		swap(a[i], a[maxIndex]);
	}
}

int main(){
	int n, m;
	cout<<"Nhap so xe: ";
	cin>>n;
	
	int k[n];
	
	for(int i = 0; i< n; i++){
		cin>>k[i];
	}
	cout<<"Nhap so tan hang can chuyen: ";
	cin>>m;
	
	sapXep(k,n);
	
	int sum = 0;
	int count = 0;
	
	for(int i = 0; i< n; i++){
		if(sum >= m) break;
		sum += k[i];
		cout<<k[i]<<" ";
		count++;
	}
	
	if(sum < m) {
        cout << "\nKhong du xe de cho hang!";
    } else {
        cout << "\nSo xe can dung: " << count;
    }
	return 0;
}
