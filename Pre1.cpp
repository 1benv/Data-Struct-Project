#include<bits/stdc++.h>
using namespace std; 
int  n , m ,start,cnt,heapsize=0;
int *head,*father,*du,*vis,*dfspath,*que,*topopath,*djstlpath,*pre, guidecnt=0,guidenow=0;
int mapp[50][50];

struct node
{
	int u , v, nextt,val;
	node(int fromm,int too,int vall)
	{
		u=fromm;
		v=too;
		val=vall;
	}
}*e,*heap;
 /*********************************************************
* 功能描述：小根堆的插入 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void insert(node x)
{
	heap[++heapsize]=x;
	int pos=heapsize;
	while(pos!=1)
	{
		if(heap[pos].val>=heap[pos/2].val)break;
		swap(heap[pos],heap[pos/2]);
		pos/=2;
	}
}
 /*********************************************************
* 功能描述：小根堆的删除 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void delet(node x)
{
	heap[1]=heap[heapsize];
	heapsize--;
	int pos=1;
	while(pos*2<=heapsize)
	{
		int to = pos*2;
		if(pos*2+1<=heapsize&&heap[pos*2+1].val<heap[pos*2].val)
		to=pos*2+1;
		if(heap[pos].val>heap[to].val)
		swap(heap[pos],heap[to]);
		else 
		break;
		pos=to;
	}
}

 /*********************************************************
* 功能描述：所有参数的初始化，动态分配内存。 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void init()
{
	
	head=(int*)calloc((n+10),sizeof(int));
	e=(node *)calloc(2*(m+10),sizeof(node));
	father=(int *)calloc((n+10),sizeof(int));
	du=(int *)calloc((n+10),sizeof(int));	
	vis=(int *)calloc((n+10),sizeof(int));
	dfspath=(int *)calloc((n*m),sizeof(int));
	que=(int *)calloc((n+10),sizeof(int));
	topopath=(int *)calloc((n+10),sizeof(int));
	heap=(node *)calloc((n+m+10),sizeof(node)); 
	pre=(int *)calloc((10000),sizeof(int));
	for(int i = 1 ; i<=n ;i++)
	{
		 
		father[i]=i;
		
	}
}
 /*********************************************************
* 功能描述：所有参数的初始化，也就是清除地图进行再次输入地图。 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void clear()
{
	guidecnt=0,guidenow=0;
	cnt=0;
	heapsize=0;
	free(head);
	free(e);
	free(father);
	memset(mapp,0,sizeof(mapp));
	memset(heap,0,sizeof(heap));
	free(du);
	free(vis);
	free(dfspath);
	free(que);
	free(heap);
	free(topopath);
	free(pre);
	for(int i = 1 ; i<=n ;i++)
	{
		father[i]=i;
	}
	printf("******恭喜 景区信息重置清理完毕!******\n");
	printf("按任意键返回主菜单......\n"); 
	system("pause");
	return ;
}
 /*********************************************************
* 功能描述：迪杰斯特拉算法求单源最短路径 
* 输入参数：无 
* 输出参数：无
* 返回值：点x到to的最短路径 
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
int djstl(int x,int to)
{
	int dis[50],v[50];
	for(int i = 1 ; i<=50 ;i++)
	dis[i]=99999999;
	memset(v,0,sizeof(v));
	memset(pre,0,sizeof(pre));
	dis[x]=0;
	int pos=x;
	v[x]=0;
	for(int j = 1; j <=n ;j++)
	{
		
		int minn=99999999;
		pos=-1;
		for(int i=1;i<=n;i++)
		{
			if(dis[i]<minn&&v[i]==0)
			{
				minn=dis[i];
				pos=i;
			
			}
		}
		v[pos]=1;
		for(int i=head[pos];i!=0;i=e[i].nextt)
		{
			if(!v[e[i].v]&&dis[e[i].v]>dis[pos]+e[i].val)
			{
				dis[e[i].v]=dis[pos]+e[i].val;
				pre[e[i].v]=pos;
			}
		}
		
	}
	return dis[to];
 } 
 /*********************************************************
* 功能描述：并查集寻找根 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/

int find(int x) 
{
	if(x!=father[x])
	father[x]=find(father[x]);
	return father[x];
}
 /*********************************************************
* 功能描述：并查集的合并
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void bing(int a,int b ) 
{
	int fa=find(a);
	int fb=find(b);
	if(father[fa]!=father[fb])
	{
		father[fa]=fb;
	}
	
}
/*********************************************************
* 功能描述：查询图中两点之间的最短路径，并且输出路径。 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void query()
{
	int from,to,tot=1,path[100];
	printf("******请输入要查询的两个景点******\n");
	printf("!!!输入0 0退出查询!!!\n");
	while(1)
	{
	memset(path,0,sizeof(path));
	tot=1;
	scanf("%d %d",&from,&to);
	if(from==0&&to==0) break;
	if(from==to)
	{
		printf("景点%d到景点%d的最短距离为0\n",from,to);
		cout<<from<<endl;
		continue;
	 } 
	if(from>n||to>n)
	{
		printf("您的输入不合法，请重新输入！\n");
		printf("按任意键继续......\n"); 
	system("pause");
		continue;
	 } 
	int duan;
	
	
	 duan=djstl(from,to);
	printf("景点%d到景点%d的最短距离为%d\n",from,to,duan);
	
	path[tot]=to;
	tot++;
	int tem=pre[to];
	while(tem!=from)
	{
	
		path[tot]=tem;
		tot++;
		tem=pre[tem];
		//cout<<path[tot]<<endl;
	}
	path[tot]=from;
	for(int i = tot ; i>=2; i--)
	{
		
		printf("%d->",path[i]);
	}
	cout<<path[1];
	cout<<endl;
	}
	printf("按任意键返回主菜单......\n"); 
	system("pause");
	
	return ;
}
/*********************************************************
* 功能描述：拓扑排序判断环的个数，并且输出每个环具体是哪些。 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void topo() //拓扑排序 
{
	int huancnt=0,tot=2;
	int num[50],huan[50],vistopo[50];
	memset(vistopo,0,sizeof(vistopo));
	memset(num,0,sizeof(num));
	memset(huan,0,sizeof(huan));
	int head=1;
	int tail=0;
	que[++tail]=start;
	du[start]=1;
	while(head<=tail)
	{
		int now=que[head++];
		num[now]++;
			int to=dfspath[tot++];
			du[to]--;
			topopath[now]=to;
			for(int i =1 ; i<=n ;i++)
			{
				if(du[i]==0&&vistopo[i]==0)
				{
				que[++tail]=i;	
				vistopo[i]=1;
				}
			}

	}	
		for(int i = 1 ; i<=n ;i++)
		{
			if(num[i]==2)
			{
				huan[i]=1;
				huancnt++;
			}
		}
	//打印环;
	printf("\n");
	printf("!!!!!!此导游路线有%d个环!!!!!!\n",huancnt);
	
	if(huancnt>0)
	{
		for(int i = 1 ; i<=guidecnt ;i++)
		{
			
			int cnt=0;
			for(int j =i+1 ; j<=guidecnt ;j++)
			{
				if(dfspath[i]==dfspath[j])
				{
					for(int k=i;k<j;k++)
					{
						printf("%d->",dfspath[k]);
					}
					cout<<dfspath[j]<<endl;
				}
			}
		}
	}
	printf("按任意键返回主菜单......\n"); 
	system("pause");
	return ;
}

/*********************************************************
* 功能描述：用最小生成树Kruskal算法，建立道路修建规划图 。 
* 输入参数：无 
* 输出参数：要修建的道路的两个端点，以及最小花费。 
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/

void plan()
{

	printf("******道路修建规划图******\n");
	int cc=0,len=0,flag=0;
	for(int i =1 ; i<=m ;i++)
	{
		int u=find(heap[1].u);	
		int v=find(heap[1].v);
		if(u==v) continue;
		len+=heap[1].val;
		bing(heap[1].u,heap[1].v);
		printf("%d %d\n",heap[1].u,heap[1].v);
		delet(heap[1]);
		bing(u,v);
		if(++cc==n-1)
		{
			flag=1;
			break;
		}
	}
	cout<<endl; 
	printf("******道路修建花费最小总代价为%d!******\n",len);
	printf("按任意键返回主菜单......\n"); 
	system("pause");
	return ;
}
/*********************************************************
* 功能描述：dfs 建立导游路线图，并且记录路径存放在dfspath[]； 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void guide(int x) 
{
	du[x]++;
	guidenow++;
	vis[x]=1;
	dfspath[++guidecnt]=x;
	if(guidenow==n) return ;
	for(int i = head[x] ; i ; i=e[i].nextt)
	{
		int to = e[i].v;
		
		if(!vis[to])
		{
			guide(to);
			if(guidenow<n)
			{
				dfspath[++guidecnt]=x;
				du[x]++;
			}
			
		}
	 } 

}
/*********************************************************
* 功能描述：输出导游路线图                                             
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void dfsprint()
{
	for(int i =1 ;i<=guidecnt-1 ;i++)
	{
		printf("%d->",dfspath[i]);
	}
	cout<<dfspath[guidecnt];
	return ;
}
/*********************************************************
* 功能描述：邻接表（链式前向星）转化为邻接矩阵
* 输入参数：无 
* 输出参数：图的邻接矩阵
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void matrix() 
{
	printf("******以下为景区地图的邻接矩阵形式******\n"); 
	for(int i = 1; i <=n ;i++)
	{
		mapp[i][i]=1;
		for(int j = head[i] ; j ; j=e[j].nextt)
		{
			int to=e[j].v;
			mapp[i][to]=1;    
		}
	}
	
	for(int i =1 ; i<=n ;i++)
	{
		for(int j = 1 ;j<=n ;j++)
		{
			printf("%d ",mapp[i][j]);
		}
		cout<<endl;
	}
	
	printf("按任意键返回主菜单......\n"); 
	system("pause");
	return ;
}

/*********************************************************
* 功能描述：给图加边，链式前向星存图。 
* 输入参数：无 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void add(int u,int v,int val) 
{
	e[++cnt].v=v;
	e[cnt].val=val;
	e[cnt].nextt=head[u];
	head[u]=cnt;
}

/*********************************************************
* 功能描述：建立景区分布图 
* 输入参数：景区景点数n，经典之间道路个数m，景区起始点start，各道路的起点终点和长度。 
* 输出参数：无 
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/
void build()
{
	int u,v,val;
	
	printf("******正在创建景区分布图ing******\n");
	printf("请输入景区景点数:");
	scanf("%d",&n);
	printf("请输入景点之间的道路个数:");
	scanf("%d",&m);
	printf("请输入景区入口(起始景点):");
	scanf("%d",&start); 
	init();
	printf("请输入各道路的起点、终点以及长度：\n"); 
	for(int i = 1 ; i<=m ;i++)
	{
		cin>>u>>v>>val;
		add(u,v,val);
		add(v,u,val);
		insert(node(u,v,val));			
	}	
	printf("******建立景区完毕******\n");
	printf("按任意键返回主菜单......\n"); 
	system("pause");
	return ;
}
