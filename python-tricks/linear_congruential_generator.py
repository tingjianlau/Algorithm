#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: linear_congruential_generator.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/09/27
#	> Detail: 模拟线性同余随机数生成器
#########################################################################
import numpy as np
import math
import time

class LCG:
    def __init__(self, seed = 1):
        self.seed = seed

    def rand(self, num):
        m = math.pow(2, 32)
        a = 214013
        c = 2531011
        x = np.zeros(num)
        x[0] = self.seed
        for i in range(1, num):
            x[i] = (a * x[i-1] + c) % m

        return x

if __name__ == '__main__':
    # seed的设置一样的话，起返回的伪随机数也是一样的
    # 因此，使用当前的系统时间最为尾随机器的seed是理想的
    lcg = LCG(time.time())
    rands = lcg.rand(10000)
    # 生成均匀的0-9的随机数
    cnt = []
    for i in range(0, 10):
        cnt.append(0)

    for i in range(len(rands)):
        cnt[int(rands[i]%10)] += 1

    print(cnt)
