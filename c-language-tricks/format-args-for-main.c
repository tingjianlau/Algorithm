// Tingjian Lau 
// 2016/5/9
// 在Linux命令行下，为main函数传递带注释的参数
// 总结自word2vec.c源码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ArgPos(char *str, int argc, char** argv){
    int a;
    for(a = 1; a < argc; a++){
     	if (!strcmp(str, argv[a])) {
            if(a == argc - 1) {
                printf("Argument missing for %s\n", str);
                exit(1);
            }
            return a;
        }
    }

    return -1;
}

int main(int argc, char** argv){
    int i;
    int a;
    float b;

    // 没有传参时，打印参数说明
    if(argc == 1){
        printf("功能：实现两个数的相乘\n");
        printf("参数说明:\n");
        printf("\t-a <int>\n");
        printf("\t\ta是乘数\n");
        printf("\t-b <float>\n");
        printf("\t\tb是被乘数\n");
        printf("\nExample:\n");
        printf("./function-name -a 3 -b 2.0\n\n");

        return 0;
    }
    
    // 获取参数
    if ((i = ArgPos((char *)"-a", argc, argv)) > 0)
        a = atoi(argv[i + 1]);	
    if ((i = ArgPos((char *)"-b", argc, argv)) > 0)
        b = atof(argv[i + 1]);	

    // 后续基于获取的参数的操作
    printf("\n%d * %f = %f\n", a, b, a * b);

    printf("\nDone!\n");

    return 0;		
}
