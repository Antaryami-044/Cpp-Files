#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void shortZeroOneTwo(vector<int> &arr, int n)
{
      int low = 0, mid = 0, high = n - 1;
      while (mid <= high)
      {
            if (arr[mid] == 0)
            {
                  swap(arr[mid], arr[low]);
                  low++;
                  mid++;
            }
            else if (arr[mid] == 1)
            {
                  mid++;
            }
            else
            {
                  swap(arr[mid], arr[high]);
                  high--;
            }
      }
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
}

void majorityElement(vector<int> &arr, int n)
{
      int cnt = 0;
      int el = 0;
      for (int i = 0; i < n; i++)
      {
            if (cnt == 0)
            {
                  cnt = 1;
                  el = arr[i];
            }
            else if (arr[i] == el)
            {
                  cnt++;
            }
            else
            {
                  cnt--;
            }
      }
      int cnt1 = 0;
      for (int i = 0; i < arr.size(); i++)
      {
            if (arr[i] == el)
            {
                  cnt1++;
            }
      }
      if (cnt1 > (n / 2))
      {
            cout << el << endl;
      }
      else
      {
            cout << "No Majority Element" << endl;
      }
}

void kadensalgo(vector<int> &arr, int n){
      int sum = 0;
      int st = -1;
      int end = -1;
      int max = INT16_MIN;

      for(int i=0; i<n;i++){
            sum += arr[i];
            if(sum < 0){
                  sum = 0;
                  st = i+1;
            }

            if(sum > max){
                  max = sum;
                  end = i;
            }
      }
      cout<<"Maximum Subarray Sum is: "<<max<<endl;
      cout<<"Starting Index: "<<st<<endl;
      cout<<"Ending Index: "<<end<<endl;
}

void buysellProblem(vector<int> &arr, int n){
      int profit = 0;
      int mini = arr[0];
      for(int i=0; i<n; i++){
            profit = max(profit, arr[i]-mini);
            mini = min(mini, arr[i]);
      }
      cout<<"Maximum Profit is: "<< profit <<endl;
}

void rearrangeArray(vector<int> &arr, int n){
      vector<int> temp(n);
      int pos = 0;
      int neg = 1;
      for(int i=0; i<n; i++){
            if(arr[i] >=0){
                  temp[pos] = arr[i];
                  pos +=2;
            } else{
                  temp[neg] = arr[i];
                  neg += 2;
            }
      }
      for(int i=0; i<n; i++){
            arr[i] = temp[i];
      }
      for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
      }
}

void rearrangeArray2(vector<int> &arr, int n){
      vector<int> pos;
      vector<int> neg;
      for(int i=0; i<n; i++){
            if(arr[i] >=0){
                  pos.push_back(arr[i]);
            } else{
                  neg.push_back(arr[i]);
            }
      }
      int idx = 0;
      int pIdx = 0;
      int qIdx = 0;
      int rem = min(pos.size(), neg.size());
      while(pIdx < rem && qIdx < rem){
            arr[idx++] = pos[pIdx++];
            arr[idx++] = neg[qIdx++];
      }

      while(pIdx < pos.size()) {
            arr[idx++] = pos[pIdx++];
      } 
      
      while (qIdx < neg.size()){
      arr[idx++] = neg[qIdx++];
      }

      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }
}


int main()
{
      vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1, 0};
      vector<int> arr1 = {2, 2, 1, 1, 1, 2, 2};
      vector<int> arr2 = {-2, -3, 4, -1, -2, 1, 5, -3};
      vector<int> arr3 = {7,1,5,3,6,4};
      vector<int> arr4 = {3, -2, 5, -1, 6, -3, 2, -4};
      vector<int> arr5 = { -5, -2, -3, 4, 6, -1, 2, -4};

      int p = arr2.size();
      int n = arr.size();
      int m = arr1.size();
      int q = arr3.size();
      int r = arr4.size();
      int s = arr5.size();
      
      // shortZeroOneTwo(arr, n);
      // majorityElement(arr1, m);
      // kadensalgo(arr2, p);
      // buysellProblem(arr3, q);
      // rearrangeArray(arr4, r);
      // rearrangeArray2(arr5, s);

      return 0;
}