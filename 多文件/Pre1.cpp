 /*********************************************************
* �������������в����ĳ�ʼ������̬�����ڴ档 
* ����������� 
* �����������
* ����ֵ����
* ����˵������Ϣ�ֶ�֮���÷ֺ�(;)�ָ�
************************************************************/

#include<bits/stdc++.h>
#include "Pre1.h"
using namespace std;
int *head,*father,*du,*vis,*dfspath,*que,*topopath,*djstlpath,*pre, guidecnt=0,guidenow=0,n,m;
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
