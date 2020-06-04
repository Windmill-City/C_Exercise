// C_P248g.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct Date
{
    Date(int _date, int _month, int _year) {
        date = _date;
        month = _month;
        year = _year;
    }
    int date;
    int month;
    int year;
};

bool EqualDate(Date* var1, Date* var2) {
    return var1->date == var2->date
        && var1->month == var2->month
        && var1->year == var2->year;
}

void PrintResult(Date* var1, Date* var2)
{
    if (EqualDate(var1, var2)) {
        printf("Equal\n");
    }
    else {
        printf("Unequal\n");
    }
}
int main()
{
    Date* date1 = new Date(1, 1, 2020);
    Date* date2 = new Date(1, 1, 2020);
    Date* date3 = new Date(2, 1, 2020);
    PrintResult(date1, date2);
    PrintResult(date1, date3);
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
