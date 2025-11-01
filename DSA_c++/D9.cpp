#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr, int n){
      int idx = -1;
      for(int i=n-2; i>0; i--) {
            if(arr[i] < arr[i+1]) {
                  idx = i;
                  break;
            }
      }

      if(idx == -1){
            reverse(arr.begin(), arr.end());
      }

      for(int i=n-1; i>idx; i--){
            if(arr[i] > arr[idx]){
                  swap(arr[i], arr[idx]);
                  break;
            }
      }

      reverse(arr.begin()+ idx + 1, arr.end());
      
      for(int i=0; i<n; i++){
            cout<<arr[i];
      }
      
}

int main() {

      vector<int> arr = {2,1,5,4,3,0,0};
      int n = arr.size();
      nextPermutation(arr, n);

      return 0;
}