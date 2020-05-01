// C_P130Ja.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int sum(int num);
int sum_recursion(int* num);

int main()
{
	printf("Input a 5-digit number:\n");
	int num;
	scanf_s("%d", &num);
	if (num >= 10000) {
		printf("%d\n",sum(num));
		printf("%d\n", sum_recursion(&num));
		return 0;
	}
	printf("Not a 5-digit number");
}
int sum(int num) {
	int var1 = num % 10;
	num -= var1;
	int var2 = num % 100 / 10;
	num -= var2;
	int var3 = num % 1000 / 100;
	num -= var3;
	int var4 = num % 10000 / 1000;
	num -= var4;
	int var5 = num % 100000 / 10000;
	return var1 + var2 + var3 + var4 + var5;
}
int sum_recursion(int* num) {
	if (*num < 10)
		return *num;
	int digit = *num % 10;
	*num /= 10;
	int sum = sum_recursion(num);
	return sum + digit;
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
