#include<iostream>
#include<unordered_map>

using namespace std;

void countNum(int array[], int n)
{
      unordered_map<int, int> mp;
      for(int i=0; i< n; i++){
            mp[array[i]] += 1;
      }
      for(auto it: mp){
            cout << it.first << " " << it.second << endl;
      }
}

void seectionSort(int arr[], int n){
      for(int i=0; i<n; i++){
            int min = i;
            for(int j=i+1; j<n; j++){
                  if(arr[j] < arr[min]){
                        min = j;
                  }
            }
            swap(arr[i], arr[min]);
      }
}

void insertionSort(int arr[], int n){
      for(int i=1; i<n; i++){
            int current = arr[i];
            int j = i-1;
            while(j >= 0 && arr[j] > current){
                  arr[j+1] = arr[j];
                  j--;
            }
            arr[j+1] = current;
      }
}

void bubbleSort(int arr[], int n){
      for(int i=0; i<n-1; i++){
            int didSwap = 0;
            for(int j=0; j<n-i-1; j++){
                  if(arr[j] > arr[j+1]){
                        swap(arr[j], arr[j+1]);
                        didSwap = 1;
                  }
            }
            if(didSwap == 0){
                  break;
            }    
      }
}

int function(int arr[], int n){
      int sum = 0;
      for(int i=0; i,n; i++){
            if(arr[i] % 2 == 0){
                  sum += arr[i];
            }
      }

      if(sum == 0){
            return 0;
      }
      return sum;
}

int main(){
      
      int arr[] = {5,24, 50, 3, 5, 24};
      int n = sizeof(arr)/sizeof(arr[0]);

      countNum(arr, n);

      seectionSort(arr, n);

      insertionSort(arr, n);

      bubbleSort(arr, n);

      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }

      return 0;
}