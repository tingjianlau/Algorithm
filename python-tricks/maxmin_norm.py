#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: maxmin_norm.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/09/22
#	> Detail: 对list类型的数据做最大最小归一化
#########################################################################

import numpy as np

def minmax_norm(data_set):
    x = np.zeros((len(data_set), len(data_set[0])))  

    for i in range(len(data_set)):
        for j in range(len(data_set[0])):
            x[i, j] = data_set[i][j]

    max = np.amax(x, axis=0)
    min = np.amin(x, axis=0)
    #print(max)
    #print(min)

    for i in range(x.shape[0]):
        x[i] = (x[i] - min) / (max - min)

    return x

if __name__ == '__main__':
    data = np.array([[11, 22, 0, 4],[4, 7, 6, 7], [7, 11,29, 10]])

    dt = minmax_norm(data)
    print(dt)
    

