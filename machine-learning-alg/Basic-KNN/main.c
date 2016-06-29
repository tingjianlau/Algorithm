/*************************************************************************
	> File Name: main.c
	> Author: Tingjian Lau
	> Mail: tjliu@mail.ustc.edu.cn
	> Created Time: 2016/06/29
	> Detail: ����K�����㷨��ʵ��
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "struct.h"
#include <string.h>

/**************************
����ԭ��
***************************/
void	loadData(const char*, int, struct SAMPLE_ST*);


int main() {
	int	i, j, k, kk, label, errCnt = 0;
	struct SAMPLE_ST curTest;
	struct SAMPLE_ST* tempSet = (struct SAMPLE_ST*)calloc(TRAIN_CNT - 1, sizeof(struct SAMPLE_ST));
	struct SAMPLE_ST* trainSet = (struct SAMPLE_ST*)calloc(TRAIN_CNT, sizeof(struct SAMPLE_ST));

	// ����ѵ���Ͳ�����������
	loadData(TRAIN_PATH, TRAIN_CNT, trainSet);

	// ��һ��
	for ( i = 0; i < TRAIN_CNT; i++)
	{
		curTest = trainSet[i];
		// ȥ����ǰ������ʣ��������䵱ѵ������
		for ( j = 0, k=0; j < TRAIN_CNT; j++)
		{
			if (j!=i)
			{
				tempSet[k++] = trainSet[j];
				
			}
		}
		label = basicKnnClassifier(K, tempSet, TRAIN_CNT - 1, curTest, CLASS_CNT, FEATURE_CNT);
		if (label != curTest.iClass)
		{
			printf("error->%d    ", i);
			errCnt++;
		}
	}

    printf("\nWhen the value of K is %d:\n", K);
	printf("Total Test Samples:%d, Error count:%d, Error Rate:%lf \n", TEST_CNT, errCnt, errCnt / (TEST_CNT*1.0));

	free(trainSet);
	free(tempSet);
	return 0;
}

/**************************
����ѵ���Ͳ�������
param trainSrc	ѵ�������ļ�·��
param trainCnt	ѵ����������
***************************/
void	loadData(const char* trainSrc, int trainCnt, struct SAMPLE_ST* trainSet) {
	int	i, j;
	char	className[20]; 
	FILE	*fpTrain = NULL;

	if ((fpTrain = fopen(trainSrc, "r")) == NULL)
	{
		printf("open file %s failed! \n", trainSrc);
		exit(0);
	}

	// ����ѵ������
	for (i = 0; i < trainCnt; i++)
	{
		for (j = 0; j < FEATURE_CNT; j++)
		{
			fscanf(fpTrain, "%lf,", &trainSet[i].fv[j]);
		}
		fscanf(fpTrain, "%s", className);
		if (strcmp(className, "Iris-setosa") == 0)
		{
			trainSet[i].iClass = 0;
		}
		else if (strcmp(className, "Iris-versicolor") == 0)
		{
			trainSet[i].iClass = 1;
		}
		else if (strcmp(className, "Iris-virginica") == 0)
		{
			trainSet[i].iClass = 2;
		}
	}

	fclose(fpTrain);
}
