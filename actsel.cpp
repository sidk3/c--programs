#include<iostream>
using namespace std;

void act(int s[],int f[],int n)
{
    int k=1;
    cout<<"\nActivity 1 included";
    for(int m=2;m<=n;m++)
    {
        if(s[m]>=f[k])
        {
         cout<<"\nActivity "<<m<<" included";
          k=m;
        }
    }
    
}

void rec(int s[],int f[],int k,int n)
{
 int m=k+1;
 while(m<=n && s[m]<f[k])
 {
    m++;
 }

 if(m<=n)
 {
    cout<<"\nActivity "<<m<<" selected";
    rec(s,f,m,n);
 }
}

int main()
{
    int s[100],f[100];
    cout<<"\nEnter number of elements in s and f arrays: ";
    int n=0;
    cin>>n;
    cout<<"\nEnter elements of s one by one: ";
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    cout<<"\nEnter elements of f one by one: ";
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
    }
    cout<<"\n*******Greedy Activity Selector*******";
    act(s,f,n);
    cout<<"\n\n*******Recursive Activity Selector*******";
    cout<<"\nActivity 1 selected";
    rec(s,f,1,n);
    return 0;
}