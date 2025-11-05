#include <iostream>
#include <vector>
#include <bits/stdc++.h>            // this is contain all the STL template
#include <algorithm>                // but for better use and understanding know the differnt headerName for differnt work
using namespace std;

void findAllSubArray(vector<int> &arr, int n, int k) {
      unordered_map<int, int> m;
      m[0] = 1;
      int presum = 0;
      int count = 0;
      for(int i=0; i<n; i++) {
            presum += arr[i];
            int remain = presum - k;
            count += m[remain];
            m[presum] += 1; 
      }

      cout << count << endl;
}

vector<int> Num(int row) {
      vector<int> res;
      res.push_back(1);
      int num = 1;
      for(int i=1; i<row; i++) {
            num *= (row-i);
            num /= i;
            res.push_back(num);
      }
      return res;
}

void pascleTriangle(int row) {
      vector<vector<int>> ans;
      ans.push_back({1});
      for(int i=1; i<row; i++) {
            ans.push_back(Num(i+1));
      }

      for(auto it: ans) {
            for( auto i: it){
                  cout << i << " ";
            }
            cout << endl;
      }
}


int main() {
      int userInput;
      cin >> userInput;

      vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};

      int s1 = arr.size();

      findAllSubArray(arr, s1, userInput);
      pascleTriangle(userInput);

      return 0;
}