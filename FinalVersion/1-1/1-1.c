#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<conio.h>
int main() {
	int iRequest = 0;
	int iElevator = 0;
	int iDestation = 0;
	printf("请输入呼叫楼层、目的楼层以及电梯所在楼层\n");
	scanf("%d %d %d", &iRequest,&iDestation,&iElevator);
	printf("电梯在第%d层，电梯开始运行，此时电梯里有0人\n", iElevator);
	printf("电梯在第%d层，电梯运行了%d个单位时间，此时电梯里有1人\n",iRequest,abs(iElevator-iRequest));
	printf("电梯在第%d层，电梯运行了%d个单位时间，此时电梯里有0人\n",iDestation,abs(iElevator-iRequest)+abs(iRequest-iDestation));
	getch();
	return 0;
}