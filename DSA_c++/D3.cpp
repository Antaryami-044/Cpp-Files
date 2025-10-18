#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void sort(int arr[], int l, int min, int r) {
      int n1 = min - l + 1;
      int n2 = r - min;

      int L[n1], R[n2];

      for(int i =0; i<n1; i++){
            L[i] = arr[l+i];
      }

      for(int j=0; j<n2; j++) {
            R[j] = arr[min + 1 + j];
      }

      int i =0, j=0;
      int k = l;
      while(i<n1 && j<n2){
            if(L[i] <= R[j]) {
                  arr[k++] = L[i++];
            }
            else {
                  arr[k++] = R[j++];
            }
      }

      while(i < n1) {
            arr[k++] = L[i++];
      }

      while(j < n2) {
            arr[k++] = R[j++];
      }
}

void mergesort(int arr[], int l, int r) {
      if(l >= r) {
            return;
      }

      int mid = l + (r - l) / 2;
      mergesort(arr, l , mid);
      mergesort(arr, mid+1, r);
      sort(arr, l, mid, r);
}

int partition(vector<int> &arr, int low, int high) {
      int pivot = arr[low];
      int i = low+1;
      int j = high;

      while(i <= j) {
            while(arr[i] <= pivot && i <= high){
                  i++;
            }
            while(arr[j] > pivot && j >= low+1) {
                  j--;
            }
            if(i < j) {
                  swap(arr[i], arr[j]);
            }
      }
      swap(arr[low], arr[j]);
      return j;
}

void quicksort (vector<int>& arr, int low, int high) {
      if(low < high){
            int partIndex = partition(arr, low, high);
            quicksort(arr, low, partIndex-1);
            quicksort(arr, partIndex + 1, high);
      }
}

int main() {

      vector<int> arr= {5, 2, 3, 2, 1, 8, 4, 7, 6};

      // mergesort(arr, 0, size - 1);             // we can it also using vector....

      quicksort(arr, 0, arr.size());

      for(int i=0; i< arr.size(); i++) {
            cout << arr[i] << " ";
      }
      return 0;
}