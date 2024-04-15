#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<cstring>
#include<string>
#include<limits.h>
using namespace std;

class lcs
{
string m,n;
int c[100][100];
char b[100][100];
public:
void gen()
{
char s[]={'A','B','C'};
ofstream fout("lcs_inp.txt");
for(int i=0;i<30;i++)
  fout<<s[rand()%3];
 fout<<endl;

for(int i=0;i<30;i++)
 fout<<s[rand()%3];
fout.close();
}

int dc(string m,string n,int i,int j,int count)
{
count++;

if(i==0||j==0)
 return 0;

if(m[i]==n[j])
 return dc(m,n,i-1,j-1,count)+1;
else
{
 int t1=dc(m,n,i-1,j,count);
 int t2=dc(m,n,i,j-1,count);
 
 if(t1>=t2)
  return t1;
 else
  return t2;
}
}

void botup(string m,string n,int count)
{
  int m1=m.size();
  int n1=n.size();
  for(int j=0;j<=n1;j++)
  {
    c[0][j]=0;
    b[0][j]='*';
  }
  for(int i=1;i<=m1;i++)
  {
    c[i][0]=0;
    b[i][0]='*';
  }
  for(int i=0;i<=m1;i++)
  {
    for(int j=0;j<=n1;j++)
    {
        count++;
        if(m[i-1]==n[j-1])
        { 
            c[i][j]=c[i-1][j-1]+1;
            b[i][j]='\\';
        }
        else if(c[i-1][j]>=c[i][j-1])
        {
            c[i][j]=c[i-1][j];
            b[i][j]='|';//^
        }
        else
        {
            c[i][j]=c[i][j-1];
            b[i][j]='-';//<-
        }
    }
  }
  
  if(m1<=6)
  {
    cout<<"\nPrinting C matrix:\n";
  cout<<"\t";
    for(int i=0;i<=n1;i++)
    {
        cout<<n[i]<<"\t";
    }
    cout<<endl;
     for(int i=0;i<m1;i++)
     {  
       cout<<endl; 
        cout<<m[i]<<"\t";
        for(int j=0;j<n1;j++)
        {
            cout<<c[i][j]<<"\t";
        }
       cout<<endl;
     }
     cout<<"\nPrinting B matrix:\n";
     cout<<"\t";
    for(int i=0;i<=n1;i++)
    {
        cout<<n[i]<<"\t";
    }
    cout<<endl;
    for(int i=0;i<m1;i++)
    {   cout<<endl;
        cout<<m[i]<<"\t";
        for(int j=0;j<n1;j++)
        {
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }

    }

    
  }


  int topdo(string m,string n,int i,int j,int count)
  {
    if(c[i][j]>=0)
     return c[i][j];
    count++;
    if(i==0||j==0)
    {
        c[i][j]=0;
        return c[i][j];
    }
    if(m[i]==n[j])
    {
        c[i][j]=topdo(m,n,i-1,j-1,count)+1;
        b[i][j]='\\';
    }
    else
    {
        int t1=topdo(m,n,i-1,j,count);
        int t2=topdo(m,n,i,j-1,count);
        if(t1>=t2)
        {
            c[i][j]=t1;
            b[i][j]='|';
        }
        else
        {
            c[i][j]=t2;
            b[i][j]='-';
        }
    }
    return c[i][j];
  }
    void prin(string m11,int i,int j)
    {
        if(i==0||j==0)
        {
            return;
        }
        if(b[i][j]=='\\')
        {
            prin(m11,i-1,j-1);
            cout<<m11[i]<<" ";
        }
        else if(b[i][j]=='|')
        {
            prin(m11,i-1,j);
        }
        else
        {
            prin(m11,i,j-1);
        }

    }
  
 void initia(string m,string n)
 {
    for(int i=0;i<m.size();i++)
    for(int j=0;j<n.size();j++)
     c[i][j]=INT_MIN;
 }

void inp()
{
gen();
cout<<"\nEnter input size(m)-5,6,10,12,14,22: ";
int m1=0;
cin>>m1;

cout<<"\nEnter input size(n)-5,6,10,12,14,22: ";
int n1=0;
cin>>n1;

ifstream fin("lcs_inp.txt");
getline(fin,m);
getline(fin,n);
fin.close();

cout<<"\nInitial strings: "<<m<<"\t"<<n;
int count=0;
//  cout<<"\n*******Divide and conquer*******";
//  int a=dc(m,n,m1,n1,count);
//  cout<<"\nStrings after given length: 1."<<m.substr(0,m1)<<" 2."<<n.substr(0,n1)<<endl;
//  cout<<"\t";
// cout<<"\nLCS length: "<<a;
string a1=m.substr(0,m1);
  string a2=n.substr(0,n1);
 cout<<"\n*******Bottom Up Approach*******\n";
 botup(a1,a2,count);
//  cout<<"\n*******Top Down Approach*******\n";
// initia(m,n);
// int b=topdo(a1,a2,m1,n1,count);
// cout<<"\nLCS length: "<<b<<endl;
// prin(m.substr(0,m1+1),m1,n1);
}


};

int main()
{
lcs l;
l.inp();
return 0;
}
