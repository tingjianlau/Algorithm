#include <stdio.h>
#include <stdlib.h>

/**************************
��ͬ�����¿������޸ĵ�ȫ�ֱ���
****************************/
#define	K			6
#define	TRAIN_CNT		150			// ѵ����������
#define	TRAIN_PATH	"iris.data"	// ѵ�������ļ�·��
#define	TEST_CNT		150			// ������������
#define TEST_PATH	"test.data"		// ���������ļ�·��
#define	CLASS_CNT	 3				// �����������
#define	FEATURE_CNT	 4				// ��������������

/**************************
ȫ�ֽṹ
***************************/
struct SAMPLE_ST {
	double	fv[FEATURE_CNT];
	int		iClass;
};

/**************************
	��KNN������
	@param int K��ֵ
    @param struct SAMPLE_SET ѵ������
	@param int ѵ�����ϵĴ�С
    @param struct SAMPLE_SET ��ǰ��������
	@param int ������
	@param int ������������
***************************/
int basicKnnClassifier(int, struct SAMPLE_ST*, int, struct SAMPLE_ST, int, int);
