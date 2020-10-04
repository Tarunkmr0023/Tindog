#include<iostream>
#include<bits/stdc++.h>


void sort(int num[], int temp[], int left, int right);
void merge(int num[], int temp[], int left, int mid, int right);
void MergeSort(int num[], int temp[], int size)
{
    sort(num, temp, 0, size-1);
}
void sort(int num[], int temp[], int left, int right)
{
    int mid;
    if(right>left)
    {
        mid= (right+left)/2;
        sort(num, temp, left, mid);
        sort(num, temp, mid+1, right);
        merge(num, temp, left, mid+1, right);
    }
}
    void merge(int num[], int temp[], int left, int mid, int right)
    {
        int i, left_end, num_ele, temp_pos;
        left_end= mid-1;
        temp_pos= left;
        num_ele= right-left+1; 
        while((left<= left_end) && (mid<=right))
        {
            if(num[left] <= num[mid])
            {
                temp[temp_pos]= num[left];
                temp_pos= temp_pos+1;
                left= left+1;
            }
            else
            {
                temp[temp_pos]= num[mid];
                temp_pos= temp_pos+1;
                mid= mid+1;
            }
            
        }
        while(left<= left_end)
        {
            temp[temp_pos]= num[left];
            left= left+1;
            temp_pos= temp_pos+1;
        }
        while(mid <= right)
        {
            temp[temp_pos]= num[mid];
            mid= mid+1;
            temp_pos= temp_pos+1;
        }
        for(i=0; i<=num_ele; i++)
        {
            num[right]= temp[right];
            right= right-1;
        }
   }


//int num[items];
//int temp[items];
int main()
{
    int n, i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>num[i];
    }
    MergeSort(num, temp, n);

    for(int i=0; i<n; i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    return 0;
}