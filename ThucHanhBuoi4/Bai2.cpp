#include<bits/stdc++.h>

using namespace std;

void sapXepChai(int a[], int n){
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if(a[i]> a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(){
	int n,m;
	cout<<"Nhap so luong nuoc: ";cin>>n;
	cout<<"Nhap so chai nuoc: ";cin>>m;
	int bottle[m];
	for(int i = 0; i< m; i++){
		cin>>bottle[i];
	}
	int count = 0;
	
	sapXepChai(bottle,m);
	
	for(int i = 0; i< m; i++){
		if(bottle[i] <= n){
			count++;
			n-=bottle[i];
			cout << "Chai dung tich " << bottle[i] << " duoc do day\n";
		}
		else{
			break;
		}
	}
	cout<<"so luong chai nuoc day la: "<<count<<endl;
	
	
	return 0;
}
