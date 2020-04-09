// C_P82f.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    for (int i = 7; i > 0; i--) {
        int alpha = 0;
        for (int j = 0; j <= 14; j++) {
            alpha++;
            int k = alpha;
            if ((k > i && k <= 7) || (-(k - 14) > i && k > 7))
                k = 0;
            switch (k)
            {
            case 1:
            case 13:
                printf("A");
                break;
            case 2:
            case 12:
                printf("B");
                break;
            case 3:
            case 11:
                printf("C");
                break;
            case 4:
            case 10:
                printf("D");
                break;
            case 5:
            case 9:
                printf("E");
                break;
            case 6:
            case 8:
                printf("F");
                break;
            case 7:
                printf("G");
                break;
            default:
                printf(" ");
                break;
            }
        }
        printf("\n");
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
