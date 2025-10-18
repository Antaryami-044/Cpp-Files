#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numCount(int n)
{
      int cnt = (int)(log10(n) + 1);
      return cnt;
}

int revNum(int n){
      int ans = 0;
      while (n > 0)
      {
            int rem = n % 10;
            ans = (ans * 10) + rem;
            n = n / 10;
      }
      return ans;
}

string palindrome(int n)
{
      int ans = 0;
      int store = n;
      while (n > 0)
      {
            int rem = n % 10;
            ans = (ans * 10) + rem;
            n = n / 10;
      }

      if (store == ans)
      {
            cout << store << " is palidrome" << endl;
      }
      else
      {
            cout << store << " is not a palidrome" << endl;
      }
}

string amstrongNum(int n)
{
      int ans = 0;
      int store = n;
      while (n > 0)
      {
            int rem = n % 10;
            ans = ans + (rem * rem * rem);
            n = n / 10;
      }

      if (store == ans)
      {
            cout << store << " is amstrong Number" << endl;
      }
      else
      {
            cout << store << " is not a amstrong Number" << endl;
      }
}

void printDivision(int n)
{
      vector<int> ls;
      for (int i = 1; i < sqrt(n); i++)
      {
            if (n % i == 0)
            {
                  ls.push_back(i);
                  if ((n / i) != i)
                  {
                        ls.push_back((n / i));
                  }
            }
      }
      sort(ls.begin(), ls.end());
      for (auto it : ls)
      {
            cout << it << " ";
      }
}

void countPrime(int n)
{
      int count = 0;
      for (int i = 1; i * i < n; i++)
      {
            if (n % i == 0)
            {
                  count++;
                  if ((n / i) != i)
                  {
                        count++;
                  }
            }
      }
      if (count == 2)
      {
            cout << n << " is a prime number." << endl;
      }
      else
      {
            cout << n << " is not a prime number." << endl;
      }
}

void gcd_hcf(int n1, int n2)
{
      int a = n1;
      int b = n2;
      while (n1 > 0 && n2 > 0)
      {
            if (n1 > n2)
            {
                  n1 = n1 % n2;
            }
            else
            {
                  n2 = n2 % n1;
            }
      }
      if (n1 == 0)
      {
            cout << "GCD between " << a << " and " << b << " is: " << n2;
      }
      else
      {
            cout << "GCD between " << a << " and " << b << " is: " << n1;
      }
}

int recursion(int n, int m)
{
      if(n == 0)
      {
            return m;
      }
      recursion(n-1, m);
      cout << n << " " << endl;
}     

int factorial(int n)
{
      if(n == 0 || n == 1)
      {
            return 1;
      }
      return n * factorial(n-1);
}

void reverseArray(int arr[], int n, int i){
      if(i >= n/2){
            return;
      }
      swap(arr[i], arr[n-i-1]);
      reverseArray(arr, n, i+1);
}




int main()
{
      // cout << numCount(345) << endl;

      // cout << revNum(345) << endl;

      // cout << palindrome(11) << endl;

      // cout << amstrongNum(153) << endl;

      // printDivision(36);

      // countPrime(103);

      // gcd_hcf(10, 13);

      // recursion(5, 10);

      // cout << factorial(5) << endl;

      // int arr[5] = {1, 2, 3, 4, 5};
      // reverseArray(arr, 5, 0);
      // for(int i=0; i<5; i++){
      //       cout << arr[i] << " ";
      // }

      return 0;
}
