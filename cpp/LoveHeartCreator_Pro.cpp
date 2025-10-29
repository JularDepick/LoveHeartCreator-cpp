#include <bits/stdc++.h>
#include <windows.h>
using namespace std; 

//参考方程：((y-0.575)^(2)+(x-0.635)^(2)-0.2)^(3)+(y-0.575)^(2) (x-0.635)^(3)=0
//该方程定义域包含于(0,1.15)，值域包含于(0,1.15) 
//根据坐标轴变化，第x行第y列对应平面直角坐标系点(x,y)

double prec; //精度：每个字符缩放到方程图形中所占长度 
int n;//参考值：爱心横向长度字符 
string endstr;

bool in_area(double x,double y) {
	const double yp2=(y-0.575)*(y-0.575);
	const double xp2=(x-0.635)*(x-0.635);
	const double xp3=xp2*(x-0.635);
	const double p3a=(yp2+xp2-0.2);
	const double p3=p3a*p3a*p3a;
	const double ans=p3+yp2*xp3;
	return (ans<=0); 
}

void print(string str,bool cycle=0) {
	string colors="0123456789abcdef";
	int idx=0,n=0;
	do {
		system("cls");
		string cmds="color 0";
		int seed=time(0)*idx+n;
		srand(seed);
		seed=rand()%15;
		cmds.push_back(colors[seed]);
		system(cmds.data());
		idx++,n++;
		if(idx>15) {
			idx%=15;
		}
		cout<<str;
		Sleep(n%8? 100:500);
	} while(cycle);
}

void run_it(vector<string> vec={},bool full=0) {
	int idx=0; 
	int len=vec.size();
	string anstr="";
	for(int x=0;x<=n;x++) {
		for(int y=0;y<n;y++) {
			double xx=prec*x;
			double yy=prec*y;
			if(in_area(xx,yy)) {
				anstr+=vec[idx%len];
				if(!full) {
					anstr+=" ";
				}
				idx++;
			} else {
				anstr+="  ";
			}
		}
		anstr+="\n";
	}
	anstr=(endstr+"\n"+anstr);
	print(anstr,1);
} 

int main() {
	//"请输入尺寸参数整数n(10~70)，该参数表示爱心图案的大致横向长度(单位/字符)，过小的n绘制出的爱心不够细致，过大的n可能导致显示异常，不符合要求的n将默认取40："<<endl;
	cin>>n;
	if(n<10 || n>70) {
		n=40;
	}
	//计算精度 
	prec=1.15/n;
	//输入内容参数
	string cont;
	cin>>cont;
	int len=cont.size();
	getline(cin,endstr);
	//判断全角
	bool full=0;
	for(int i=0;i<len;i++) {
		if(cont[i]<0 || cont[i]>=128) {
			full=1;
			break;
		}
	}
	//构造分割 
	vector<string> vec={};
	if(full) {
		for(int i=0;i<len;i++) {
			string str="";
			str.push_back(cont[i]);
			if(cont[i]<0 || cont[i]>=128) {
				str.push_back(cont[i+1]);
				i++;
			} else {
				str.push_back(' ');
			}
			vec.push_back(str);
		}
	} else {
		for(int i=0;i<len;i+=1) {
			string str="";
			str.push_back(cont[i]);
			vec.push_back(str);
		}
	}
	run_it(vec,full);
    return 0;
}
