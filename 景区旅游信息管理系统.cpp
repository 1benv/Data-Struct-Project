
/***********************************************************
* 版权所有 (C)2021, BianMingHao
*
* 文件名称：景区旅游信息管理系统.c
* 文件标识：无
* 内容摘要：景区旅游信息管理系统 
* 其它说明：无
* 当前版本： V1.0
* 作   者：边明豪
* 完成日期： 2021/12/20
*
**********************************************************/

#include "Pre1.cpp"
/*********************************************************
* 功能描述：主函数，作为界面使用。 
* 输入参数：要使用的功能的编号1，2，3，4，5，6； 
* 输出参数：无
* 返回值：无
* 其它说明：消息字段之间用分号(;)分隔
************************************************************/

int main()
{
	int op;
	init();
	
	while(1)
	{
	system("cls");
	printf("欢迎来到景区旅游中心！\n");
	printf("******功能菜单******\n");
	printf("输入相应数字来选择功能\n");
	printf("1 创建景区分布图\n");
	printf("2 景区分布图\n");
	printf("3 导游路线及是否有环\n");
	printf("4 景点最短路径查询\n");
	printf("5 道路修建规划图\n");
	printf("6 清除景区分布图\n"); 	
	
	scanf("%d",&op);	
	switch(op)
	{
		case 1:
			system("cls");
			build();
			break;
		case 2:
			system("cls");
			matrix();
			break;
		case 3:
			system("cls");
			guide(start);
			dfsprint();
			topo();
			break; 
		case 4:
			system("cls");
			query();
			break;
		case 5:
			system("cls");
			plan();
			break;
		case 6:
			system("cls");
			clear();
			break;
	}
	
	}
	return 0;
}
