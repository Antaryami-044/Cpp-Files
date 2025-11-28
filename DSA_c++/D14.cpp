#include<iostream>
#include<vector>
#include<algorithm>
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

int floorCelliProblem(vector<int> &arr, int target) {
      int low = 0, high = arr.size() - 1;
      int ans = -1;
      while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] <= target) {
                  ans = arr[mid];
                  low = mid + 1;
            }
            else {
                  high = mid - 1;
            }
      }
      return ans;
}

pair<int, int> findOccurrencesUsingBinarySearch(vector<int> &arr, int n, int target) {
      int lb = lowerBound(arr, target);
      int ub = upperBound(arr, target);
      if(lb == n || arr[lb] != target) {
            return {-1, -1};
      }
      return {lb, ub-1};
}

int main() {
      vector<int> arr = {1, 3, 3, 5, 7, 9};
      vector<int> arr2 = {1, 2, 4, 6, 8, 10};
      int target = 3;
      int target2 = 5;
      int target3 = 3;

      int index = lowerBound(arr, target);
      int index2 = upperBound(arr, target);
      int floorValue = floorCelliProblem(arr2, target2);
      pair<int, int> occurrences = findOccurrencesUsingBinarySearch(arr, arr.size(), target3);

      cout << "The lower bound index of " << target << " is: " << index << endl; 
      cout << "The upper bound index of " << target << " is: " << index2 << endl;   
      cout << "The floor value of " << target2 << " is: " << floorValue << endl;
      cout << "The first and last occurrences of " << target3 << " are: (" << occurrences.first << ", " << occurrences.second << ")" << endl;

      return 0;
}