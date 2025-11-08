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

void majorityElement_II (vector<int> &arr, int n) {

      int cnt1 = 0;
      int el1, el2;
      int cnt2 = 0;
      for(int i=0; i<n; i++) {

            if(cnt1 == 0 && arr[i] != el2) {
                  cnt1 = 1;
                  el1 = arr[i];
            } else if (cnt2 == 0 && arr[i] != el2) {
                  cnt2 = 1;
                  el2 = arr[i];
            } else if(el1 == arr[i]) {
                  cnt1++;
            } else if(el2 == arr[i]) {
                  cnt2++;
            } else {
                  cnt1--;
                  cnt2--;
            }
      }

      int c1 = 0;
      int c2 = 0;

      for(int i=0; i<n; i++) {
            if(el1 == arr[i]) {
                  c1++;
            } 
            if( el2 == arr[i]) {
                  c2++;
            }
      }

      if(c1 > (n/3)) {
            cout << el1 << endl;
      }
      if(c2 > (n/3)) {
            cout << el2 << endl;
      }
}

void ThreeSum_brute(vector<int> arr, int n) {

      vector<vector<int>> result;
      int pos = 0;
      for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++) {
                  for(int k=j+1; k<n; k++) {
                        if(arr[i] + arr[j] + arr[k] == 0) {
                              result[pos] = {arr[i], arr[j], arr[k]};
                              pos++;
                        }
                  }
            }
      }

      for(auto it: result) {
            for(auto it2: it) {
                  cout << it2 << " ";
            }
            cout << endl;
      }
}

void ThreeSum_better(vector<int> arr, int n) {

      vector<vector<int>> result;
      set<vector<int>> ans;
      int k = n-1;

      for(int i=0; i<n; i++) {
            set<int> hash;
            for(int j=i+1; j<n; j++) {
                  int sum = -(arr[i] + arr[j]);
                  if(hash.find((sum)) != hash.end()) {
                        vector<int> temp = {arr[i], arr[j], sum};
                        sort(temp.begin(), temp.end());
                        result.push_back(temp);
                  }
                  hash.insert(arr[j]);
            }
      }


      for(auto it: result) {
            for(auto it2: it) {
                  cout << it2 << " ";
            }
            cout << endl;
      }
}

int main() {
      int userInput;
      // cin >> userInput;

      vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
      vector<int> arr2 = {1,1,1,1,2,3,3,3,3};
      vector<int> arr3 = {-1,0,1,2,-1,-4};

      int s1 = arr.size();

      // findAllSubArray(arr, s1, userInput);
      // pascleTriangle(userInput);
      // majorityElement_II(arr2, arr2.size());
      // ThreeSum_brute(arr3,arr3.size());
      ThreeSum_better(arr3,arr3.size());

      return 0;
}