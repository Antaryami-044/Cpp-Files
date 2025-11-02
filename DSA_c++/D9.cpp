#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &arr, int n)
{
      int idx = -1;
      for (int i = n - 2; i > 0; i--)
      {
            if (arr[i] < arr[i + 1])
            {
                  idx = i;
                  break;
            }
      }

      if (idx == -1)
      {
            reverse(arr.begin(), arr.end());
      }

      for (int i = n - 1; i > idx; i--)
      {
            if (arr[i] > arr[idx])
            {
                  swap(arr[i], arr[idx]);
                  break;
            }
      }

      reverse(arr.begin() + idx + 1, arr.end());

      for (int i = 0; i < n; i++)
      {
            cout << arr[i];
      }
}

void superiorElement(vector<int> &arr, int n)
{
      int maxi = INT16_MIN;
      vector<int> ans(0);
      for (int i = n - 1; i >= 0; i--)
      {
            if (arr[i] > maxi)
            {
                  ans.push_back(arr[i]);
            }
            maxi = max(maxi, arr[i]);
      }

      for (int i = 0; i < ans.size(); i++)
      {
            cout << ans[i] << " ";
      }
}

bool check(vector<int> &arr, int num)
{

      for (int x : arr)
      {
            if (x == num)
            {
                  return true;
            }
      }
      return false;
}

void longestElementBF(vector<int> &arr, int n)
{
      int ls = 0;
      int num;
      int count;
      for (int i = 0; i < n; i++)
      {
            num = arr[i];
            count = 1;
            while (check(arr, num + 1))
            {
                  num++;
                  count++;
            }
            ls = max(ls, count);
      }

      cout << ls << endl;
}

void longestElementB(vector<int> &arr, int n){
      int ls = 0;
      int num, count = 0;
      unordered_set<int> st;

      for(int i=0; i<n; i++){
            st.insert(arr[i]);
      }

      for(int i=0; i<n; i++){
            num = arr[i];
            count = 1;
            if(st.find(num - 1) == st.end()){
                  count = 1;
                  num = arr[i];
                  while(st.find(num + 1) != st.end()){
                        count++;
                        num++;
                  }
            }
            ls = max(ls, count);
      }
      cout << ls << endl;
}

int main()
{

      vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
      vector<int> arr2 = {10, 22, 12, 3, 0, 6};
      vector<int> arr3 = {100, 4, 200, 1, 3, 2};
      vector<int> arr4 = {5,8,4,3,2,1};

      int n = arr.size();
      int o = arr2.size();
      int p = arr3.size();
      int q = arr4.size();

      nextPermutation(arr, n);
      cout << endl;
      superiorElement(arr2, o);
      cout << endl;
      longestElementBF(arr3, p);

      longestElementB(arr4, q);

      return 0;
}