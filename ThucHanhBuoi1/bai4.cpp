#include <bits/stdc++.h>

using namespace std;

vector<string> sv = {
	"",
	"trang",
	"cong",
	"trung",
	"binh",
	"hoang",
	"mai"
};

void next_config(int x[], int k, int i){
	x[i] += 1;
	i++;
	while(i<=k){
		x[i] = x[i-1] + 1;
		i++;
	}
}

void view_config(int x[], int k){
	for(int i = 1; i<=k; i++){
		cout<<sv[i];
	}
	cout<<endl;
}

void listing_config(int k, int n){
	int i, x[k+1] = {0};
	
	for(int i = 1; i<=k; i++){
		x[i] = i;
	}
	do{
		view_config(x,k);
		i = k;
		while(i>0 && x[i] == n-k + i){
			i--;
		}
		if(i>0 ){
			next_config(x,k,i);
		}
	}while(i>0);
}

int main(){
//	int n,k;
//	cin>>n>>k;
	
	listing_config(4,6);
	return 0;
}