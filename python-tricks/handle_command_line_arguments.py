#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##########################################################################
#	> File Name: git_auto_commit.py
#	> Author: Tingjian Lau
#	> Mail: tjliu@mail.ustc.edu.cn
#	> Created Time: 2016/05/15
#       > Detail: python命令行参数处理
#########################################################################

import os, sys, getopt
from os import system

def usage():
    print sys.argv[0], 'usage:'
    # 在此加入需要添加的命令行参数使用方式
    print '\t', '-m, --msg: the msg for commit' 
    print '\t', '-h, --help: print help msg' 

if __name__ == '__main__':
    try:
        # 加入命令行参数，如果参数options后面需要传入参数的话，必须以':'结尾，同理参数long_options后要以'='结尾
        opts, args = getopt.getopt(sys.argv[1:], 'hm:', ['help', 'msg='])
    except getopt.GetoptError as err:
        # print help infomation and exit:
        print(err)
        usage()
        sys.exit(2)
    msg = ''
    if len(opts) == 0:
        usage()
        sys.exit()
    for opt, arg in opts:
        if opt in ('-h', '--help'):
            usage()
            sys.exit()
        elif opt in ('-m', '--msg'):
            msg = arg
        else:
            assert False, 'unhandled option'
    
    print msg
