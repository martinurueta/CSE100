#include <limits.h> 
#include <iostream>

using namespace std;


int maxCross(int a[], int low, int mid, int high) 
{ 
    int sum = 0;
    int Left = INT_MIN; 
    for (int i = mid; i >= low; i--) 
    { 
        sum = sum + a[i]; 
        if (sum > Left) 
          Left = sum; 
    } 
  
    sum = 0; 
    int Right = INT_MIN;
    for (int i = mid+1; i <= high; i++) 
    { 
        sum = sum + a[i]; 
        if (sum > Right) 
          Right = sum; 
    } 
  
    return Left + Right;
} 
  

int maxarray(int a[], int low, int high) 
{ 

   if (low == high)
    {
     return a[low]; 
    }

   int mid = (low + high)/2;  //divide and conquer
   if (maxarray(a, low, mid) >= maxarray(a, mid+1, high) && 
       maxarray(a, low, mid) >= maxCross(a, low, mid, high))
    {
       return maxarray(a, low, mid);
    }
    
   if (maxarray(a, low, mid) <= maxarray(a, mid+1, high) && 
       maxarray(a, mid+1, high) >= maxCross(a, low, mid, high))
    {
       return maxarray(a, mid+1, high);
    }
    
   if (maxCross(a, low, mid, high) >= maxarray(a, mid+1, high) && 
       maxarray(a, low, mid) <= maxCross(a, low, mid, high))
    {
       return maxCross(a, low, mid, high);
    }
return 0;
}

int main() 
{ 
    int Arraysize;
    cin >> Arraysize;
        
    int a[Arraysize];
        
        for (int i = 0; i < Arraysize; i++) //fill in the aay
        {
            cin >> a[i];
        }
           int Maximized_sum = maxarray(a, 0, Arraysize-1); //return max
           cout<< Maximized_sum; 
           return Maximized_sum; 
}