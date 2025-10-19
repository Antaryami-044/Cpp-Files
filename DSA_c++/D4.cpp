#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLargest(vector<int> &arr)
{
    int largest = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int findSecondLargest(vector<int> &arr)
{
    int largest = INT16_MIN;
    int secondLargest = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int findSecondSmallest(vector<int> &arr)
{
    int smallest = arr[0];
    int ssmallest = INT16_MAX;
    for (auto i : arr)
    {
        if (i < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (i < ssmallest && arr[i] != smallest)
        {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

void check(vector<int> &arr)
{   
    cout << "Check function called!" << endl;

    for(int i =0; i<arr.size() - 1; i++){
        if(arr[i] <= arr[i+1]){
            continue;
        }
        else{
            cout << "Array is not sorted in non-decreasing order." << endl;
            return;
        }
    }
}

vector<int> removeDuplicates(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> temp;
    for(int i =0; i < arr.size()-1; i++) {
        if(arr[i] != arr[i+1]) {
            temp.push_back(arr[i]);
        }
    }
    return temp;
}

int main()
{
    vector<int> arr = {1, 3, 8, 7, 9, 2, 5, 6, 4, 3, 8, 1};

    cout << "The largest element is: " << findLargest(arr) << endl;

    cout << "Hello" << endl;

    cout << "The second largest element is: " << findSecondLargest(arr) << endl;

    cout << "The second smallest element is: " << findSecondSmallest(arr) << endl;
    
    check(arr);

    vector<int> uniqueArr = removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    
    for(int i = 0; i < uniqueArr.size(); i++) {
        cout << uniqueArr[i] << " ";
    }
    return 0;
}