#include<iostream>
#include<vector>
using namespace std;

void findMissingNumber(vector<int> &arr, int n){
    int sum = 0;
    for(auto it : arr){
        sum += it;
    }

    int sum2 = n * (n+1) / 2;
    int missNumber =sum2 - sum;
    cout << "Missing Number is: " << missNumber << endl;
}

void usingXOR(vector<int> &arr, int n) {
    int xor1 = 0, xor2 = 0;
    for(int i=0; i<arr.size(); i++){
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ i+1;
    }
    xor2 = xor2 ^ n; // since numbers are from 1 to n
    int missingNumber = xor1 ^ xor2;
    cout << "Missing Number using XOR is: " << missingNumber << endl;
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 6};
    int n = 6; // Since numbers are from 1 to 6
    findMissingNumber(arr, n);
    usingXOR(arr, n);
    
    return 0;
}