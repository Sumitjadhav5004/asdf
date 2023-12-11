/*
Write a function template for selection sort that inputs, sorts and outputs an
integer array and a float array
*/
#include<iostream>
using namespace std;

template<typename t>
void selection(t array[],int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if (array[j]<array[min])
            min=j;
        }
        t temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
    cout<<"Array after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" , ";
    }
    cout<<endl;
}
int main()
{
int n;
cout<<"Enter array length : "<<endl;
cin>>n;
int array[n];
float arr[n];
cout<<"Enter integer  array : "<<endl;
for(int i=0;i<n;i++)
{
    cout<<"enter the element at index "<<i<<endl;
        cin>>array[i];
    }
    cout<<"Enter float array: "<<endl;
for(int i=0;i<n;i++)
{
    cout<<"enter the element at index "<<i<<endl;
        cin>>arr[i];
    }

selection(array,n);
selection(arr,n);
    return 0;
}/*
Write a function template for selection sort that inputs, sorts and outputs an
integer array and a float array
*/
#include<iostream>
using namespace std;

template<typename t>
void selection(t array[],int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if (array[j]<array[min])
            min=j;
        }
        t temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
    cout<<"Array after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" , ";
    }
    cout<<endl;
}
int main()
{
int n;
cout<<"Enter array length : "<<endl;
cin>>n;
int array[n];
float arr[n];
cout<<"Enter integer  array : "<<endl;
for(int i=0;i<n;i++)
{
    cout<<"enter the element at index "<<i<<endl;
        cin>>array[i];
    }
    cout<<"Enter float array: "<<endl;
for(int i=0;i<n;i++)
{
    cout<<"enter the element at index "<<i<<endl;
        cin>>arr[i];
    }

selection(array,n);
selection(arr,n);
    return 0;
}
