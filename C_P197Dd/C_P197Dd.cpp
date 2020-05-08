// C_P197Dd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <wtypes.h>
#include<time.h>
int* GetRandomNums(UINT limit) {
	int* result = new int[limit]();
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < limit; i++)
	{
		result[i] = rand() % 2 == 0 ?  rand() : -rand();
		printf("%d\n", result[i]);
	}
	return result;
}

int* InputNums(UINT limit) {
	int len = (int)limit;
	int* num_arr = new int[len];
	printf("Input %u number.\n", limit);
	for (int i = 0; i < len; i++)
	{
		printf("Current:%d\n", i);
		scanf_s("%d", &num_arr[i]);
	}
	return num_arr;
}

int CountPositive(int* array, UINT len) {
	int positives = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (array[i] > 0)
			positives++;
	}
	return positives;
}

int CountNegative(int* array, UINT len) {
	int negatives = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (array[i] < 0)
			negatives++;
	}
	return negatives;
}

int CountEven(int* array, UINT len) {
	int evens = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (array[i] % 2 == 0)
			evens++;
	}
	return evens;
}

int CountOdd(int* array, UINT len) {
	int odds = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (array[i] % 2 != 0)
			odds++;
	}
	return odds;
}

int main()
{
	int count = 25;
	int* nums = InputNums(count);
	printf("Positives:%d\n", CountPositive(nums, count));
	printf("Negatives:%d\n", CountNegative(nums, count));
	printf("Evens:%d\n", CountEven(nums, count));
	printf("Odds:%d\n", CountOdd(nums, count));
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
