// C_P197De.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <wtypes.h>
#include<time.h>

int* GetRandomNums(UINT limit) {
    int* result = new int[limit]();
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < limit; i++)
    {
        result[i] = rand();
    }
    return result;
}

void Swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int* ChangeOddAndEven(int* array, UINT len) {
    if (len % 2 == 0) {
        for (size_t i = 0; i < len - 1; i = i + 2)
        {
            Swap(&array[i], &array[i + 1]);
        }
    }
    return array;
}

int main()
{
    int count = 4;
    int* nums = GetRandomNums(count);

    for (size_t i = 0; i < count; i++)
    {
        printf("%d\n", nums[i]);
    }

    ChangeOddAndEven(nums, count);
    printf("After change\n");
    for (size_t i = 0; i < count; i++)
    {
        printf("%d\n", nums[i]);
    }
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
