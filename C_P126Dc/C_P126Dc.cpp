// C_P126Dc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

std::string convertToRoman(int in) {
	int values[] = { 1000,500,100,50,10,5,1 };
	std::string roman = "";
	for (int i = 0; i < 7; i++)
	{
		int result = in / values[i];
		in %= values[i];

		switch (values[i])
		{
		case 1000:
			roman.append(result,'m');
			break;
		case 500:
			roman.append(result, 'd');
			break;
		case 100:
			roman.append(result, 'c');
			break;
		case 50:
			roman.append(result, 'l');
			break;
		case 10:
			roman.append(result, 'x');
			break;
		case 5:
			roman.append(result, 'v');
			break;
		case 1:
			roman.append(result, 'i');
			break;
		default:
			break;
		}
	}
	return roman;
}

int main()
{
	printf("Input a year to convert to roman\n");
	int year;
	scanf_s("%d", &year);
	printf("Year:%d Roman:%s", year, convertToRoman(year).c_str());
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
