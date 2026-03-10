#include<iostream>

using namespace std;

int tong(int n){
	if(n==0){
		return n;
	} else if(n >0 ){
		return n + tong(n-1);
	}
	return -1;
}

int main(){
	/* Khai niem De quy:
	La goi lai chinh no
	Cac thanh phan:
	 + thanh phan co so: dieu kien dung cua de quy
	 + thanh phan quy nap: mo ta doi tuong
	*/
	
	/* Vi du: tong n so tu nhien dau tien
	
	*/
	
	int n;
	cin>>n;
	cout<<tong(n)<<endl;
	
	
	
	cout<<"Hello World";
	return 0;
}
