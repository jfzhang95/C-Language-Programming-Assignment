#include<stdio.h>
#include<string.h>
#include<stdlib.h>				//调用system()
#include<conio.h>				//调用getch()
#define ZHANGHAO 123456
#define MIMA 123456
void mainmenu();                	//主目录
void query(int);				//查询函数
void querenmenu1(int);			//确认目录1
void querenmenu2(int);			//确认目录2	
int deposit(int);				//存款函数1	
int deposit1();				//存款函数2
int withdraw(int);				//取款函数1
int withdraw1();				//取款函数2
int change(int);				//修改密码函数
int main(void)
{
	int zhanghao,mima;
	int i;
	char ch;
	for(i=0;i<=3;i++)
	{
		printf("请输入账号：");
		while(scanf("%d",&zhanghao)!=1)
		{
			printf("请输入数字账号!\n");
			printf("输入账号：");
			while((ch=getchar())!='\n')
				continue;
		}
		printf("请输入密码：");
		while(scanf("%d",&mima)!=1)
		{
			printf("请输入数字密码!\n");
			printf("输入密码：");
			while((ch=getchar())!='\n')
				continue;
		}
		if((zhanghao==ZHANGHAO)&&(mima==MIMA))
		{
			printf("========================\n");
			printf("欢迎您，123456用户。\n");
			printf("按任意键进入主界面\n");
			printf("========================\n");
			getch();
			break;
		}
		else
		{
			if(i==3)
			{
				printf("输错次数达到4次，退出程序\n");
				exit(0);
			}
			else
			{
				printf("账号或密码有误，请重新输入，你还有%d次机会。\n",3-i);
			}
		}
	}
	int exit=0;
	int money=10000;
	char in;
	while(!exit)
	{
		mainmenu();
		in=getch();
		switch(in)
		{
			case '1':query(money);break;		
			case '2':money=deposit(money);break;	
			case '3':money=withdraw(money);break;	
			case '4':mima=change(mima);break;		
			case '5':printf("欢迎再次使用\n");return 0;		}
	}
	return 0;
}

void mainmenu()
{
	system("cls");
	printf("========================\n");
	printf("|     1. 查询          |\n");
	printf("|     2. 存钱          |\n");
	printf("|     3. 取钱          |\n");
	printf("|     4. 修改密码      |\n");
	printf("|     5. 退出          |\n");
	printf("========================\n");
}

void query(int money)
{
	system("cls");
	printf("========================\n");
	printf("此账户有%d元\n",money);
	printf("按任意继续\n");
	printf("========================\n");
	getch();
}

int deposit(int money)
{
	int input;
	char in;
	system("cls");
	printf("========================\n");
	printf("输入您要存钱的数目 ￥");
	scanf("%d%*c",&input);
	while(input%100!=0)
	{
		printf("每次存款金额应为100的整数倍\n");
		printf("输入您要存钱的数目 ￥");
		scanf("%d%*c",&input);
	}
	int exit=0;
	while(!exit)
	{
		querenmenu1(input);
		in=getch();
		switch(in)
		{	
			case '1':exit=1;break;
			case '2':input=deposit1();exit=1;break;      
			case '3':input=0;exit=1;break;
		}
	}
	if(input!=0)
	{
		system("cls");
		printf("========================\n");
		printf("成功存储%d元\n",input);
		printf("按任意键继续\n");
		printf("========================\n");
		getch();
	}
	return money+input;
}

int withdraw(int money)
{
	int input;
	char in;
	while(1)
	{	
		system("cls");
		printf("========================\n");
		printf("输入您要取钱的数目: ￥");
		scanf("%d%*c",&input);
		while(input%100!=0||input>5000)
		{
			printf("每次取款金额应为100的整数倍且总额不得超过5000元\n");
			printf("输入您要取钱的数目 ￥");
			scanf("%d%*c",&input);
		}
		int exit=0;
		int m;
		while(!exit)
		{
			querenmenu2(input);
			in=getch();
			switch(in)
			{	
			   case '1':exit=1;break;
			   case '2':input=withdraw1();exit=1;break;    			   case '3':input=0;exit=1;break;
			}
		}
		if(input<=money)
			break;
		else
		{
			printf("余额不足,所剩余额为%d元。按2键后重新输入!\n",money);
			scanf("%d",&m);
			while(m!=2)
			{
				printf("请按2键后重新输入取款金额!\n");
				scanf("%d",&m);
			}
		}
	}
	if(input!=0)
		{
			system("cls");
			printf("========================\n");
			printf("成功取款%d元\n",input);
			printf("按任意键继续\n");
			printf("========================\n");
			getch();
		}	
	return money-input;
}

