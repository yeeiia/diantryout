#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int indexOfMaximum(int* array, int length);
int indexOfMinimum(int* array, int length);
void isElevatorUp(int* KnownDestation, int* RequestedFloor, int* g_iDirection, int length, int Elevator);//look算法中判断是否要向上的代码
void isElevatorDown(int* KnownDestation, int* RequestedFloor, int* g_iDirection, int length, int Elevator);
void isElevatorWait(int* KnownDestation, int* RequestedFloor, int* Waitingfloor, int length, int* p_Direction);
int foundNumber(int* array, int key, int length);//判断数组是否存在某个数(不存在返回-1)并返回数组中某个值的下标
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
	int iOverloadRequestFloor[10000] = { 0 };//超载时不再上人
	int iIntervalTime[10000] = { 0 };
	int iWaitingFloor[10000] = { 0 }; 
	printf("请输入电梯初始楼层\n");
	scanf("%d", &g_iElevator);
	printf("请输入起始楼层和目的楼层以及等待时间，结束请输入q\n");
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
		isElevatorWait(iKnownDestationFloor, iRequestedFloor, iWaitingFloor, MaxHeadCount, &g_iDirection);//函数中若不等候就把方向改为1
		isElevatorUp(iKnownDestationFloor, iRequestedFloor, &g_iDirection, MaxHeadCount, g_iElevator);//检查默认方向为1是否正确
		if (g_iDirection == 0) {
			g_iTime++;
			for (int i = 0; i < MaxHeadCount; i++) {
				if (iIntervalTime[i] >= 0) {
					iIntervalTime[i] -= 1;
				}
			}
		}
		if (g_iDirection == 1) {//向上
			if (g_iCount < 4) {
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
					iKnownDestationFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = iUnknownDestation[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)];//赋值iKnownDestationFloor
					g_iCount++;
				}
				if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
					int subtract = countNumberInArray(iKnownDestationFloor, g_iElevator,MaxHeadCount);
					g_iCount -= subtract;
				}
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
					printf("电梯在第%d层，运行了%d个单位时间，电梯里有%d个人\n", g_iElevator, g_iTime, g_iCount);
				}
				do {
					if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
						iKnownDestationFloor[foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)] = 0;
					}
				} while (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1);
				if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
					iRequestedFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = 0;
				}//清空数据
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
			else {//超载的处理结果
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
		else {//向下
			if (g_iDirection == -1) {
				if (g_iCount < 4) {
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1) {
						iKnownDestationFloor[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)] = iUnknownDestation[foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount)];//赋值iKnownDestationFloor
						g_iCount++;
					}
					if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
						int subtract = 0;
						subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
						g_iCount -= subtract;
					}
					if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
						printf("电梯在第%d层，运行了%d个单位时间，电梯里有%d个人\n", g_iElevator, g_iTime, g_iCount);
					}
					do {
						if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
							iKnownDestationFloor[foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount)] = 0;
						}
					} while (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1);//g_iElevator=0时死循环，所以要立即掉头
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
				else {//超载时
					if (g_iDirection == -1) {
						if (foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
							int subtract = countNumberInArray(iKnownDestationFloor, g_iElevator, MaxHeadCount);
							g_iCount -= subtract;//只下不上
						}
						if (foundNumber(iRequestedFloor, g_iElevator, MaxHeadCount) != -1 || foundNumber(iKnownDestationFloor, g_iElevator, MaxHeadCount) != -1) {
							printf("电梯在第%d层，运行了%d个单位时间，电梯里有%d个人\n", g_iElevator, g_iTime, g_iCount);
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
						if (g_iDirection == 1)continue;//立即掉头	
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
	for (int i = 1; i < length; i++) {//int i=0则多循环一次,attention
		if (array[i] > array[ret]) {
			ret = i;
		}
	}
	return ret;
}


int indexOfMinimum(int* array, int length) {//要找出非零的最小值
	int iNonZeroCount = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] != 0) {
			iNonZeroCount++;
		}
	}
	if (iNonZeroCount != 0) {//防止数组全为零
		int ret = -1;
		//for (int x = 0; x < length; x++) {if (KnownDestation[x] != 0)ret = x;}有更简单的初始化
		for (int t = 0; t < length; t++) {
			if (array[t] == 0) {
				continue;
			}
			if (ret == -1) {
				ret = t;
			}//防止ret没有值!!
			if (array[t] != 0 && array[t] < array[ret]) {
				ret = t;
			}
			return ret;
		}
	}
	else return -1;//注意使用时要判断，不然会引发越界!!!
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
	}//当两个都为零时死循环,这和1-3不同
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