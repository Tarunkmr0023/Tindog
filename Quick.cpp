#include <iostream>
#include<bits/stdc++.h>
#define max 1000
int a[max], n, i, l, h;

using namespace std;

void Quick(int a[], int l, int h)
{
    int temp, key, low, high;
    low=l;
    high=h;
    key= a[(low+high)/2];
    do
    {
        while(key> a[low])
        { low++; }
        while(key< a[high])
        { high--; }
        if(low<= high)
        {
            temp= a[low];
            a[low++]= a[high];
            a[high--]= temp;
        }
    }
    while(low<= high);
    if(l< high)
      Quick(a, l, high);
    if(low< h)
      Quick(a, low, h);
}

int main()
{
   cin>>n;
   clock_t time_req;
  // int* a= new int[n];
   for(i=0; i<n; i++)
   {
       cin>>a[i];
   }
   time_req= clock();
   l= 0;
   h= n-1;
   Quick(a, l, h);
   time_req= clock() - time_req;
   //time_req= time_req - clock();
   
   for(i=0; i<n; i++)
   {
       cout<<a[i]<<" ";
   }
   cout<<endl;
   cout<<"Best Case Quick Sort "<<(double)time_req/CLOCKS_PER_SEC<<" seconds"<<endl;
   return 0;
}

