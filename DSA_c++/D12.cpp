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

int main() {

      vector<int> arr = {6, 1, 5, 4, 6, 2};

      int n = arr.size();

      find_missing_Number(arr, n);
      FMN2(arr, n);

      return 0;
}