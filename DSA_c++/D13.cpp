#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void mixing(vector<int> &arr, int l, int mid, int r) {
      int n1 = mid - l + 1;
      int n2 = r - mid;

      int L[n1], R[n2];

      for(int i=0; i<n1; i++) {
            L[i] = arr[l + i];
      }
      for(int j=0; j<n2; j++) {
            R[j] = arr[mid + 1 + j];
      }

      int i=0, j=0, k=l;  
      while(i<n1 && j<n2) {
            if(L[i] <= R[j]) {
                  arr[k++] = L[i++];
            } else {
                  arr[k++] = R[j++];
            }            
      }
}

int countInverse(vector<int> &arr, int l, int mid, int r) {
      int count = 0;
      int right = mid + 1;
      for(int i=l; i<=mid; i++) {
            while(right <= r && arr[i] > 2 * arr[right]) {
                  right++;
            }
            count += (right - (mid + 1));
      }
      return count;
}

int mergesort(vector<int> &arr, int l, int r) {
      int cnt = 0;
      if(l >= r) {
            return cnt;
      }
      int mid = (l+r) / 2;
      cnt += mergesort(arr, l, mid);
      cnt += mergesort(arr, mid+1, r);
      cnt += countInverse(arr, l, mid, r);
      mixing(arr, l, mid, r);

      return cnt;
}


int main() {
      vector<int> arr = {23, 11, 5, 3};

      int n = arr.size();

      int result = mergesort(arr, 0 , n-1);

      cout << "The number of important reverse pairs are: " << result << endl;
      return 0;
}