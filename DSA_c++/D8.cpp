#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

void shortZeroOneTwo(vector<int> &arr, int n){
      int low = 0, mid = 0, high = n-1;
      while(mid <= high){
            if(arr[mid] == 0){
                  swap(arr[mid], arr[low]);
                  low++;
                  mid++;
            } else if(arr[mid] == 1){
                  mid++;
            } else {
                  swap(arr[mid], arr[high]);
                  high--;
            }
      }
      for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
      }

}

int main() {

      vector<int> arr ={0,1,2,0,1,2,1,0,2,1,0};
      int n = arr.size();     
      shortZeroOneTwo(arr, n);
      
      return 0;
}