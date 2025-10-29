#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void shortZeroOneTwo(vector<int> &arr, int n)
{
      int low = 0, mid = 0, high = n - 1;
      while (mid <= high)
      {
            if (arr[mid] == 0)
            {
                  swap(arr[mid], arr[low]);
                  low++;
                  mid++;
            }
            else if (arr[mid] == 1)
            {
                  mid++;
            }
            else
            {
                  swap(arr[mid], arr[high]);
                  high--;
            }
      }
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
}

void majorityElement(vector<int> &arr, int n)
{
      int cnt = 0;
      int el = 0;
      for (int i = 0; i < n; i++)
      {
            if (cnt == 0)
            {
                  cnt = 1;
                  el = arr[i];
            }
            else if (arr[i] == el)
            {
                  cnt++;
            }
            else
            {
                  cnt--;
            }
      }
      int cnt1 = 0;
      for (int i = 0; i < arr.size(); i++)
      {
            if (arr[i] == el)
            {
                  cnt1++;
            }
      }
      if (cnt1 > (n / 2))
      {
            cout << el << endl;
      }
      else
      {
            cout << "No Majority Element" << endl;
      }
}

void kadensalgo(vector<int> &arr, int n){
      int sum = 0;
      int st = -1;
      int end = -1;
      int max = INT16_MIN;

      for(int i=0; i<n;i++){
            sum += arr[i];
            if(sum < 0){
                  sum = 0;
                  st = i+1;
            }

            if(sum > max){
                  max = sum;
                  end = i;
            }
      }
      cout<<"Maximum Subarray Sum is: "<<max<<endl;
      cout<<"Starting Index: "<<st<<endl;
      cout<<"Ending Index: "<<end<<endl;
}


int main()
{
      vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1, 0};
      vector<int> arr1 = {2, 2, 1, 1, 1, 2, 2};
      vector<int> arr2 = {-2, -3, 4, -1, -2, 1, 5, -3};

      int p = arr2.size();
      int n = arr.size();
      int m = arr1.size();
      
      shortZeroOneTwo(arr, n);
      majorityElement(arr1, m);
      kadensalgo(arr2, p);

      return 0;
}