#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

int indexOfMaximum(int* array,int length);
int indexOfMinimum(int* array,int length);
void isElevatorUp(int* KnownDestation, int* RequestedFloor, int* g_iDirection,int length,int Elevator);//look�㷨���ж��Ƿ�Ҫ���ϵĴ���
void isElevatorDown(int* KnownDestation, int* RequestedFloor, int* g_iDirection,int length,int Elevator);
int foundNumber(int* array, int key,int length);//�ж������Ƿ����ĳ����������������ĳ��ֵ���±�
int countNumberInArray(int* array, int key,int length);//����������ĳ����������
int isQuit(int* KnownDestation, int* RequestedFloor);
int const c_totalFloor = 10;
int const MaxHeadCount = 10000;
int g_iElevator = 1;
int g_iTime = 0;
int g_iCount = 0;
int g_iDirection = 1;
int main()
{

	int iRequestedFloor[10000] = { 0 };
	int iUnknownDestation[10000] = { 0 };
	int iKnownDestationFloor[10000] = { 0 };
	int iOverloadRequestFloor[10000] = { 0 };
	printf("��������ʼ¥���Ŀ��¥�㣬����������q\n");
	for (int z = 0; z < c_totalFloor; z++) {
		scanf("%d %d", &iRequestedFloor[z], &iUnknownDestation[z]);
	}
	do {//����
		if (g_iDirection == 1) {//�ж��Ƿ�Ҫ����
			if (g_iCount < 4) {//�ж��Ƿ���	
				if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
					int subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
					g_iCount -= subtract;//����
				}
				if (foundNumber(iRequestedFloor,g_iElevator,MaxHeadCount)!=-1) {
					iKnownDestationFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = iUnknownDestation[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)];//��ֵiKnownDestationFloor
					g_iCount++;//����
				}
			
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)!=-1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)!=-1) {
					printf("�����ڵ�%d�㣬������%d����λʱ�䣬��������%d����\n", g_iElevator, g_iTime, g_iCount);
				}
				do {
					if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
						iKnownDestationFloor[foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)] = 0;
					}
				} while (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1);
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
					iRequestedFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = 0;
				}//�������
				isElevatorUp(iKnownDestationFloor, iRequestedFloor, &g_iDirection, MaxHeadCount, g_iElevator);
				if (g_iDirection == -1)continue;
				if (g_iCount == 4)continue;
				g_iElevator++;g_iTime++;
			}
			else {//���صĴ�����
				isElevatorUp(iKnownDestationFloor,iOverloadRequestFloor, &g_iDirection,MaxHeadCount,g_iElevator);
				if (g_iDirection == -1)continue;
				g_iElevator++;g_iTime++;
			}

		}
		else {//����
			if (g_iDirection == -1) {//�ж��Ƿ�Ҫ����
				if (g_iCount < 4) {//�ж��Ƿ���
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)!=-1) {
						iKnownDestationFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = iUnknownDestation[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)];//��ֵiKnownDestationFloor
						g_iCount++;//����
					}
					if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)!=-1) {
						int subtract = 0;
						subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
						g_iCount -= subtract;//����
					}
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)!=-1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)!=-1) {
						printf("�����ڵ�%d�㣬������%d����λʱ�䣬��������%d����\n", g_iElevator, g_iTime, g_iCount);
					}
					do {
						if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
							iKnownDestationFloor[foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)] = 0;
						}
					} while (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1);//g_iElevator=0ʱ��ѭ��������Ҫ������ͷ
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
						iRequestedFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = 0;
					}
					isElevatorDown(iKnownDestationFloor, iRequestedFloor, &g_iDirection,MaxHeadCount,g_iElevator);
					if (g_iDirection == 1)continue;
					if (g_iElevator == 1)continue;//���̵�ͷ
					g_iElevator--;g_iTime++;
				}
				else {//����ʱ
					if (g_iDirection==-1) {
						if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)!=-1) {
							int subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
							g_iCount -= subtract;//ֻ�²���
						}
						if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)!=-1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)!=-1) {
								printf("�����ڵ�%d�㣬������%d����λʱ�䣬��������%d����\n", g_iElevator, g_iTime, g_iCount);
						}
						do {
							if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
									iKnownDestationFloor[foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)] = 0;
							}
						} while (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1);
						if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
							iRequestedFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = 0;
						}
						isElevatorDown(iKnownDestationFloor, iRequestedFloor, &g_iDirection,MaxHeadCount, g_iElevator);
						if (g_iDirection == 1)continue;//������ͷ
						if (g_iElevator == 1)continue;
						g_iElevator--;g_iTime++;	
					}
				}
			}
		}
	} while (isQuit(iRequestedFloor, iKnownDestationFloor));
	getch();
	return 0;
}


