#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

/**************************
函数原型
***************************/
double*		caculateDistance(struct SAMPLE_ST* trainSet, int trainCnt, struct SAMPLE_ST curTest, int featrueCnt);
void    getNearestSet(int k, double* distance, int*, int trainCnt);
void    quickSort(double* A, int p, int r, int*);
int		getExtremumIndex(const int nums[], int numsSize, int mode);
int	    decisionRule(int k, int* indexList, struct SAMPLE_ST* trainSet, int trainCnt, int classCnt);
/**************************
KNN分类器
***************************/
int basicKnnClassifier(int k, struct SAMPLE_ST* trainSet, int trainCnt, struct SAMPLE_ST curTest, int classCnt, int featrueCnt) {
	int i, j, g, f;
	double*	distanceSet = NULL;
	double* nearestSet = NULL;
	int* indexList = (int*)malloc(trainCnt*sizeof(int));
	double temp = 0;
	int	isClass;
	int errCnt = 0;
	// 循环每个测试样例
	for (j = 0; j < trainCnt; j++)
	{
		indexList[j] = j;   // 用于跟踪记录排序后的原始训练集合的索引
	}

	distanceSet = caculateDistance(trainSet, trainCnt, curTest, featrueCnt);
	/*for (i = 0; i < trainCnt; i++)
	{
		if (i % 5 == 0)
		{
			printf("\n");
		}
		printf("%lf ", distanceSet[i]);

	}*/
	getNearestSet(k, distanceSet, indexList, trainCnt);
	isClass = decisionRule(k, indexList, trainSet, trainCnt, classCnt);

	free(indexList);
	free(distanceSet);
	free(nearestSet);

	return isClass;
}

/**************************
计算当前测试样例和每个训练样例之间的欧式距离

param return	返回距离矩阵
***************************/
double*	caculateDistance(struct SAMPLE_ST* trainSet, int trainCnt, struct SAMPLE_ST curTest, int featrueCnt) {
	int	i, j;
	double* dis = (double*)calloc(trainCnt, sizeof(double));

	for (i = 0; i < trainCnt; i++)
	{
		for (j = 0; j < featrueCnt; j++)
		{
			dis[i] += (trainSet[i].fv[j] - curTest.fv[j]) * (trainSet[i].fv[j] - curTest.fv[j]);
		}
	}

	return dis;
}

/**************************
选择离测试样例最近的k个训练样本的集合
indexList的前k个元素即为要求子集在原始训练集合中的索引
***************************/
void    getNearestSet(int k, double* distanceSet, int* indexList, int trainCnt) {
	quickSort(distanceSet, 0, trainCnt - 1, indexList);
}

/**************************
决策函数，采用多数表决法
***************************/
int	decisionRule(int k, int* indexList, struct SAMPLE_ST* trainSet, int trainCnt, int classCnt) {
	int* isClass = (int*)calloc(classCnt, sizeof(int)); // 用来统计各个类的个数
	int i;

	for (i = 0; i < k; i++)
	{
		//printf("%d ", trainSet[indexList[i]].iClass);
		++isClass[trainSet[indexList[i]].iClass];
	}

	//printf("\n");
	return getExtremumIndex(isClass, classCnt, 1); // 返回多数的类
}

void exchange(double* a, double* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

void exchange2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(double* A, int p, int r, int* indexList) {
	double	x = A[r];
	int		i = p - 1, j;

	for (j = p; j < r; j++)
	{
		if (A[j] < x)
		{
			++i;
			exchange(&A[i], &A[j]);
			exchange2(&indexList[i], &indexList[j]);
		}
	}

	exchange(&A[i + 1], &A[r]);
	exchange2(&indexList[i + 1], &indexList[r]);
	return i + 1;
}

/**************************
快排
***************************/
void quickSort(double* A, int p, int r, int* indexList) {
	int	q;
	if (p < r)
	{
		q = partition(A, p, r, indexList);
		quickSort(A, p, q - 1, indexList);
		quickSort(A, q + 1, r, indexList);
	}
}

int		getExtremumIndex(const int nums[], int numsSize, int mode) {
	int i, maxIndex, minIndex;

	maxIndex = minIndex = 0;
	for (i = 0; i<numsSize; ++i) {
		maxIndex = (nums[maxIndex]>nums[i]) ? maxIndex : i;
		minIndex = (nums[minIndex]<nums[i]) ? minIndex : i;
	}

	return (mode == 0) ? minIndex : maxIndex;
}
