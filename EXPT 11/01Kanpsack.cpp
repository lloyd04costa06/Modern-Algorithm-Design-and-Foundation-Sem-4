#include<iostream>
using namespace std;


struct PW
{
    float p;
    float w;
};

bool search(int L,int H,float pp,float ww,PW pair[])
{
    int low=L;
    int high=H;
    while(low<=high)
    {

        int mid= (low+high)/2;

        if(pair[mid].p==pp&&pair[mid].w==ww)
        {
             return true;
        }
        else if(pair[mid].w<ww)
        {
            low=mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return false;
}


void Traceback(float p[],float w[],PW pair[],int x[],int m,int n,int b[])
{
    int last=b[n+1]-1;
    float pp=pair[last].p;
    float ww=pair[last].w;
    int k=n;

    while(pp>0 &&ww>0)
    {
  
         bool f=true;

        for(int j=k;j>=0;j--)
        {
    
            f=search(b[j],b[j+1]-1,pp,ww,pair);

            if(!f)
            {

                if(j!=n)
                {
                    x[j+1] =1;
                    pp=pp-p[j+1];
                    ww =ww-w[j+1];
                }
                else
                {
                    x[j] = 1;
                    pp=pp-p[j];
                    ww =ww-w[j];
                }
                k=j;
        
                break;
            }
        }
    
    }
  
    cout<<"\nSOLUTION VECTOR: ";

    for(int i=1;i<=n;i++)
    {
         cout<<x[i]<<" ";
    }
    
    cout<<endl;
   
    }


int largest(PW pair[],float w[],int t,int h,int i,int m)
{
    int low=t;
    int high=h;
    
    int ans;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(pair[mid].w+w[i]<=m)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
             high=mid-1;
        }
    }
   
    return ans;
}


void Dknap(float p[],float w[],int x[],int n,int m)
{
    struct PW pair[100];
    int b[n+1];
    //S0
    b[0]=1;
    pair[1].p=0.0;
    pair[1].w=0.0;
    int t=1,h=1;//start and end of s0
 
    b[1]=2;
    int next=2;
  
    for(int i=1;i<=n;i++)
    {

        //generate si
        int k=t;
        int u=largest(pair,w,t,h,i,m);

        for(int j=t;j<=u;j++)
        {
        
            //generate Si-1 and merge
            int pp=pair[j].p+p[i];
            int ww=pair[j].w+w[i];

            //(pp,ww) is next element in sI-1
            while((k<=h)&&(pair[k].w<=ww))
            {
                pair[next].p=pair[k].p;
                pair[next].w=pair[k].w;
                next++;
                k++;
            }
    
            if((k<=h) && (pair[k].w==ww))
            {
                if(pp<pair[k].p)
                {
                pp=pair[k].p;
            
                }
                k++;
            }

            if(pp>pair[next-1].p)
            {
                pair[next].p=pp;
                pair[next].w=ww;
                next++;
            }
            while((k<=h) && (pair[next].p<=pair[next-1].p))
            {
                 k++;
            }
        
        }
        
        //merge remaining terms
        while(k<=h)
        {
            pair[next].p=pair[k].p;
            pair[next].w=pair[k].w;
            next++;
            k++;
        }

        //initialise S i+1
        t=h+1;
        h=next-1;
        b[i+1]=next;

    }
  
    cout<<"SUBSETS: "<<endl;
    for(int i=0;i<=n;i++)
    {
    
        for(int j=b[i];j<=b[i+1]-1;j++)
        {
             cout<<" ("<<pair[j].p<<","<<pair[j].w<<") ";
        }
    
        cout<<endl;
    }
    
    Traceback(p,w,pair,x,m,n,b);
}


int main()
{
    int n,m;
    cout<<"ENTER NUMBER OF ELEMENTS : ";
    cin>>n;
  
    float p[n+1],w[n+1];
    cout<<"ENTER PROFIT AND WEIGHT OF ELEMENTS: "<<endl;

    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>w[i];
    }
    
    cout<<"ENTER THE BAG CAPACITY : ";
  
    cin>>m;
    
    int x[n+1];
    for(int i=0;i<=n+1;i++)
    {
         x[i]=0;
    }

    Dknap(p,w,x,n,m);
    float profit=0,weight=0;
    for(int i=1;i<=n;i++)
    {
        profit+=(x[i]*p[i]);
        weight+=(x[i]*w[i]);
    }
  
    cout<<"MAXIMUM PROFIT : "<<profit<<endl;
    cout<<"MAXIMUM WIGHT OCCUPIED : "<<weight<<endl;
    
    return 0;
}