int indexOfMaximum(int* array,int length) {
	int ret = 0;
	for (int i = 1; i < length; i++) {//int i=0���ѭ��һ��,attention
		if (array[i] > array[ret]) {
			ret = i;
		}
	}
	return ret;
}


int indexOfMinimum(int* array,int length) {//Ҫ�ҳ��������Сֵ
	int iNonZeroCount = 0;
	for (int i = 0;i < length; i++) {
		if (array[i] != 0) {
			iNonZeroCount++;
		}
	}
	if (iNonZeroCount != 0) {//��ֹ����ȫΪ��
		int ret=-1;
		//for (int x = 0; x < length; x++) {if (KnownDestation[x] != 0)ret = x;}�и��򵥵ĳ�ʼ��
		for (int t = 0;t < length;t++) {
			if (array[t] == 0) {
				continue;
			}
			if(ret==-1) {
				ret = t;
			}//��ֹretû��ֵ
			if (array[t] != 0 && array[t] < array[ret]) {
				ret = t;
			}
			return ret;
		}
	}
	else return -1;//ע��ʹ��ʱҪ�жϣ���Ȼ������Խ��
}

void isElevatorUp(int* KnownDestation, int* RequestedFloor,int* Direction,int length,int Elevator) {
	if (KnownDestation[indexOfMaximum(KnownDestation, length)] < Elevator && RequestedFloor[indexOfMaximum(RequestedFloor, length)] < Elevator) {
		*Direction = -1;
	}
}


void isElevatorDown(int* KnownDestation, int* RequestedFloor,int* p_Direction,int length,int Elevator) {
	if (indexOfMinimum(KnownDestation, length) != -1 && indexOfMinimum(RequestedFloor, length) != -1) {
		if ((KnownDestation[indexOfMinimum(KnownDestation, length)] > Elevator && RequestedFloor[indexOfMinimum(RequestedFloor, length)] > Elevator)) {
			*p_Direction = 1;
		}
	}
	if (indexOfMinimum(KnownDestation, length) != -1 && indexOfMinimum(RequestedFloor, length) == -1) {
		if (KnownDestation[indexOfMinimum(KnownDestation, length)] > Elevator) {
			*p_Direction = 1;
		}
	}
	if (indexOfMinimum(KnownDestation, length) == -1 && indexOfMinimum(RequestedFloor, length) != -1) {
		if (RequestedFloor[indexOfMinimum(RequestedFloor, length)] > Elevator) { 
			*p_Direction = 1; 
		}
	}//�ֱ��о�3�������ʣ�µ�һ����quit�����.
}

int foundNumber(int* array, int key,int length) {
	int ret = -1;
	for (int i = 0;i < MaxHeadCount;i++) {
		if (array[i] == key) {
			ret = i;
		}
	}
	return ret;
}

int isQuit(int* KnownDestation, int* RequestedFloor) {
	int ret = 0;
	for (int i = 0; i < MaxHeadCount; i++) {
		if (KnownDestation[i] != 0 || RequestedFloor[i] != 0) {
			ret = 1;
		}
	}
	return ret;
}

int countNumberInArray(int* KnownDestation, int key,int length) {
	int g_iCount = 0;
	for (int i = 0;i < MaxHeadCount;i++) {
		if (KnownDestation[i] == key)g_iCount++;
	}
	return g_iCount;
}