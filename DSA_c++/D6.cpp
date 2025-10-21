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

int main(){
    vector<int> arr = {1, 2, 4, 5, 6};
    int n = 6; // Since numbers are from 1 to 6
    findMissingNumber(arr, n);
    
    return 0;
}