#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

void longestSubarray(vector<int> &arr, int n, int k){
      int sum = 0;
      for(int i=0; i<n-1; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                  sum += arr[j];
                  if(sum == k){
                        cout<<i<<" "<<j<<endl;
                  }
            }
      }
}

void longestSubArr2(vector<int> &arr, int n, int k){
      long long sum = 0;
      int len = 0;
      map<long long, int> sumMap;
      for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == k){
                  len = max(len, i+1);
            }
            long long rem = sum - k;
            if(sumMap.find(rem) != sumMap.end()){
                  len = max(len, i - sumMap[rem]);
            }
            if(sumMap.find(sum) != sumMap.end()){
                  sumMap[sum] = i;
            }
      }
      cout<<len<<endl;
}

int main() {
      vector<int> arr = {2,0,0,3};
      int k = 3;
      int n = arr.size();
      longestSubarray(arr, n, k);
      longestSubArr2(arr, n, k);
      // return 0;
}