#include<iostream>
#include<limits.h>
#include<string.h>
#include<fstream>
using namespace std;
#define MAX INT_MAX

class HHeap
{
    private:
    long int a[11000];
    public:
    void readInp(int n,int type)
    {
        char s[16];
        switch(type)
        {
            case 0: strcpy(s,"rand3.txt");break;
            case 1: strcpy(s,"ascend3.txt");break;
            case 2: strcpy(s,"descend3.txt");break;
            case 3: strcpy(s,"eqq3.txt");break;
        }
        ifstream fin(s);
        for(int i=0;i<n;i++)
        {
            fin>>a[i];
        }
        fin.close();
    }

    void output(int n)
    {
        ofstream fout("output.txt");
        for(int i=0;i<n;i++)
        {
            fout<<a[n-i-1]<<" ";
        }
        fout.close();
    }
    
    void maxheapify(int heapsize,int i,int &count)
    {
        count++;
        int l=2*i+1;
        int r=2*i+2;
        int max=i;
        if(l<=heapsize && a[max]<a[l])  
        {
            max=l;
        }
        if(r<=heapsize && a[max]<a[r])
        {
            max=r;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            maxheapify(heapsize,max,count);
        }
    }

    void buildmaxheap(int heapsize,int &count)
    {
        for(int i=(heapsize)/2;i>=0;i--)
        {
            maxheapify(heapsize,i,count);
        }
    }

    int heapsort(int n)
    {
        int count=0;
        int heapsize=n-1;
        buildmaxheap(heapsize,count);
        for(int i=n-1;i>=0;i--)
        {
            swap(a[0],a[i]);
            heapsize--;
            maxheapify(heapsize,0,count);
        }
        return count;
    }
};

int main()
{
    HHeap h;
    int l[]={10,50,100,500,1000,5000,10000};
    cout<<"\n\nFor Random numbers: \n";
    for(int i=0;i<7;i++)
    {
        int n=l[i];
        h.readInp(n,0);
        int c=h.heapsort(n);
        h.output(n);
        cout<<"Input size: "<<n<<endl;
        cout<<"Number of comparisions: "<<c<<endl;
    }
    cout<<"\n\nFor Acending numbers: \n";
    for(int i=0;i<7;i++)
    {
        int n=l[i];
        h.readInp(n,1);
        int c=h.heapsort(n);
        h.output(n);
        cout<<"Input size: "<<n<<endl;
        cout<<"Number of comparisions: "<<c<<endl;
    }
    cout<<"\n\nFor Descending numbers: \n";
    for(int i=0;i<7;i++)
    {
        int n=l[i];
        h.readInp(n,2);
        int c=h.heapsort(n);
        h.output(n);
        cout<<"Input size: "<<n<<endl;
        cout<<"Number of comparisions: "<<c<<endl;
    }
    cout<<"\n\nFor Equal numbers: \n";
    for(int i=0;i<7;i++)
    {
        int n=l[i];
        h.readInp(n,3);
        int c=h.heapsort(n);
        h.output(n);
        cout<<"Input size: "<<n<<endl;
        cout<<"Number of comparisions: "<<c<<endl;
    }
    return 0;
}