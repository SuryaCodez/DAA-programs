#include<iostream>
#include<time.h>
#include<ctime>
using namespace std;
void middle(int m,int n)
{
        int i,gcd;
        for(i=1;i<=m&&i<=n;i++)
        {
                if(m%i==0&n%i==0)
                {
                        gcd=i;
                }
        }
        cout<<"gcd is"<<gcd<<endl;
}
void euclid(int m,int n)
{
        int r=0;
        if(n!=0)
        {
                r=m%n;
                m=n;
                n=r;
        }
        cout<<"gcd is"<<m<<endl;
}
void sub(int m,int n)
{
        if(m!=n)
        {
                m=m-n;
        }
        else
        {
                n=n-m;
        }
        cout<<"gcd is"<<m<<endl;
}
int main()
{
        int m,n;
        cout<<"enter the two numbers\n";
        cin>>m>>n;
        clock_t start_t1=clock();
        middle(m,n);
        clock_t end1=clock();
        double time1=double(end1-start_t1)/CLOCKS_PER_SEC;
        cout<<"time taken for middle school is:"<<time1*1000000<<"microseconds";
        clock_t start_t2=clock();
        euclid(m,n);
        clock_t end2=clock();
        double time2=double(end2-start_t2)/CLOCKS_PER_SEC;
        cout<<"time taken for euclid is:"<<time2*1000000<<"microseconds";
        clock_t start_t3=clock();
        sub(m,n);
        clock_t end3=clock();
        double time3=double(end3-start_t3)/CLOCKS_PER_SEC;
        cout<<"time taken for subtraction is:"<<time3*1000000<<"microseconds";
        return 0;
}

