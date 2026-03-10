#include <bits/stdc++.h>
using namespace std;

/* Phuong phap sinh
cau hinh dau tien,
cau hinh cuoi cung
phuong phap sinh

Phuong phap:
B1: <khoi tao cau hinh dau tien>
B2: while(khi chua phai cau hinh cuoi cung){
		in ra cau hinh hien tai;
		sinh ra cau hinh tiep theo; <chinh>
	}
*/

/* Vidu: Sinh xau nhi phan co do dai n

int n,k,a[100], isFinal;

void khoitao(){ // khoi tao cau hinh dau tien
	for(int i = 1; i<=n; i++){
		a[i] = 0;
	}
}

void sinh(){ // sinh day bit nhi phan
	// bat dau tu bit cuoi,va tim bit 0 dau tien
	int i = n;
	while(i>=1 && a[i]==1){
		a[i] = 0;
		--i;
	}
	if(i==0){
		isFinal = 0;
	}
	else{
		a[i] = 1;
	}
	
}

bool check(){ // check có k bit 1
	int count = 0;
	for(int i = 1; i<=n; i++){
		count+= a[i];
	}
	return count == k;
}

cin>>n>>k;
	isFinal = 1;
	khoitao();
	while(isFinal){
		if(check()){
	 		for(int i = 1; i<=n; i++){
	 			cout<<a[i];
			}
			cout<<endl;
		}
		sinh();
	}


*/

/* Vidu: sinh tổ hợp chập K của n
cấu hình khởi tạo {1,2,...k}
giới hạn max = n-k+i, a[i] chưa max -> + a[i]
giới hạn min a[i] = a[i-1] + 1;

int n,k,a[100], ok;

void khoitao(){
	for(int i = 1; i<=k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	// max i = n-K + i
	while(i >= 1 && a[i] == n-k+i){
		--i;
	}
	if(i== 0){
		ok=0;
	}
	else{
		a[i]++;
		for(int j = i+1; j<=k; j++){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	cin>>n>>k;
	ok=1;
	khoitao();
	while(ok){
		for(int i = 1; i<=k; i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
*/

/* Vidu: Sinh hoán vị
	cấu hình đầu tiên: 1..n
	cấu hình cuối: n..1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
int n,k,a[100], ok;

void khoitao(){
	for(int i = 1; i<=n; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = n-1;
	while(i>=1 && a[i] > a[i+1]){
		--i;
	}
	if(i==0){
		ok = 0;
	}
	else{
		// tim a[i] trong [i+1,n]
		int j = n;
		while(a[i] > a[j]){
			--j; 
		}
		swap(a[i],a[j]);
		int l = i+1, r =n;
		while(l<r){
			swap(a[l],a[r]);
			++l; --r;
		}
	}
}

int main(){
	cin>>n;
	ok=1;
	khoitao();
	while(ok){
		for(int i = 1; i<=n; i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
	return 0;
}
*/


int n = 6, k = 4, ok;
int a[10];

vector<string> sv = {
	"",
	"tam",
	"toan",
	"trang",
	"cong",
	"trung",
	"tu"
};

void khoitao(){
	for(int i = 1; i<=k; i++){
		a[i] =  i;
	}
}

void sinh(){
	int i = k;
	while(i>=1 && a[i] == n-k + i){
		i--;
	}
	if(i==0){
		ok = 0;
	}
	else{
		a[i]++;
		for(int j = i+1; j<=k; j++){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	ok=1;
	khoitao();
	while(ok){
		for(int i = 1; i<=n; i++){
			cout<<sv[a[i]] << " ";
		}
		cout<<endl;
		sinh();
	}
	return 0;
}
