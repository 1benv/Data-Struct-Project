
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
