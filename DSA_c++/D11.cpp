#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

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

void fourSum_better(vector<int> &arr, int n, int target) {
      set<vector<int>> st;
      for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                  set<int> hashmap;
                  for(int k=j+1; k<n; k++) {
                        int fourth =  target - (arr[i] + arr[j] + arr[k]);
                        if(hashmap.find(fourth) != hashmap.end()) {
                              vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                              sort(temp.begin(), temp.end());
                              st.insert(temp);
                        }
                        hashmap.insert(arr[k]);
                  }     
            }
      }
      for(auto it : st) {
            for(auto ele: it) {
                  cout<< ele << " ";
            }
            cout<< endl;
      } 
}

void fourSum_optimal(vector<int> &arr, int n, int target) {
      vector<vector<int>> ans;
      sort(arr.begin(), arr.end());
      for(int i=0; i<n; i++) {
            if(i>0 && arr[i]== arr[i-1]) continue;
            for(int j=i+1; j<n; j++) {
                  if(j>i+1 && arr[j] == arr[j-1]) continue;
                  int k = j+1;
                  int l = n-1;
                  while(k<l) {
                        long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                        if(sum == target) {
                              vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                              ans.push_back(temp);
                              k++;
                              l--;
                              while(k<l && arr[k] == arr[k-1]) k++;
                              while(k<l && arr[l] == arr[l+1]) l++;
                        } else if(sum < target) {
                              k++;
                        } else {
                              l--;
                        }
                  }
            }

      }
      for(auto it : ans) {
            for(auto ele: it) {
                  cout<< ele << " ";
            }
            cout<< endl;
      }
}

int main()
{

      vector<int> arr1 = {1, 1, -1, 0, 2, -2, 3};

      int n = arr1.size();

      // fourSum_brute(arr1, n, 4);
      // fourSum_better(arr1, n, 4);
      fourSum_optimal(arr1, n, 4);


      return 0;
}