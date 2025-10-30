#include <bits/stdc++.h>
#include <windows.h>
using namespace std; 

//��Ȩ���У�github.com/JularDepick 
//�ο����̣�((y-0.575)^(2)+(x-0.635)^(2)-0.2)^(3)+(y-0.575)^(2) (x-0.635)^(3)=0
//�÷��̶����������(0,1.15)��ֵ�������(0,1.15) 
//����������仯����x�е�y�ж�Ӧƽ��ֱ������ϵ��(x,y)

double prec; //���ȣ�ÿ���ַ����ŵ�����ͼ������ռ���� 

bool in_area(double x,double y) {
	const double yp2=(y-0.575)*(y-0.575);
	const double xp2=(x-0.635)*(x-0.635);
	const double xp3=xp2*(x-0.635);
	const double p3a=(yp2+xp2-0.2);
	const double p3=p3a*p3a*p3a;
	const double ans=p3+yp2*xp3;
	return (ans<=0);
}

int main() {
	system("color 04");
	int n=40;
	prec=1.15/n;
	for(int x=0;x<=n;x++) {
		for(int y=0;y<n;y++) {
			double xx=prec*x;
			double yy=prec*y;
			if(in_area(xx,yy)) {
				printf("* "); 
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	system("pause");
    return 0;
}
