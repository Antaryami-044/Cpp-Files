#include <iostream>
#include <vector>
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



int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << "The largest element is: " << findLargest(arr) << endl;
    cout << "Hello" << endl;
    cout << "The second largest element is: " << findSecondLargest(arr) << endl;
    cout << "The second smallest element is: " << findSecondSmallest(arr) << endl;
    return 0;
}