int change(int mm)
{
	system("cls");
	int mima1,mima2;
	int i;
	char ch;
	for(i=0;i<=3;i++)
	{
		printf("请输入原密码：");
		while(scanf("%d",&mima1)!=1)
		{
			printf("请输入6位数字密码!\n");
			printf("输入6位原密码：");
			while((ch=getchar())!='\n')
				continue;
		}
		while(mima1>999999||mima1<100000)
		{
			printf("请输入6位数字密码!\n");
			printf("输入6位原密码:");
			scanf("%d",&mima1);
			while((ch=getchar())!='\n')
				continue;
		}
		if(mima1==mm)
		{
			break;
		}
		else
		{
			if(i==3)
			{
				printf("输错次数达到4次，退出程序\n");
				exit(0);
			}
			else
			{
				printf("输入原密码有误，请重新输入，你还有%d次机会。\n",3-i);
			}
		}
	}
	printf("请输入新密码：");
	while(scanf("%d",&mima1)!=1)
	{
		printf("请输入数字密码!\n");
		printf("输入新密码：");  
		while((ch=getchar())!='\n')
				continue;
	}
	while(mima1>999999||mima1<100000||mima1%111111==0)
	{
		printf("请输入6数字位密码,且不能输入6位完全相同的密码!\n");
		printf("输入6位新密码：");
		scanf("%d",&mima1);
		while((ch=getchar())!='\n')
				continue;
	}
	system("cls");
	printf("请再次输入密码：");
	for(i=0;i<=3;i++)
	{
		scanf("%d",&mima2);
		if(mima2==mima1)
		{
			system("cls");
			printf("========================\n");
			printf("修改密码成功\n");
			printf("按任意键继续\n");
			printf("========================\n");
			getch();
			break;
		}
		else
		{
			if(i==3)
			{
				printf("输错次数达到4次，退出程序\n"); 
				exit(0);						
			}
			else
			{
				printf("所输入密码和新密码不同，你还有%d次机会。\n",3-i);
				printf("请再次输入密码：");
			}
		}
	}
	return mima2;
}

void querenmenu1(int input)
{
	int i;
	i=input;
	system("cls");
	printf("===============================\n");
	printf("|      1. 确认存储%d元         \n",i);
	printf("|      2. 修改存储金额         \n");
	printf("|      3. 放弃存款，返回上级   \n");
	printf("===============================\n");
}

void querenmenu2(int input)
{
	int i;
	i=input;
	system("cls");
	printf("===============================\n");
	printf("|      1. 确认取款%d元         \n",i);
	printf("|      2. 修改取款金额         \n");
	printf("|      3. 放弃取款，返回上级   \n");
	printf("===============================\n");
}

int deposit1()
{
	system("cls");
	int input;
	printf("========================\n");
	printf("输入您要存钱的数目 ￥");
	scanf("%d%*c",&input);
	while(input%100!=0)
	{
		printf("每次存款金额应为为100的整数倍\n");
		printf("输入您要存钱的数目 ￥");
		scanf("%d%*c",&input);
	}
	return input;
}

int withdraw1()
{
	system("cls");
	int input;
	printf("========================\n");
	printf("输入您要取款的数目 ￥");
	scanf("%d%*c",&input);
	while(input%100!=0)
	{
		printf("每次取款金额应为100的整数倍\n");
		printf("输入您要取款的数目 ￥");
		scanf("%d%*c",&input);
	}
	return input;
}
