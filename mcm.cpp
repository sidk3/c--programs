#include<iostream>
#include<limits.h>
using namespace std;

class mcm
{
    int p[100];
    int m[100][100];
    int s[100][100];
    int n;
    public:
    void get()
    {
        //int n=0;
        cout<<"\nEnter number of elements in p array: ";
        cin>>n;
        cout<<"\nEnter elements one by one: ";
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }

        cout<<"\n*****Divide and Conquer*****\n";
         int a=dc(p,1,n-1);
        cout<<"\nRequired value: "<<a;
        cout<<"\n*****TOP DOWN*****\n";
        memo(n);
        prin(1,n-1);
        cout<<"\n*****BOTTOM UP*****\n\n";
        botup(n-1);
        prin(1,n-1);
        cout<<endl;
    }

    int dc(int p[],int i,int j)
    {
        if(i==j)
         return 0;
        m[i][j]=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int q=dc(p,i,k)+dc(p,k+1,j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j])
            {
                m[i][j]=q;
            }
        }
        return m[i][j];
    }

    void botup(int n)
    {
        for(int i=0;i<n;i++)   
         m[i][i]=0;
        for(int l=2;l<=n;l++)
        {
            for(int i=1;i<=(n-l+1);i++)
            {
                int j=i+l-1;
                m[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(q<m[i][j])
                    {
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
    }

    int lookup(int p[],int i,int j)
    {
        if(m[i][j]<INT_MAX)
         return m[i][j];

        if(i==j) 
        {
         m[i][j]=0;
         return m[i][j];
        }
        else
        {
            for(int k=i;k<j;k++)
            {
                int q=lookup(p,i,k)+lookup(p,k+1,j)+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
        return m[i][j];
    }

    void memo(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                m[i][j]=INT_MAX;
                s[i][j]=INT_MAX;
            }
        }
        int a= lookup(p,1,n-1);
        cout<<"\nFinal value: "<<a<<endl;

    }

    void prin(int i,int j)
    {
        if(i==j)
         cout<<"a"<<i;
        else
        {
            cout<<"(";
            prin(i,s[i][j]);
            prin(s[i][j]+1,j);
            cout<<")";
        } 
    }

};

int main()
{
    mcm m;
    m.get();
    return 0;
}