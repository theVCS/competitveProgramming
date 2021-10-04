#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    			int n,temp,max;
    			cout<<"Enter the no. of jobs: ";
    			cin>>n;
    			int profit[n],deadline[n];
    			string job[n],swap;
    			bool time_slot[n]={false};
    			cout<<"Enter the job, profit and deadline: "<<endl;
    			for(int i=0;i<n;i++)
        			cin>>job[i]>>profit[i]>>deadline[i];
    			for(int i=0;i<n-1;i++)
    			{
        			for(int j=i+1;j<n;j++)
        			{
            				if(profit[j]>profit[i])
            				{
                				temp=profit[i];
                				profit[i]=profit[j];
                				profit[j]=temp;

                				temp=deadline[i];
                				deadline[i]=deadline[j];
                				deadline[j]=temp;

                				swap=job[i];
                				job[i]=job[j];
                				job[j]=swap;
            				}
        			}
    			}
    			cout<<endl<<"After sorting: "<<endl<<"job\tprofit\tdeadline"<<endl;
    			for(int i=0;i<n;i++)
    			{
        			cout<<job[i]<<"\t"<<profit[i]<<"\t"<<deadline[i]<<endl;
    			}
    			cout<<endl<<"job scheduling sequence for maximum profit:"<<endl;
    			for(int i=0;i<n;i++)
    			{
        			for(int j=min(n,deadline[i])-1;j>=0;j--)
        			{
            				if(time_slot[j]==false)
            				{
                				cout<<job[i]<<" ";
                				time_slot[j]=true;
                				break;
            				}
        			}
    			}
    			return 0;
}
