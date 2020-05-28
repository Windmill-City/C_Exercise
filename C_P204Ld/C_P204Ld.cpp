// C_P204Ld.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <conio.h>
#include <iostream>
#include <wtypes.h>
#include<time.h>
//#define DEBUG

int* GetRandomNums(UINT limit) {
    int* result = new int[limit]();
    for (size_t i = 0; i < limit; i++)
    {
        result[i] = rand();
#ifdef DEBUG
        printf("%d\n", result[i]);
#endif
    }
#ifdef DEBUG
    printf("------------\n");
#endif
    return result;
}

int** GetArray(int column, int row) {
    srand((unsigned)time(NULL));
    int** result = new int* [row]();
    for (size_t i = 0; i < row; i++)
    {
        result[i] = GetRandomNums(column);
    }
    return result;
}

void Swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int getKey() {
using namespace std;
	int ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
            if (ch == 27 || ch == 72 || ch == 80 || ch == 75 || ch == 77)
                break;
		}
	}
	return ch;
}

void DrawMap(int** map, int size) {
    system("cls");
    int len = sqrt(size);
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (map[i][j] != size)
                printf("%3d", map[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

int** genMap(int size) {
    int len = sqrt(size);
    int** map = GetArray(len, len);
    for (size_t i = 0; i < size; i++)
    {
        int row = i / len;
        int column = i % len;
        int current = map[row][column];
        map[row][column] = i + 1;
        if (current % 2 && i != size - 1) {
            Swap(&(map[row][column]), &(map[row][column - 1 < 0 ? column : column - 1]));
            Swap(&(map[row][column]), &(map[row - 1 < 0 ? row : row - 1][column]));
        }
    }
    return map;
}

BOOL handleKey(int** map, int size, int* row, int* col, int* move) {
    int key = getKey();
    int max = sqrt(size) - 1;
    switch (key)
    {
    case 72://up
        printf("Move Up\n");
        if (*row < max) {
            Swap(&(map[*row][*col]), &(map[(*row) + 1][*col]));
            (*row)++;
            (*move)++;
        }
        return true;
    case 80://down
        printf("Move Down\n");
        if (*row > 0) {
            Swap(&(map[*row][*col]), &(map[(*row) - 1][*col]));
            (*row)--;
            (*move)++;
        }
        return true;
    case 75://left
        printf("Move Left\n");
        if (*col < max) {
            Swap(&(map[*row][*col]), &(map[*row][(*col) + 1]));
            (*col)++;
            (*move)++;
        }
        return true;
    case 77://right
        printf("Move Right\n");
        if (*col > 0) {
            Swap(&(map[*row][*col]), &(map[*row][(*col) - 1]));
            (*col)--;
            (*move)++;
        }
        break;
    case 27://esc
        printf("Game exit...\n");
        return false;
    default:
        return true;
    }
}

int main()
{
    Start:
    int size = 16;
    int** map = genMap(size);
    DrawMap(map, size);
    int row, col;
    row = col = sqrt(size) - 1;
    int move = 0;
    bool sorted = false;
    while (!sorted && handleKey(map, size, &row, &col, &move))
    {
        DrawMap(map, size);
        int len = sqrt(size);
        int last = map[0][0];
        sorted = true;
        for (size_t i = 0; i < size && sorted; i++)
        {
            int _row = i / len;
            int column = i % len;
            if (_row == row && col == column)
                continue;
            if (map[_row][column] < last)
                sorted = false;
            last = map[_row][column];
        }
        if (sorted) {
            printf("You Win, you have move %d times.\n", move);
            system("pause");
        }
    }
    if(sorted)
        goto Start;
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
