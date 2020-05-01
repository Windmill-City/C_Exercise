// C_P130Jb.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector> 
std::vector<int> getPrimer(int* num);

int main()
{
	printf("Input a number");
	int input;
	scanf_s("%d", &input);
	std::vector<int> result = getPrimer(&input);
	for (int i = 0; i < result.size(); i++)
	{
		printf("%d", result[i]);
		if (i < result.size() - 1) {
			printf(" x ");
		}
	}
}

bool isPrimer(int a) {
	bool yes = true;
	if (a < 2) yes = false;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			yes = false;
			break;
		}
	}
	return yes;
}

std::vector<int> getPrimer(int* num) {
	if (isPrimer(*num) || *num <= 1) {
		std::vector<int> result = std::vector<int>();
		result.push_back(*num);
		return result;
	}
	int temp = *num;
	while (true)
	{
		if (isPrimer(temp) && *num % temp == 0) {
			break;
		}
		temp--;
	}
	int next = *num / temp;
	std::vector<int> result = getPrimer(&next);
	result.push_back(temp);
	return result;
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
