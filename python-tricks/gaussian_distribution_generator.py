#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: gaussian_distribution_generator.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/09/27
#	> Detail: 使用Box-Muller算法模拟正态分布随机生成器
#########################################################################

import numpy as np
import matplotlib.pyplot as plt

def getNormal(SampleSize):
    iid = np.random.uniform(0, 1, SampleSize)
    # Box-Muller算法
    normal1 = np.cos(2*np.pi*iid[0:SampleSize/2-1])*np.sqrt(-2*np.log(iid[SampleSize/2:SampleSize-1]))
    normal2 = np.sin(2*np.pi*iid[0:SampleSize/2-1])*np.sqrt(-2*np.log(iid[SampleSize/2:SampleSize-1]))

    return np.hstack((normal1,normal2)) 

if __name__ == '__main__':
    SampleSize = 10000000
    normal = getNormal(SampleSize)

    print(normal.shape)
    for i in range(0, 10):
        print(normal[i])
    plt.hist(normal, np.linspace(-4,4,81), facecolor='green')
    plt.savefig('./tmp.pdf')
    print('Done!')
