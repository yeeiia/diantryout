#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int indexOfMaximum(int* array, int length);
int indexOfMinimum(int* array, int length);
void isElevatorUp(int* KnownDestation, int* RequestedFloor, int* g_iDirection, int length, int Elevator);//look�㷨���ж��Ƿ�Ҫ���ϵĴ���
void isElevatorDown(int* KnownDestation, int* RequestedFloor, int* g_iDirection, int length, int Elevator);
void isElevatorWait(int* KnownDestation, int* RequestedFloor, int* Waitingfloor, int length, int* p_Direction);
int foundNumber(int* array, int key, int length);//�ж������Ƿ����ĳ����(�����ڷ���-1)������������ĳ��ֵ���±�
int countNumberInArray(int* array, int key,int length);
int isQuit(int* KnownDestation, int* RequestedFloor, int* WaitingFloor);
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
	int iOverloadRequestFloor[10000] = { 0 };//����ʱ��������
	int iIntervalTime[10000] = { 0 };
	int iWaitingFloor[10000] = { 0 }; 
	printf("��������ݳ�ʼ¥��\n");
	scanf("%d", &g_iElevator);
	printf("��������ʼ¥���Ŀ��¥���Լ��ȴ�ʱ�䣬����������q\n");
	for (int z = 0; z < 10000; z++) {
	scanf("%d %d %d", &iWaitingFloor[z], &iUnknownDestation[z],&iIntervalTime[z]);
	}	
	do {
		for (int i = 0; i < MaxHeadCount; i++) {
			if (iIntervalTime[i] == 0) {
				iRequestedFloor[i] = iWaitingFloor[i];
				iWaitingFloor[i] = 0; iIntervalTime[i] = -1;
			}
		}
		isElevatorWait(iKnownDestationFloor, iRequestedFloor, iWaitingFloor, MaxHeadCount, &g_iDirection);//�����������Ⱥ�Ͱѷ����Ϊ1
		isElevatorUp(iKnownDestationFloor, iRequestedFloor, &g_iDirection, MaxHeadCount, g_iElevator);//���Ĭ�Ϸ���Ϊ1�Ƿ���ȷ
		if (g_iDirection == 0) {
			g_iTime++;
			for (int i = 0; i < MaxHeadCount; i++) {
				if (iIntervalTime[i] >= 0) {
					iIntervalTime[i] -= 1;
				}
			}
		}
		if (g_iDirection == 1) {//����
			if (g_iCount < 4) {
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
					iKnownDestationFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = iUnknownDestation[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)];//��ֵiKnownDestationFloor
					g_iCount++;
				}
				if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
					int subtract = countNumberInArray(iKnownDestationFloor, g_iElevator,MaxHeadCount);
					g_iCount -= subtract;
				}
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
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
				g_iElevator++; g_iTime++;
				for (int i = 0; i < MaxHeadCount; i++) {
					if (iIntervalTime[i] >= 0) {
						iIntervalTime[i] -= 1;
					}
				}
			}
			else {//���صĴ�����
				isElevatorUp(iKnownDestationFloor, iOverloadRequestFloor, &g_iDirection, MaxHeadCount, g_iElevator);
				if (g_iDirection == -1)continue;
				g_iElevator++; g_iTime++;
				for (int i = 0; i < MaxHeadCount; i++) {
					if (iIntervalTime[i] >= 0) {
						iIntervalTime[i] -= 1;
					}
				}
			}
		}
		else {//����
			if (g_iDirection == -1) {
				if (g_iCount < 4) {
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
						iKnownDestationFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = iUnknownDestation[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)];//��ֵiKnownDestationFloor
						g_iCount++;
					}
					if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
						int subtract = 0;
						subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
						g_iCount -= subtract;
					}
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
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
					isElevatorDown(iKnownDestationFloor, iRequestedFloor, &g_iDirection, MaxHeadCount, g_iElevator);
					if (g_iDirection == 1)continue;
					for (int i = 0; i < MaxHeadCount; i++) {
						if (iIntervalTime[i] >= 0) {
							iIntervalTime[i] -= 1;
						}
					}				
					if (g_iElevator == 1)continue;
					g_iElevator--; g_iTime++; 

				}
				else {//����ʱ
					if (g_iDirection == -1) {
						if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
							int subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
							g_iCount -= subtract;//ֻ�²���
						}
						if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
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
						isElevatorDown(iKnownDestationFloor, iRequestedFloor, &g_iDirection, MaxHeadCount, g_iElevator);
						if (g_iDirection == 1)continue;//������ͷ	
						for (int i = 0; i < MaxHeadCount; i++) {
							if (iIntervalTime[i] >= 0) {
								iIntervalTime[i] -= 1;
							}
						}
						if (g_iElevator == 1)continue;
						g_iElevator--; g_iTime++;

					}
				}	
			}
		}
	} while (isQuit(iRequestedFloor, iKnownDestationFloor,iWaitingFloor));
	getch();
	return 0;
}


