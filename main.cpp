//20133059 ����΢ ��1301-1��
#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
#include<fstream>
#define size 10000
using namespace std;

string num_str(int i)    //������ת��Ϊ�ַ���
{
	stringstream ss;
	ss<<i;
	return ss.str();
}

int Operator(int m)    //���������
{
	int a,b;
	char oper;
	a=rand()%4;    //��������������ڳ���ȡ����������������ź���������ѡ��
	b=rand()%2;
	if(m==2)    //�޳˳������
	{
		switch(b)    //���ڼӼ��������ַ�ѡ��
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
	if(m==1)    //�г˳������
	{
		switch(a)          //���������������ַ��ŵ�ѡ��
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

int operator1(char oper)    //���������������ж�
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

int Calculate1(int number,int value,int print)    //�������ʮ����ֵ����,�޼Ӽ������˳���������
{
	int i,j,num1,num2,jishu,m,n;
	char oper1,op1,op2;
	string s_num1,s_num2,s_connect[size];
	ofstream outfile;    //����ofstream�༴����ļ��������outfile
	srand((unsigned)time(NULL));    //ͨ��ϵͳʱ���ʼ����������ӣ�����������ÿ�β����������ͬ
	cout<<"��ѡ�������Ƿ��г˳���:1.��  2.û��"<<endl;  //�˳���ѡ��
	cin>>m;
	if(print==2)    //�ļ���
	{
		outfile.open("out.txt",ios::out);
		if(!outfile)    //�򿪴��󣬱���
		{
			cerr<<"open error!"<<endl;
			exit(0);
		}
	}
	for(i=0;i<number;i++)    //�������ʽ����ѭ��
	{
		num1=rand()%value+1;
	    num2=rand()%value+1;
		oper1=Operator(m);
		s_num1=num_str(num1);
		s_num2=num_str(num2);
		s_connect[i]=s_num1+oper1+s_num2;
		jishu=rand()%9+2;
		if(jishu>2)    //�������������ʽ����ֵ�����ж�
		{
			for(j=jishu;j>2;j--)     //������ֵ��������ʽ����
			{
				s_num1=s_connect[i];
				oper1=Operator(m);
				num2=rand()%value+1;
				s_num2=num_str(num2);
				s_connect[i]=s_num1+oper1+s_num2;
			}
		}
		if(print==2)    //�ļ����
		{
			outfile<<s_connect[i]<<"="<<endl;
		}
		else
		{
			cout<<s_connect[i]<<"="<<endl;    //dos�������
		}
	}
	if(print==2)
	{
		outfile.close();    //�ر��ļ�
	}
	return 0;
}
int Calculate2(int number,int value,int print)    //��������ɵ�����ʽ,�мӼ������ͳ˳�������
{
	int i,num1,num2,num3,k1,k2,num,m,negtive,remainder;
	char oper1,oper2;
	string s_num1,s_num2,s_num3,s_connect[size];
	ofstream outfile;    //����ofstream�༴����ļ��������outfile
	srand((unsigned)time(NULL));    //ͨ��ϵͳʱ���ʼ����������ӣ�����������ÿ�β����������ͬ
	cout<<"��ѡ������ʱ�Ӽ�����Ƿ��и���:1.��  2.û��"<<endl;  //�Ӽ������޸���ѡ��
	cin>>negtive;
	cout<<"��ѡ�������Ƿ��г˳���:1.��  2.û��"<<endl;  //�˳���ѡ��
	cin>>m;
	if(m==1)
	{
		cout<<"��ѡ������ʱ�����Ƿ�������:1.��  2.û��"<<endl;  //������������ѡ��
		cin>>remainder;
	}
	if(print==2)    //�ļ���
	{
		outfile.open("out.txt",ios::out);
		if(!outfile)    //�򿪴��󣬱���
		{
			cerr<<"open error!"<<endl;
			exit(0);
		}
	}
	for(i=0;i<number;i++)    //�������ʽ����ѭ��
	{
		num1=rand()%value+1;
	    num2=rand()%value+1;
		num3=rand()%value+1;
		oper1=Operator(m);
	    oper2=Operator(m);
		k1=operator1(oper1);
		k2=operator1(oper2);
		if(negtive==1&&m==2)    //�Ӽ��и������޳˳���
		{
			oper1=Operator(m);
			oper2=Operator(m);
		    k1=operator1(oper1);
		    k2=operator1(oper2);
		}
		if(negtive==2&&m==2)    //�Ӽ��޸������޳˳���
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
		if(negtive==2&&m==1&&remainder==2)    //�Ӽ��޸���,�˳���������
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
		if(negtive==1&&m==1&&remainder==2)    //�Ӽ��޸���,�˳���������
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
		if(print==2)    //�ļ����
		{
			outfile<<s_connect[i]<<"="<<endl;
		}
		else
		{
			cout<<s_connect[i]<<"="<<endl;    //dos�������
		}
	}
	if(print==2)
	{
		outfile.close();    //�ر��ļ�
	}
	return 0;
}

void main()
{
	int number,value,print,chose;
	cout<<"������������Ŀ����:"<<endl;  //����������Ŀ����
	cin>>number;
	cout<<"��������ֵ������Χ:"<<endl;    //ѡ����ֵ������Χ
	cin>>value;
	cout<<"��ѡ��������Ŀ��ӡ��ʽ: 1.dos�����ӡ 2.�ļ���ӡ"<<endl;  //����������Ŀ��ӡ��ʽ
	cin>>print;
	cout<<"��ѡ��: 1.�������10�������ڵ�����ʽ,�޼Ӽ������˳���������"<<endl;
    cout<<"        2.����������ֵ������ʽ,�мӼ������˳���������"<<endl;
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
