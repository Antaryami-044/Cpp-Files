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

int main()
{

      vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1, 0};
      int n = arr.size();
      // shortZeroOneTwo(arr, n);

      vector<int> arr1 = {2, 2, 1, 1, 1, 2, 2};
      int m = arr1.size();
      majorityElement(arr1, m);

      return 0;
}