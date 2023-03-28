#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
struct edge
	{
		int start,finish,cost;
	};
	
int main()
	{
		int n,m;
		cin>>n>>m;
		vector<edge>e;
		for (int i=0;i<m;i++)
			{
				edge a;
				cin>>a.start>>a.finish>>a.cost;
				a.start--;
				a.finish--;
				e.push_back(a);
			}
		vector<int> length (n, INT_MIN);
		vector<int> p (n, -1);
		length[0] = 0;
		int x;
		for (int i=0;i<n;i++)
			{
				x = -1;
				for (int j=0;j<m;j++)
					if 
((length[e[j].start]>INT_MIN)&&(length[e[j].finish]<length[e[j].start] + 
e[j].cost))
							{
								
length[e[j].finish]=length[e[j].start] + e[j].cost;
								
p[e[j].finish]=e[j].start;
								x=1;
							}
			}
		vector<int> path;
		int k=0;
		for (int i=n-1;i!=-1;i=p[i])
			{
				k++;
				path.push_back (i);
				if(k>n) break;
			}
		if(length[n-1]==INT_MIN) cout<<":("<<endl;
		else 
			 
if((x!=-1)&&((path.back()!=0)||(path.front()!=n-1)||(k>n))) 
cout<<":)"<<endl;
			 else cout<<length[n-1]<<" answer "<<endl;
		return 0;
	}
