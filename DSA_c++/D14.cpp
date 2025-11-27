#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int lowerBound(vector<int> &arr, int target) {
      int low = 0, high = arr.size() - 1;
      int ans = arr.size();
      while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] >= target) {
                  ans = mid;
                  high = mid - 1;
            } else {
                  low = mid + 1;
            }
      }
      return ans;
}

int upperBound(vector<int> &arr, int target) {
      int low = 0, high = arr.size() - 1;
      int ans = arr.size();
      while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] > target) {
                  ans = mid;
                  high = mid - 1;
            } else {
                  low = mid + 1;
            }
      }
      return ans;
}

int main() {
      vector<int> arr = {1, 3, 3, 5, 7, 9};
      int target = 3;

      int index = lowerBound(arr, target);
      int index2 = upperBound(arr, target);

      cout << "The lower bound index of " << target << " is: " << index << endl; 
      cout << "The upper bound index of " << target << " is: " << index2 << endl;   

      return 0;
}