#include<bits/stdc++.h>

using namespace std;

int N, X[100];

void inkq(){
	for(int i = 1; i<=N; i++){
		cout<<X[i];
	}
	cout<<endl;
}

void Try(int i){
	for(int j = 0; j<=1; j++){
		X[i] = j;
		if(i==N){
			inkq();
		}
		else(Try(i+1));
	}
}

int main(){
	/* Quay lui (Back Tracking)
	*/
	
	/* vi du sinh xau nhi phan n bit
	*/
	cin>>N;
	Try(1);
	
	
	cout<<"Hello World";
	return 0;
}
