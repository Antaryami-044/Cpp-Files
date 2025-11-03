#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &arr, int n)
{
      int idx = -1;
      for (int i = n - 2; i > 0; i--)
      {
            if (arr[i] < arr[i + 1])
            {
                  idx = i;
                  break;
            }
      }

      if (idx == -1)
      {
            reverse(arr.begin(), arr.end());
      }

      for (int i = n - 1; i > idx; i--)
      {
            if (arr[i] > arr[idx])
            {
                  swap(arr[i], arr[idx]);
                  break;
            }
      }

      reverse(arr.begin() + idx + 1, arr.end());

      for (int i = 0; i < n; i++)
      {
            cout << arr[i];
      }
}

void superiorElement(vector<int> &arr, int n)
{
      int maxi = INT16_MIN;
      vector<int> ans(0);
      for (int i = n - 1; i >= 0; i--)
      {
            if (arr[i] > maxi)
            {
                  ans.push_back(arr[i]);
            }
            maxi = max(maxi, arr[i]);
      }

      for (int i = 0; i < ans.size(); i++)
      {
            cout << ans[i] << " ";
      }
}

bool check(vector<int> &arr, int num)
{

      for (int x : arr)
      {
            if (x == num)
            {
                  return true;
            }
      }
      return false;
}

void longestElementBF(vector<int> &arr, int n)
{
      int ls = 0;
      int num;
      int count;
      for (int i = 0; i < n; i++)
      {
            num = arr[i];
            count = 1;
            while (check(arr, num + 1))
            {
                  num++;
                  count++;
            }
            ls = max(ls, count);
      }

      cout << ls << endl;
}

void longestElementB(vector<int> &arr, int n){
      int ls = 0;
      int num, count = 0;
      unordered_set<int> st;

      for(int i=0; i<n; i++){
            st.insert(arr[i]);
      }

      for(int i=0; i<n; i++){
            num = arr[i];
            count = 1;
            if(st.find(num - 1) == st.end()){
                  count = 1;
                  num = arr[i];
                  while(st.find(num + 1) != st.end()){
                        count++;
                        num++;
                  }
            }
            ls = max(ls, count);
      }
      cout << ls << endl;
}

void setMatrixZero(vector<vector<int>> &matrix, int n, int m) {
      int col0 = 1;
      
      for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  if(matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                  }
            }
      }

      for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                  if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        if(j != 0) {
                              matrix[i][j] = 0;
                        } else {
                              col0 = 0;
                        }
                  }
            }
      }

      if(col0 == 0) {
            for(int i=0; i<n; i++) {
                  matrix[i][0] = 0;
            }
            for(int j=0; j<n; j++) {
                  matrix[0][j] = 0;
            }
      }

      for(auto it : matrix){
            for(auto newit : it){
                  cout << newit  << " ";
            }
            cout << endl;
      }
}

void rotateMatirx(vector<vector<int>> &matrix, int n, int m) {
      for(int i=0; i<n-1; i++) {
            for(int j=i; j<m; j++) {
                  if(i != j) {
                        swap(matrix[i][j], matrix[j][i]);
                  }
            }
      }

      for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
      }


      for(auto it : matrix){
            for(auto newit : it){
                  cout << newit  << "  ";
            }
            cout << endl;
      }
}

void spiralMatrix(vector<vector<int>> &matrix, int n, int m) {
      int top = 0;
      int left = 0;
      int right = m-1;
      int bottom = n-1;
      vector<int> spiral;
      while(top <= bottom && left <= right) {

            for(int i=top; i<=right; i++) {
                  spiral.push_back(matrix[top][i]);
            }
            top++;

            for(int j=top; j<=bottom; j++) {
                  spiral.push_back(matrix[j][right]);
            }
            right--;
            if( top <= bottom) {
                  for(int i=right; i>=left; i--) {
                        spiral.push_back(matrix[bottom][i]);
                  }
                  bottom--;
            }

            if(left <= right) {
                  for(int i=bottom; i>=top; i--) {
                        spiral.push_back(matrix[i][left]);
                  }
                  left++;
            }
      }

      for(auto it: spiral) {
            cout << it <<" ";
      }
}

int main()
{

      vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
      vector<int> arr2 = {10, 22, 12, 3, 0, 6};
      vector<int> arr3 = {100, 4, 200, 1, 3, 2};
      vector<int> arr4 = {5,8,4,3,2,1};
      vector<vector<int>> matrix = {{1,0,0,1},{1,0,1,1},{1,1,0,1},{0,1,1,1}};
      vector<vector<int>> matrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
      vector<vector<int>> matrix3 = {{1,  2,  3,  4,  5},{14, 15, 16, 17, 6},{13, 20, 19, 18, 7},{12, 11, 10, 9,  8}};

      int n = arr.size();
      int o = arr2.size();
      int p = arr3.size();
      int q = arr4.size();
      int a = matrix.size();
      int b = matrix[0].size();

      nextPermutation(arr, n);
      cout << endl;
      superiorElement(arr2, o);
      cout << endl;
      longestElementBF(arr3, p);
      longestElementB(arr4, q);
      setMatrixZero(matrix, a, b);
      rotateMatirx(matrix2, a, b);              // i use different matrix with smae size , so i donot assign the any size for matrix 2
      spiralMatrix(matrix3, 4, 5);
      return 0;
}