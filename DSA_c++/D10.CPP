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







int main() {
      int userInput;
      cin >> userInput;

      vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};

      int s1 = arr.size();

      findAllSubArray(arr, s1, userInput);

      return 0;
}