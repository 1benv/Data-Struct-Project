
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
void init(); //�����б����ĳ�ʼ��
void build();//���������ֲ�ͼ������������n������֮���·����m��������ʼ��start������·������յ�ͳ��ȡ�
void add(int u,int v,int val);//��ͼ�ӱ�
void matrix();//�ڽӱ���ʽǰ���ǣ�ת��Ϊ�ڽӾ��󣬲�������ڽӾ���
void guide(int x); //dfs����·��
void dfsprint(); //�������·��
void topo(); //���������жϻ��ĸ������Ҵ�ӡ��
void query();//������ѯ���������·�����������·��
	int djstl(int x,int to); //�Ͻ�˹��������������·����������̾���
void plan(); //��·�޽��滮ͼ,��С���������Ҫ�޽��ĵ�·�������˵㣬�Լ���С����
void clear();//�����б���������ͷ�
void insert(struct node); //�ѵĲ���
void delet(struct node); //�ѵ�ɾ��
int find(int x);//���鼯�Ҹ�
	void bing(int a,int b ); //���鼯�ϲ�����

