// C_P197Db.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int* SelectionSort(int* nums, UINT len) {
	for (size_t i = 0; i < len; i++)
	{
		int min = i;
		for (size_t j = i + 1; j < len; j++)
		{
			if (nums[j] < nums[min]) {
				min = j;
			}
		}
		Swap(&nums[i], &nums[min]);
	}
	return nums;
}

int* BubbleSort(int* nums, UINT len) {
	bool sorted = false;
	int tail = len;
	while (!sorted) {
		sorted = true;
		for (size_t i = 0; i < tail - 1; i++)
		{
			if (nums[i] > nums[i + 1]) {
				Swap(&nums[i], &nums[i + 1]);
				sorted = false;
			}
		}
		tail--;
	}
	return nums;
}

int* InsertSort(int* nums, UINT len) {
	for (size_t i = 1; i < len; i++)
	{
		for (size_t j = i; j > 0 && nums[j - 1] > nums[j]; j--)
		{
			Swap(&nums[j - 1], &nums[j]);
		}
	}
	return nums;
}

int main()
{
	int times = 0;
	bool hasUnsort = false;
	while (times < 100) {
		int* nums = GetRandomNums(25);
		InsertSort(nums, 25);
		for (size_t i = 0; i < 1; i++)
		{
			if (i - 1 >= 0 && nums[i] < nums[i - 1])
			{
				hasUnsort = true;
			}
			printf("%d\n", nums[i]);
		}
		times++;
	}
	printf("HasUnsort:%d", hasUnsort);
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
