// C_P204Lb.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <wtypes.h>
#include<time.h>
#define DEBUG

int* GetRandomNums(UINT limit) {
    int* result = new int[limit]();
    for (size_t i = 0; i < limit; i++)
    {
        result[i] = rand();
#ifdef DEBUG
        printf("%d\n", result[i]);
#endif
    }
#ifdef DEBUG
    printf("------------\n");
#endif
    return result;
}

int** GetArray(int column, int row) {
    srand((unsigned)time(NULL));
    int** result = new int*[row]();
    for (size_t i = 0; i < row; i++)
    {
        result[i] = GetRandomNums(column);
    }
    return result;
}

int* findLargest(int** in, int column, int row)
{
#ifdef DEBUG
    printf("------Start Find------\n");
#endif
    int* largest = NULL;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            if (largest == NULL)
                largest = &(in[i][j]);
            else if(*largest < in[i][j])
                largest = &(in[i][j]);
#ifdef DEBUG
            printf("%d\n", in[i][j]);
#endif
        }
    }
#ifdef DEBUG
    printf("------Found------\n");
#endif
    return largest;
}
int main()
{
    int** toFind = GetArray(5, 5);
    printf("%d", *findLargest(toFind, 5, 5));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
