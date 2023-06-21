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
* ����������С���ѵĲ��� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* ����������С���ѵ�ɾ�� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* �������������в����ĳ�ʼ������̬�����ڴ档 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* �������������в����ĳ�ʼ����Ҳ���������ͼ�����ٴ������ͼ�� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
	printf("******��ϲ ������Ϣ�����������!******\n");
	printf("��������������˵�......\n"); 
	system("pause");
	return ;
}
 /*********************************************************
* �����������Ͻ�˹�����㷨��Դ���·�� 
* ����������� 
* �����������
* ����ֵ����x��to�����·�� 
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* �������������鼯Ѱ�Ҹ� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/

int find(int x) 
{
	if(x!=father[x])
	father[x]=find(father[x]);
	return father[x];
}
 /*********************************************************
* �������������鼯�ĺϲ�
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* ������������ѯͼ������֮������·�����������·���� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void query()
{
	int from,to,tot=1,path[100];
	printf("******������Ҫ��ѯ����������******\n");
	printf("!!!����0 0�˳���ѯ!!!\n");
	while(1)
	{
	memset(path,0,sizeof(path));
	tot=1;
	scanf("%d %d",&from,&to);
	if(from==0&&to==0) break;
	if(from==to)
	{
		printf("����%d������%d����̾���Ϊ0\n",from,to);
		cout<<from<<endl;
		continue;
	 } 
	if(from>n||to>n)
	{
		printf("�������벻�Ϸ������������룡\n");
		printf("�����������......\n"); 
	system("pause");
		continue;
	 } 
	int duan;
	
	
	 duan=djstl(from,to);
	printf("����%d������%d����̾���Ϊ%d\n",from,to,duan);
	
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
	printf("��������������˵�......\n"); 
	system("pause");
	
	return ;
}
/*********************************************************
* �������������������жϻ��ĸ������������ÿ������������Щ�� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void topo() //�������� 
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
	//��ӡ��;
	printf("\n");
	printf("!!!!!!�˵���·����%d����!!!!!!\n",huancnt);
	
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
	printf("��������������˵�......\n"); 
	system("pause");
	return ;
}

/*********************************************************
* ��������������С������Kruskal�㷨��������·�޽��滮ͼ �� 
* ����������� 
* ���������Ҫ�޽��ĵ�·�������˵㣬�Լ���С���ѡ� 
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/

void plan()
{

	printf("******��·�޽��滮ͼ******\n");
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
	printf("******��·�޽�������С�ܴ���Ϊ%d!******\n",len);
	printf("��������������˵�......\n"); 
	system("pause");
	return ;
}
/*********************************************************
* ����������dfs ��������·��ͼ�����Ҽ�¼·�������dfspath[]�� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* �����������������·��ͼ                                             
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
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
* �����������ڽӱ���ʽǰ���ǣ�ת��Ϊ�ڽӾ���
* ����������� 
* ���������ͼ���ڽӾ���
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void matrix() 
{
	printf("******����Ϊ������ͼ���ڽӾ�����ʽ******\n"); 
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
	
	printf("��������������˵�......\n"); 
	system("pause");
	return ;
}

/*********************************************************
* ������������ͼ�ӱߣ���ʽǰ���Ǵ�ͼ�� 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void add(int u,int v,int val) 
{
	e[++cnt].v=v;
	e[cnt].val=val;
	e[cnt].nextt=head[u];
	head[u]=cnt;
}

/*********************************************************
* �������������������ֲ�ͼ 
* �������������������n������֮���·����m��������ʼ��start������·������յ�ͳ��ȡ� 
* ����������� 
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/
void build()
{
	int u,v,val;
	
	printf("******���ڴ��������ֲ�ͼing******\n");
	printf("�����뾰��������:");
	scanf("%d",&n);
	printf("�����뾰��֮��ĵ�·����:");
	scanf("%d",&m);
	printf("�����뾰�����(��ʼ����):");
	scanf("%d",&start); 
	init();
	printf("���������·����㡢�յ��Լ����ȣ�\n"); 
	for(int i = 1 ; i<=m ;i++)
	{
		cin>>u>>v>>val;
		add(u,v,val);
		add(v,u,val);
		insert(node(u,v,val));			
	}	
	printf("******�����������******\n");
	printf("��������������˵�......\n"); 
	system("pause");
	return ;
}
