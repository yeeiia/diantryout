#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<conio.h>
int main() {
	int iRequest = 0;
	int iElevator = 0;
	int iDestation = 0;
	FILE* fp = fopen("./input.txt", "r");
	fscanf(fp, "%d %d %d", &iElevator, &iRequest, &iDestation);
	fclose(fp);
	printf("�����ڵ�%d�㣬���ݿ�ʼ���У���ʱ��������0��\n", iElevator);
	printf("�����ڵ�%d�㣬����������%d����λʱ�䣬��ʱ��������1��\n", iRequest, abs(iElevator - iRequest));
	printf("�����ڵ�%d�㣬����������%d����λʱ�䣬��ʱ��������0��\n", iDestation, abs(iElevator - iRequest) + abs(iRequest - iDestation));
	getch();
	return 0;
}