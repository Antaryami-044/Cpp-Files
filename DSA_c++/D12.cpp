#include<iostream>
#include<vector>

using namespace std;

void find_missing_Number(vector<int> &arr, int n) {

      int ans[n+1] = {0};
      int missingNumber = -1;
      int repeatingNumber = -1;
      int cnt = 0;

      for(int i=0; i<n; i++) {
            ans[arr[i]]++; 
      }

      for(int i=0; i<n+1; i++) {
            if(ans[i] == 0) {
                  missingNumber = i;
            } else if(ans[i] > 1) {
                  repeatingNumber = i;
            }

            if(repeatingNumber != -1 && missingNumber != -1) {
                  break;
            }
      }

      cout << "Missing Number is: " << missingNumber << endl;
      cout << "Repeating Number is: " << repeatingNumber << endl;
}

void FMN2 (vector<int> & arr, int n) {
      long long total = (n * (n+1)) / 2;
      long long total2 = 0;

      
      long long sqTotal = (n * (n+1) * (2*n + 1)) / 6;
      long long sqTotal2 = 0;
      
      for(int i=0; i<n; i++) {
            total2 += arr[i];
            sqTotal2 += (long long) arr[i] * (long long) arr[i];
      }

      long long val1 = total - total2;
      long long val2 = sqTotal - sqTotal2;

      val2 = val2 / val1;

      long long x = (val2 + val1) / 2;
      long long y = x - val1 ;

      cout << "Missing Number is: " << int(x) << endl;
      cout << "Repeating Number is: " << int(y) << endl;
}

void FNM3(vector<int> & arr, int n) {
      int xr = 0;
      int bit = 0;
      for(int i=0; i<n; i++) {
            xr ^= arr[i];
            xr ^= (i+1);
      }
      while(true) {
            if( (xr & (1 << bit)) != 0) {
                  break;
            }
            bit++;
      }
      
      int x=0, y=0;

      for(int i=0; i<n; i++) {
            if( (arr[i] & (1 << bit)) != 0) {
                  // group 1
                  x ^= arr[i];
            } else {
                  // group 2
                  y ^= arr[i];
            }
      }

      for(int i=1; i<=n; i++) {
            if( (i & (1 << bit)) != 0) {
                  // group 1
                  x ^= i;
            } else {
                  // group 2
                  y ^= i;
            }
      }

      int cnt = 0;
      int missingNumber = 0, repeatingNumber = 0;
      for(int i=0; i<n; i++) {
            if(arr[i] == y) {
                  cnt++;
            }
      }
      if(cnt == 2) {
                  missingNumber = x;
                  repeatingNumber = y;
      } else {
                  missingNumber = y;
                  repeatingNumber = x;
      }

      cout << "Missing Number is: " << missingNumber << endl;
      cout << "Repeating Number is: " << repeatingNumber << endl;

}

int mixing(vector<int> &arr, int l, int mid, int r) {
      int  n1 = mid -l +1;
      int n2 = r - mid;

      int left[n1], right[n2];

      for(int i=0; i<n1; i++) {
            left[i] = arr[l+1];
      }

      for(int j=0; j<n2; j++) {
            right[j] = arr[mid+1+j];
      }

      int i=0, j=0, k=l;
      int cnt = 0;
      while(i<n1 && j<n2) {
            if(left[i] <= right[j]) {
                  arr[k++] = left[i++];
            } else {
                  arr[k++] = right[j++];
                  cnt += (n1 - i);
            }            
      }

      while(i <n1) {
            arr[k++] = left[i++];
      }

      while(j<n2) {
            arr[k++] = right[j++];
      }
      return cnt;
}

int mergesort(vector<int> &arr, int l, int r) {
      int cnt = 0;
      if(l >= r) {
            return cnt;
      }
      int mid = (l+r) / 2;
      cnt += mergesort(arr, l, mid);
      cnt += mergesort(arr, mid+1, r);
      cnt += mixing(arr, l, mid, r);

      return cnt;
}

int countInversions(vector<int> &arr, int n) {
      int cnt = 0;
      return mergesort(arr, 0 , n-1);
}

int main() {

      vector<int> arr = {1, 1, 3, 4, 6, 2};
      vector<int> arr2 = {1, 5, 2, 6, 3, 4};

      int n = arr.size();
      int m = arr2.size();

      // find_missing_Number(arr, n);
      // FMN2(arr, n);
      // FNM3(arr, n);
      cout << "Count of Inversions is: " << countInversions(arr2, m) << endl;

      return 0;
}