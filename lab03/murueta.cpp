#include <limits.h> 
#include <iostream>

using namespace std;


int maxCross(int a[], int low, int mid, int high) 
{ 
    int sum = 0;
    int Left = INT_MIN;
    int maxLeft; 
    for (int i = mid; i >= low; i--) 
    { 
        sum = sum + a[i]; 
        if (sum > Left) 
          Left = sum;
          maxLeft = i;
    } 
  
    sum = 0; 
    int Right = INT_MIN;
    int maxRight;
    for (int i = mid+1; i <= high; i++) 
    { 
        sum = sum + a[i]; 
        if (sum > Right) 
          Right = sum; 
          maxRight = i;
    } 
  
    return (maxLeft, maxRight, Left + Right);
} 
  

int maxarray(int a[], int low, int high) { 
    int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;
   if (low == high)
    {
     return (low, high, a[low]); 
    }

   int mid = (low + high)/2;
   (left_low, left_high, left_sum) = maxarray(a, low, mid);
        (right_low, right_high, right_sum) = maxarray(a, mid+1, high); 
        (cross_low, cross_high, cross_sum) = maxCross(a, low, mid, high); 
        if(left_sum >= right_sum && left_sum >= cross_sum){
            return (left_low, left_high, left_sum);
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum){
            return(right_low, right_high, right_sum);
        }
        else{
            return (cross_low, cross_high, cross_sum);
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