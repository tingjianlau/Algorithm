#include <stdio.h>
#include <stdlib.h>

/**************************
不同场景下可能需修改的全局变量
****************************/
#define	K			6
#define	TRAIN_CNT		150			// 训练样本数量
#define	TRAIN_PATH	"iris.data"	// 训练样本文件路径
#define	TEST_CNT		150			// 测试样本数量
#define TEST_PATH	"test.data"		// 测试样本文件路径
#define	CLASS_CNT	 3				// 样本类别种数
#define	FEATURE_CNT	 4				// 单个样本特征数

/**************************
全局结构
***************************/
struct SAMPLE_ST {
	double	fv[FEATURE_CNT];
	int		iClass;
};

/**************************
	简单KNN分类器
	@param int K的值
    @param struct SAMPLE_SET 训练集合
	@param int 训练集合的大小
    @param struct SAMPLE_SET 当前测试样例
	@param int 类别个数
	@param int 样本的特征数
***************************/
int basicKnnClassifier(int, struct SAMPLE_ST*, int, struct SAMPLE_ST, int, int);
