#include <stdio.h>
#include <stdlib.h>
#define N 20
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N]){
 	int i,j,t,k;
	int r;		//��¼��˵ľ����������
	for(i=1;i<=n;i++){
		m[i][i]=0;	//��һ���������ʱ����˴���Ϊ 0
    }					//���������������ʼһ�ε���
for(r=2;r<=n;r++){	//��ĳ������ʼ
	for(i=1;i<=n-r+1;i++){   //��ĳ������Ľ���

		j=i+r-1;    //�õ���i��j�������˵Ĵ���
		m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];		//�õ��������˶Ͽ���λ��
		s[i][j]=i;		//Ѱ�Ҽ����Ų�ͬ,�������˴�������Сֵ,�޸�m����ͶϿ���λ��s����
		for(k=i+1;k<j;k++){
			t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			if(t<m[i][j]){
				m[i][j]=t;
				s[i][j]=k;
		   }
	   }
    }
  }
}

int main(void){
	int n=5,i,j=2;
	int p[N]={3,5,4,2,4,5};	//�洢������к�������
	int m[N][N]={0};		//�洢�����������˵���С����
	int s[N][N]={0};	//�洢�����������˶Ͽ���λ��	}
	MatrixChain(p,n,m,s);
	printf("\n������˵���С��������Ϊ:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
	 	    printf("%4d",m[i][j]);
	}
	printf("\n");
}
printf("\n������˶Ͽ���λ�þ���Ϊ:\n");
for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		printf("%3d",s[i][j]);
	}
	printf("\n");
}
	printf("������С��˴���Ϊ:%d\n",m[1][n]);
	return 0;
}
