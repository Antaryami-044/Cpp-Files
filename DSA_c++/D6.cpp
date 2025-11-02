#include <iostream>
#include <vector>
#include<map>
using namespace std;

void findMissingNumber(vector<int> &arr, int n)
{
    int sum = 0;
    for (auto it : arr)
    {
        sum += it;
    }

    int sum2 = n * (n + 1) / 2;
    int missNumber = sum2 - sum;
    cout << "Missing Number is: " << missNumber << endl;
}

void usingXOR(vector<int> &arr, int n)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ i + 1;
    }
    xor2 = xor2 ^ n; // since numbers are from 1 to n
    int missingNumber = xor1 ^ xor2;
    cout << "Missing Number using XOR is: " << missingNumber << endl;
}

void findMaxCon(vector<int> &arr)
{
    int count = 0, maxCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxCount = max(maxCount, count);
        }
        else
        {
            count = 0;
        }
    }
    cout << "Maximum consecutive 1's are: " << maxCount << endl;
}

int findSignleOccur(vector<int> &arr)
{
    int XOR = 0;
    for (auto it : arr)
    {
        XOR = XOR ^ it;
    }
    return XOR;
}

int singleOccur(vector<int> &arr) { // second method
    map<int, int> mapArr;
    for(auto it: arr){
        mapArr[it]++;
    }
    for(auto it : mapArr){
        if(it.second == 1){
            return it.first;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6};
    vector<int> arr2 = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    vector<int> arr3 = {2, 3, 5, 4, 3, 5, 2};

    // cout << "The element occuring once is: " << findSignleOccur(arr3) << endl;

    cout << "The element occuring once is: " << singleOccur(arr3) << endl;

    findMaxCon(arr2);

    int n = 6; // Since numbers are from 1 to 6
    
    findMissingNumber(arr, n);
    usingXOR(arr, n);

    return 0;
}