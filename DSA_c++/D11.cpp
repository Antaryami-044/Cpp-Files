#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

void fourSum_brute(vector<int> &arr, int n, int target)
{
      set<vector<int>> st;
      for (int i = 0; i < n; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  for (int k = j + 1; k < n; k++)
                  {
                        for (int l = k + 1; l < n; l++)
                        {
                              long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                              if (sum == target)
                              {
                                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                                    sort(temp.begin(), temp.end());
                                    st.insert(temp);
                              }
                        }
                  }
            }
      }

      for (auto i : st)
      {
            for (auto j : i)
            {
                  cout << j << " ";
            }
            cout << endl;
      }
}

void fourSum_better(vector<int> &arr, int n, int target)
{
      set<vector<int>> st;
      for (int i = 0; i < n; i++)
      {
            for (int j = i + 1; j < n; j++)
            {
                  set<int> hashmap;
                  for (int k = j + 1; k < n; k++)
                  {
                        int fourth = target - (arr[i] + arr[j] + arr[k]);
                        if (hashmap.find(fourth) != hashmap.end())
                        {
                              vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                              sort(temp.begin(), temp.end());
                              st.insert(temp);
                        }
                        hashmap.insert(arr[k]);
                  }
            }
      }
      for (auto it : st)
      {
            for (auto ele : it)
            {
                  cout << ele << " ";
            }
            cout << endl;
      }
}

void fourSum_optimal(vector<int> &arr, int n, int target)
{
      vector<vector<int>> ans;
      sort(arr.begin(), arr.end());
      for (int i = 0; i < n; i++)
      {
            if (i > 0 && arr[i] == arr[i - 1])
                  continue;
            for (int j = i + 1; j < n; j++)
            {
                  if (j > i + 1 && arr[j] == arr[j - 1])
                        continue;
                  int k = j + 1;
                  int l = n - 1;
                  while (k < l)
                  {
                        long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                        if (sum == target)
                        {
                              vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                              ans.push_back(temp);
                              k++;
                              l--;
                              while (k < l && arr[k] == arr[k - 1])
                                    k++;
                              while (k < l && arr[l] == arr[l + 1])
                                    l++;
                        }
                        else if (sum < target)
                        {
                              k++;
                        }
                        else
                        {
                              l--;
                        }
                  }
            }
      }
      for (auto it : ans)
      {
            for (auto ele : it)
            {
                  cout << ele << " ";
            }
            cout << endl;
      }
}

void findSubArrayByXOR(vector<int> &arr, int n, int k)
{
      map<int, int> prefix;
      int count = 0;
      int XOR = 0;
      for (int i = 0; i < n; i++)
      {
            XOR = XOR ^ arr[i];
            if (XOR == count)
            {
                  count++;
            }
            int rem = XOR ^ k;
            if (prefix.find(rem) != prefix.end())
            {
                  count += prefix[rem];
            }
            prefix[XOR]++;
      }
      cout << count << endl;
}

void mergeoverlappingIntervals(vector<vector<int>> &arr, int n)
{
      vector<vector<int>> ans;
      sort(arr.begin(), arr.end());
      for (int i = 0; i < n; i++)
      {
            int st = arr[i][0];
            int end = arr[i][1];
            if ( !ans.empty() && end <= ans.back()[1])
            {
                  continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                  if (arr[j][0] <= end)
                  {
                        end = max(end, arr[j][1]);
                  }
                  else
                  {
                        break;
                  }
            }
            ans.push_back({st, end});
      }

      // sort(ans.begin(), ans.end());
      for(auto it: ans) {
            for(auto ele:it) {
                  cout << ele << " ";
            }
            cout << endl;
      }
}

void MOE_optimal(vector<vector<int>> &arr, int n) {
      vector<vector<int>> ans;
      sort(arr.begin(), arr.end());
      for(int i=0; i<n; i++) {
            if(ans.empty() || arr[i][0] > ans.back()[1]) {
                  ans.push_back(arr[i]);
            } else {
                  ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
      }
      for(auto it: ans) {
            for(auto ele:it) {
                  cout << ele << " ";
            }
            cout << endl;
      }
}

void merge2sorted(vector<int> &arr1, vector<int> &arr2, int n, int m) {
      vector<int> arr3;
      int i=0, j=0;
      while(i<n && j<m) {
            if(arr1[i] < arr2[j]){
                  arr3.push_back(arr1[i]);
                  i++;
            } else {
                  arr3.push_back(arr2[j]);
                  j++;
            }
      }

      while(i<n){
            arr3.push_back(arr1[i]);
            i++;
      }

      while(j<m){
            arr3.push_back(arr2[j]);
            j++;
      }

      for(auto it: arr3) {
            cout << it << " ";
      }
}

int main()
{

      vector<int> arr1 = {1, 1, -1, 0, 2, -2, 3};
      vector<int> arr2 = {2, 2, 2, 2, 2};
      vector<vector<int>> arr3 = {{4, 3}, {11, 12}, {12, 19}, {1, 5}, {8, 10}};
      vector<int> arr4 = {4, 5, 6, 7, 8};
      vector<int> arr5 = {1, 2, 3};

      int n = arr1.size();
      int m = arr3.size();
      int p = arr4.size();
      int q = arr5.size();

      // fourSum_brute(arr1, n, 4);
      // fourSum_better(arr1, n, 4);
      // fourSum_optimal(arr1, n, 4);
      // findSubArrayByXOR(arr1, n, 0);
      // mergeoverlappingIntervals(arr3, m);
      // MOE_optimal(arr3, m);
      merge2sorted(arr4, arr5, p, q);

      return 0;
}