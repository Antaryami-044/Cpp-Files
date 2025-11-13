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

int main() {

      vector<int> arr = {1, 1, 3, 4, 6, 2};

      int n = arr.size();

      // find_missing_Number(arr, n);
      // FMN2(arr, n);
      FNM3(arr, n);

      return 0;
}