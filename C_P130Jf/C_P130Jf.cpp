// C_P130Jf.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
int factorial(int num) {
    int a = 1;
    for (int i = 1; i < num; i++) {
        a = a * (i + 1);
    }
    return a;
}

double ssin(double t) {
    bool flag = true;//T减法，F加法
    t = 3.14159265 / (180 / t);//换算成弧度
    double result = t;
    double a = 0, b = 0;
    double oddnum = 0;
    int i = 0;
    while (true) {
        oddnum = 2 * (i + 1) + 1;
        a = pow(t, oddnum);
        b = (double)factorial(oddnum);
        if (flag) {
            double temp = result - (a / b);
            if (abs(result - temp) < 0.00001) {
                return temp;
            }
            result = temp;
            flag = false;
        }
        else {
            double temp = result + (a / b);
            if (abs(result - temp) < 0.00001) {
                return temp;
            }
            result = temp;
            flag = true;
        }
        i++;
    }
    return result;
}

int main()
{
	printf("%.5f", ssin(280));
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