int indexOfMaximum(int* array, int length) {
	int ret = 0;
	for (int i = 1; i < length; i++) {//int i=0���ѭ��һ��,attention
		if (array[i] > array[ret]) {
			ret = i;
		}
	}
	return ret;
}


int indexOfMinimum(int* array, int length) {//Ҫ�ҳ��������Сֵ
	int iNonZeroCount = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] != 0) {
			iNonZeroCount++;
		}
	}
	if (iNonZeroCount != 0) {//��ֹ����ȫΪ��
		int ret = -1;
		//for (int x = 0; x < length; x++) {if (KnownDestation[x] != 0)ret = x;}�и��򵥵ĳ�ʼ��
		for (int t = 0; t < length; t++) {
			if (array[t] == 0) {
				continue;
			}
			if (ret == -1) {
				ret = t;
			}//��ֹretû��ֵ!!
			if (array[t] != 0 && array[t] < array[ret]) {
				ret = t;
			}
			return ret;
		}
	}
	else return -1;//ע��ʹ��ʱҪ�жϣ���Ȼ������Խ��!!!
}

void isElevatorUp(int* KnownDestation, int* RequestedFloor, int* p_Direction, int length, int Elevator) {
	int isNull = -1;
	for (int i = 0; i < length; i++) {
		if (KnownDestation[i] != 0 || RequestedFloor[i] != 0) {
			isNull = 1;
		}
	}
	if (isNull == 1) {
		if (KnownDestation[indexOfMaximum(KnownDestation, length)] < Elevator && RequestedFloor[indexOfMaximum(RequestedFloor, length)] < Elevator) {
			*p_Direction = -1;
		}
	}
	else {
		*p_Direction = 0;
	}
}


void isElevatorDown(int* KnownDestation, int* RequestedFloor, int* p_Direction, int length, int Elevator) {
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
	}//��������Ϊ��ʱ��ѭ��,���1-3��ͬ
	if (indexOfMinimum(KnownDestation, length) == -1 && indexOfMinimum(RequestedFloor, length) == -1) {
		*p_Direction = 0;
	}
}

void isElevatorWait(int* KnownDestation,int* RequestedFloor,int *Waitingfloor,int length,int* p_Direction) {
	for (int i = 0; i < length; i++) {
		*p_Direction = 0;
		if (RequestedFloor[i] != 0||KnownDestation[i]!=0) {
			*p_Direction = 1;
			break;
		}
	}
}
int foundNumber(int* array, int key, int length) {
	int ret = -1;
	for (int i = 0; i < MaxHeadCount; i++) {
		if (array[i] == key) {
			ret = i;
		}
	}
	return ret;
}

int isQuit(int* KnownDestation, int* RequestedFloor,int* WaitingFloor) {
	int ret = 0;
	for (int i = 0; i < MaxHeadCount; i++) {
		if (KnownDestation[i] != 0 || RequestedFloor[i] != 0||WaitingFloor[i]!=0) {
			ret = 1;
		}
	}
	return ret;
}

int countNumberInArray(int* array, int key,int length) {
	int g_iCount = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] == key)g_iCount++;
	}
	return g_iCount;
}