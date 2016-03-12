//20133059 武于微 信1301-1班
#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
#include<fstream>
#define size 10000
using namespace std;

string num_str(int i)    //将数字转换为字符串
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

int Operator(int m)    //产生运算符
{
	int a,b;
	char oper;
	a=rand()%4;    //产生随机整数用于除四取余后进行四种运算符号和四种数的选择
	b=rand()%2;
	if(m==2)    //无乘除法情况
	{
		switch(b)    //用于加减运算两种符选择
		{
		case 0:
			oper='+';
			break;
		case 1:
			oper='-';
			break;
		default:
			break;
		}
	}
	if(m==1)    //有乘除法情况
	{
		switch(a)          //用于四则运算四种符号的选择
		{
		case 0:
			oper='+';
			break;
		case 1:
			oper='-';
			break;
		case 2:
			oper='*';
			break;
		case 3:
			oper='/';
			break;	
		default:
		    break;
		}
	}
	return oper;
}

int operator1(char oper)    //随机生成运算符号判断
{
	int k;
	if(oper=='+')
	{
		k=1;
	}
	if(oper=='-')
	{
		k=2;
	}
	if(oper=='*')
	{
		k=3;
	}
	if(oper=='/')
	{
		k=4;
	}
	return k;
}

int Calculate1(int number,int value,int print)    //满足最多十个数值运算,无加减负数乘除余数限制
{
	int i,j,num1,num2,jishu,m,n;
	char oper1,op1,op2;
	string s_num1,s_num2,s_connect[size];
	ofstream outfile;    //定义ofstream类即输出文件流类对象outfile
	srand((unsigned)time(NULL));    //通过系统时间初始化随机数种子，若不设置则每次产生随机数相同
	cout<<"请选择运算是否有乘除法:1.有  2.没有"<<endl;  //乘除法选择
	cin>>m;
	if(print==2)    //文件打开
	{
		outfile.open("out.txt",ios::out);
		if(!outfile)    //打开错误，报错
		{
			cerr<<"open error!"<<endl;
			exit(0);
		}
	}
	for(i=0;i<number;i++)    //输出运算式数量循环
	{
		num1=rand()%value+1;
	    num2=rand()%value+1;
		oper1=Operator(m);
		s_num1=num_str(num1);
		s_num2=num_str(num2);
		s_connect[i]=s_num1+oper1+s_num2;
		jishu=rand()%9+2;
		if(jishu>2)    //对随机生成运算式里数值个数判断
		{
			for(j=jishu;j>2;j--)     //两个数值以上运算式生成
			{
				s_num1=s_connect[i];
				oper1=Operator(m);
				num2=rand()%value+1;
				s_num2=num_str(num2);
				s_connect[i]=s_num1+oper1+s_num2;
			}
		}
		if(print==2)    //文件输出
		{
			outfile<<s_connect[i]<<"="<<endl;
		}
		else
		{
			cout<<s_connect[i]<<"="<<endl;    //dos界面输出
		}
	}
	if(print==2)
	{
		outfile.close();    //关闭文件
	}
	return 0;
}
int Calculate2(int number,int value,int print)    //三个数组成的运算式,有加减负数和乘除法限制
{
	int i,num1,num2,num3,k1,k2,num,m,negtive,remainder;
	char oper1,oper2;
	string s_num1,s_num2,s_num3,s_connect[size];
	ofstream outfile;    //定义ofstream类即输出文件流类对象outfile
	srand((unsigned)time(NULL));    //通过系统时间初始化随机数种子，若不设置则每次产生随机数相同
	cout<<"请选择运算时加减结果是否有负数:1.有  2.没有"<<endl;  //加减法有无负数选择
	cin>>negtive;
	cout<<"请选择运算是否有乘除法:1.有  2.没有"<<endl;  //乘除法选择
	cin>>m;
	if(m==1)
	{
		cout<<"请选择运算时除法是否有余数:1.有  2.没有"<<endl;  //除法有无余数选择
		cin>>remainder;
	}
	if(print==2)    //文件打开
	{
		outfile.open("out.txt",ios::out);
		if(!outfile)    //打开错误，报错
		{
			cerr<<"open error!"<<endl;
			exit(0);
		}
	}
	for(i=0;i<number;i++)    //输出运算式数量循环
	{
		num1=rand()%value+1;
	    num2=rand()%value+1;
		num3=rand()%value+1;
		oper1=Operator(m);
	    oper2=Operator(m);
		k1=operator1(oper1);
		k2=operator1(oper2);
		if(negtive==1&&m==2)    //加减有负数，无乘除法
		{
			oper1=Operator(m);
			oper2=Operator(m);
		    k1=operator1(oper1);
		    k2=operator1(oper2);
		}
		if(negtive==2&&m==2)    //加减无负数，无乘除法
		{
			oper1=Operator(m);
			oper2=Operator(m);
		    k1=operator1(oper1);
		    k2=operator1(oper2);
			if(k1==2)
			{
				for(;num1<num2;)
				{
					num1=rand()%value+1;
				}
				num=num1-num2;
			}
			if(k1==1)
			{
				num=num1+num2;
			}
			if(k2==2)
			{
				for(;num<num3;)
				{
					num3=rand()%value+1;
				}
			}
		}
		if(negtive==2&&m==1&&remainder==2)    //加减无负数,乘除法无余数
		{
			oper1=Operator(m);
			oper2=Operator(m);
		    k1=operator1(oper1);
		    k2=operator1(oper2);
			if(k1==4)
			{
				for(;num1%num2!=0;)
				{
					num1=rand()%value+1;
				}
				num=num1/num2;
				if(k2==2)
				{
					for(;num<num3;)
					{
						num3=rand()%value+1;
					}
				}
			}
			if(k2==4)
			{
				for(;num2%num3!=0;)
				{
					num2=rand()%value+1;
				}
				num=num2/num3;
				if(k1==2)
				{
					for(;num1<num;)
					{
						num1=rand()%value+1;
					}
				}
			}
			if(k1==4&&k2==4)
			{
				for(;num1%num2!=0;)
				{
					num1=rand()%value+1;
				}
				num=num1/num2;
				for(;num%num3!=0;)
				{
					num3=rand()%value+1;
				}
			}
		}
		if(negtive==1&&m==1&&remainder==2)    //加减无负数,乘除法无余数
		{
			if(k1==4)
			{
				for(;num1%num2!=0;)
				{
					num1=rand()%value+1;
				}
			}
			if(k2==4)
			{
				for(;num2%num3!=0;)
				{
					num2=rand()%value+1;
				}
			}
			if(k1==4&&k2==4)
			{
				for(;num1%num2!=0;)
				{
					num1=rand()%value+1;
				}
				num=num1/num2;
				for(;num%num3!=0;)
				{
					num3=rand()%value+1;
				}
			}
		}
		s_num1=num_str(num1);
		s_num2=num_str(num2);
		s_num3=num_str(num3);
		s_connect[i]=s_num1+oper1+s_num2+oper2+s_num3;
		if(print==2)    //文件输出
		{
			outfile<<s_connect[i]<<"="<<endl;
		}
		else
		{
			cout<<s_connect[i]<<"="<<endl;    //dos界面输出
		}
	}
	if(print==2)
	{
		outfile.close();    //关闭文件
	}
	return 0;
}

void main()
{
	int number,value,print,chose;
	cout<<"请输入运算题目数量:"<<endl;  //定制运算题目数量
	cin>>number;
	cout<<"请输入数值产生范围:"<<endl;    //选择数值产生范围
	cin>>value;
	cout<<"请选择运算题目打印方式: 1.dos界面打印 2.文件打印"<<endl;  //定制运算题目打印方式
	cin>>print;
	cout<<"请选择: 1.随机产生10个数以内的运算式,无加减负数乘除余数限制"<<endl;
    cout<<"        2.满足三个数值的运算式,有加减负数乘除余数限制"<<endl;
	cin>>chose;
	if(chose==1)
	{
		Calculate1(number,value,print);
	}
	if(chose==2)
	{
		Calculate2(number,value,print);
	}
}
