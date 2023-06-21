
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
void init(); //对所有变量的初始化
void build();//建立景区分布图，景区景点数n，经典之间道路个数m，景区起始点start，各道路的起点终点和长度。
void add(int u,int v,int val);//给图加边
void matrix();//邻接表（链式前向星）转化为邻接矩阵，并且输出邻接矩阵
void guide(int x); //dfs导游路线
void dfsprint(); //输出导游路线
void topo(); //拓扑排序，判断环的个数并且打印环
void query();//用来查询两点间的最短路径，并且输出路径
	int djstl(int x,int to); //迪杰斯特拉求两点间最短路径，返回最短距离
void plan(); //道路修建规划图,最小生成树输出要修建的道路的两个端点，以及最小花费
void clear();//对所有变量的清除释放
void insert(struct node); //堆的插入
void delet(struct node); //堆的删除
int find(int x);//并查集找根
	void bing(int a,int b ); //并查集合并集合

