#include <bits/stdc++.h>

using namespace std;

string addBigNumber(string a, string b) {

    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;

    int carry = 0;

    // cộng từ phải sang trái
    while (i >= 0 || j >= 0 || carry > 0) {

        int digitA = 0;
        int digitB = 0;

        // lấy chữ số của a
        if (i >= 0) {
            digitA = a[i] - '0';
        }

        // lấy chữ số của b
        if (j >= 0) {
            digitB = b[j] - '0';
        }

        // tính tổng
        int sum = digitA + digitB + carry;

        // chữ số ghi vào kết quả
        int digit = sum % 10;

        // số nhớ
        carry = sum / 10;

        // thêm vào đầu chuỗi
        result = char(digit + '0') + result;

        i--;
        j--;
    }

    return result;
}

int main() {

    string m, n;

    cout << "Nhap m: ";
    cin >> m;

    cout << "Nhap n: ";
    cin >> n;

    string sum = addBigNumber(m, n);

    cout << "Tong = " << sum;

    return 0;
}