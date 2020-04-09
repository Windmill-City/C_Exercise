// C_P79f.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>

int main()
{
    bool gamefinished = false;
	int sticks = 21;
	int min_pickup = 1;
	int max_pickup = 4;

	printf("There are %d sticks,you can pick up %d - %d sitck(s) at a time\n", sticks, min_pickup, max_pickup);
	printf("Whoever pickup the last stick will lose\n");
	while (!gamefinished)
	{
		printf("Take sticks(%d-%d)", min_pickup, std::min(max_pickup,sticks));

		int num;
		int computer_take;
		//handle input
		scanf_s("%d", &num);
		rewind(stdin);//clear buffer
		//vertify input
		if (num > std::min(max_pickup, sticks) || num < min_pickup)
			goto WrongPickup;
		//output state
		printf("You picked up %d stick(s)\n", num);
		sticks -= num;
		printf("Sticks left:%d\n", sticks);
		if (sticks == 0) {
			gamefinished = true;
			printf("You lost");
			break;
		}
		//computer take
		computer_take = 5 - num;
		sticks -= computer_take;
		printf("Computer picked up %d stick(s)\n", computer_take);
		printf("Sticks left:%d\n", sticks);
		if (sticks == 0) {
			gamefinished = true;
			printf("Computer lost");
			break;
		}
		continue;
	WrongPickup:
		printf("Wrong pickup\n");
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
