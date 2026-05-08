#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    int left = 0;
    int right = s.length() -1;

    while(left < right){
        if(s[left]  != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string longestPalindromeCenter(string s, int k){
    int left = k;
    int right = k;

    while(left >= 0 && right <= s.length() &&s[left] == s[right]){
        left --;
        right ++;
    }

    return s.substr( left + 1, right - left -1);
}


int main(){

     string s;

    cout << "Nhap xau: ";
    getline(cin, s);

     if (isPalindrome(s)) {
        cout << "Xau doi xung\n";
    }
    else {
        cout << "Xau khong doi xung\n";

        int k;
        cout << "Nhap vi tri k: ";
        cin >> k;

        if (k < 0 || k >= s.length()) {
            cout << "Vi tri k khong hop le";
        }
        else {
            string result = longestPalindromeCenter(s, k);

            cout << "Xau con doi xung dai nhat co tam tai s[" 
                 << k << "] la: " << result;
        }
    }
    return 0;
}