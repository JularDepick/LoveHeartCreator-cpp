#include <bits/stdc++.h>
#include <windows.h>
using namespace std; 

//版权所有：github.com/JularDepick 
//参考方程：((y-0.575)^(2)+(x-0.635)^(2)-0.2)^(3)+(y-0.575)^(2) (x-0.635)^(3)=0
//该方程定义域包含于(0,1.15)，值域包含于(0,1.15) 
//根据坐标轴变化，第x行第y列对应平面直角坐标系点(x,y)

double prec; //精度：每个字符缩放到方程图形中所占长度 

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
