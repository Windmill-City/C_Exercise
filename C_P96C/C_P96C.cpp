// C_P96C.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void FactorialOfNumber() {
	printf("Input a number:");
	int num;
	//handle input
	scanf_s("%d", &num);
	rewind(stdin);//clear buffer
	int temp = 1;
	for (int j = num; j > 1; j--) {
		temp *= j;
	}
	printf("Number:%d Result:%d\n", num, temp);
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
void PrimeOrNot() {
	printf("Input a number:");
	int num;
	//handle input
	scanf_s("%d", &num);
	rewind(stdin);//clear buffer
	printf("Number:%d isPrime:%s\n", num, isPrimer(num) ? "true" : "false");
}

void OddOrEven() {
	printf("Input a number:");
	int num;
	//handle input
	scanf_s("%d", &num);
	rewind(stdin);//clear buffer
	printf("Number:%d It's a %s\n", num, num % 2 ? "Odd" : "Even");
}

int main()
{
	bool ShouldExit = false;
	while (!ShouldExit)
	{
		printf("[1]Factorial of a number\n");
		printf("[2]Prime or not\n");
		printf("[3]Odd or even\n");
		printf("[4]Exit\n");

		printf("Chosse a option[1-4]:");
		int num;
		//handle input
		scanf_s("%d", &num);
		rewind(stdin);//clear buffer
		switch (num)
		{
		case 1:
			FactorialOfNumber();
			break;
		case 2:
			PrimeOrNot();
			break;
		case 3:
			OddOrEven();
			break;
		case 4:
			ShouldExit = true;
			break;
		default:
			printf("Wrong choice\n");
			break;
		}
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
