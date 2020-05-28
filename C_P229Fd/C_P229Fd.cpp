// C_P229Fd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <conio.h>
#include <iostream>
#include <wtypes.h>
#include <time.h>
#include <string>

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


int getdays(int year, int month)
{
    switch (month)
    {
    case 12:  return 31;
    case 11:  return 30;
    case 10:  return 31;
    case  9:  return 30;
    case  8:  return 31;
    case  7:  return 31;
    case  6:  return 30;
    case  5:  return 31;
    case  4:  return 30;
    case  3:  return 31;
    case  2: 
        if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
            return 29;
               else
            return 28;
    case  1:  return 31;
    case  0:  return 31;//last year Decemeber
    }
}
using namespace std;
string getMonthStr(int month) {
    switch (month)
    {
    case 12:  return "Dec";
    case 11:  return "Nov";
    case 10:  return "Oct";
    case  9:  return "Sep";
    case  8:  return "Aug";
    case  7:  return "Jul";
    case  6:  return "Jun";
    case  5:  return "May";
    case  4:  return "Apr";
    case  3:  return "Mar";
    case  2:  return "Feb";
    case  1:  return "Jan";
    }
}

int ReturnWeekDay(unsigned int iYear, unsigned int iMonth, unsigned int iDay)
{
    int iWeek = 0;
    unsigned int y = 0, c = 0, m = 0, d = 0;

    if (iMonth == 1 || iMonth == 2)
    {
        c = (iYear - 1) / 100;
        y = (iYear - 1) % 100;
        m = iMonth + 12;
        d = iDay;
    }
    else
    {
        c = iYear / 100;
        y = iYear % 100;
        m = iMonth;
        d = iDay;
    }

    iWeek = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;    //蔡勒公式
    iWeek = iWeek >= 0 ? (iWeek % 7) : (iWeek % 7 + 7);    //iWeek为负时取模
    if (iWeek == 0)    //星期日不作为一周的第一天
    {
        iWeek = 7;
    }

    return iWeek;
}

BOOL handleKey(int* year, int* month) {
    int key = getKey();
    switch (key)
    {
    case 72://up
        printf("Prev Year\n");
        if((*year) > 1900)
            (*year)--;
        return true;
    case 80://down
        printf("Next Year\n");
        (*year)++;
        return true;
    case 75://left
        printf("Prev Month\n");
        (*month)--;
        if ((*month) == 0) {
            if ((*year) > 1900) {
                (*month) = 12;
                (*year)--;
            }
            else {
                (*month)++;
            }
        }
        return true;
    case 77://right
        printf("Next Month\n");
        (*month)++;
        if ((*month) == 13) {
            (*month) = 1;
            (*year)++;
        }
        break;
    case 27://esc
        printf("Calender exit...\n");
        return false;
    default:
        return true;
    }
}

void handleKeyBoardInput(int* year, int* month) {
    Again:
    printf("Input a year:");
    scanf_s("%d", year);
    printf("\nInput a month:");
    scanf_s("%d", month);
    if ((*year) >= 1900 && (*month) >= 1 && (*month) <= 12)
        return;
    else
        goto Again;
}

int** getCal(int year, int month) {
    int** Cal = new int*[6];
    int firstWeekDay = ReturnWeekDay(year, month, 1);
    int thisDays = getdays(year, month);
    int prevDays = firstWeekDay - 1;
    int lastDays = getdays(year, month - 1) - prevDays;
    int nextDays = 1;
    int curDay = 1;
    for (size_t i = 0; i < 6; i++)
    {
        Cal[i] = new int[7];
        for (size_t j = 0; j < 7; j++)
        {
            if (prevDays > 0) {
                lastDays++;
                Cal[i][j] = lastDays;
                prevDays--;
            }
            else if (thisDays > 0) {
                Cal[i][j] = curDay;
                curDay++;
                thisDays--;
            }
            else {
                Cal[i][j] = nextDays;
                nextDays++;
            }
        }
    }
    return Cal;
}

void DrawCal(int year, int month) {
    system("cls");
    int** Cal = getCal(year, month);
    printf("                 %s  %d\n", getMonthStr(month).c_str(), year);
    printf("  Mon   Tue   Wed   Thu   Fri   Sat   Sun\n");
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            printf(" %4d ", Cal[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int year, month;
    handleKeyBoardInput(&year, &month);
    DrawCal(year, month);
    while (handleKey(&year, &month))
    {
        DrawCal(year, month);
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
