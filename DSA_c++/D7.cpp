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

void longestSubArr3(vector<int> &arr, int n, int k){
      int left = 0, right = 0;
      int sum = 0;
      int len = 0;
      while(right < n){
            sum += arr[right];
            while(left < right && sum > k){
                  sum -= arr[left];
                  left++;
            }
            if(sum == k){
                  len = max(len, right - left + 1);
            }
            right++;
      }
      cout<<len<<endl;
}

void twoSum(vector<int> &arr, int n, int k){
      map<int, int> m;
      for(int i=0; i<n; i++){
            int r = k - arr[i];
            if(m.find(r) != m.end()){
                  // cout<< i << " " << m[r] << endl;
                  cout<< m[r] << " " << i << endl;
            } else {
                  m[arr[i]] = i;
            }
      }
}

void twoSum2(vector<int> &arr,int n, int k){
      int left = 0, right = n-1;
      while(left < right){
            int sum = arr[left] + arr[right];
            if(sum < k){
                  left++;
            } else if(sum > k){
                  right--;
            } else {
                  cout << left << " "<< right << endl;
                  // left++;
            }

      }
}

int main() {
      vector<int> arr = {2,0,0,3};
      vector<int> arr2 = {2,7,11,15};

      int k = 3;
      int k1 = 17;

      int n = arr.size();

      longestSubarray(arr, n, k);
      longestSubArr2(arr, n, k);
      longestSubArr3(arr, n, k);
      twoSum(arr2, n, k1);
      twoSum2(arr2, n, k1);

      return 0;
}