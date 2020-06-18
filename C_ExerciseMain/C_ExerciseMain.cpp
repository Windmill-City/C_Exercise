// C_ExerciseMain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <regex>
#include <stdio.h>
#include <io.h>
#include <string>
int getChapterByPage(int page) {
    if (page >=31 && page <=59)
        return 2;
    if (page >=61 && page <=83)
        return 3;
    if (page >=85 && page <=96)
        return 4;
    if (page >=98 && page <=131)
        return 5;
    if (page >=133 && page <=151)
        return 6;
    if (page >=153 && page <=171)
        return 7;
    if (page >=173 && page <=209)
        return 8;
    if (page >=211 && page <=230)
        return 9;
    if (page >=232 && page <=248)
        return 10;
    if (page >=250 && page <=262)
        return 11;
    if (page >=264 && page <=293)
        return 12;
    throw "IllegalArg:" + page;
}
std::regex FILENAME = std::regex("C_P?([0-9]+)([^.]+).exe");
using namespace std;
struct Item
{
    Item(int page, int chapter, string serialNumber, string location) {
        this->page = page;
        this->chapter = chapter;
        this->serialNumber = serialNumber;
        this->location = location;
    }
    int page;
    int chapter;
    string serialNumber;
    string location;
};
void drawChapter() {
    system("cls");
    for (size_t i = 2; i < 13; i++)
    {
        printf("Chapter %d\n", i);
    }
}
void runLocation(std::string location) {
    system(location.c_str());
}
using namespace std;
void handleChapter(vector<Item*> items) {
ReInput:
    cin.clear();
    printf("Input the chapter which to view");
    int chapter;
    scanf_s("%d", &chapter);
    if (chapter < 2 || chapter > 12)
        goto ReInput;
    vector<Item*> cur_items = vector<Item*>();
    for (size_t i = 0; i < items.size(); i++)
    {
        Item* item = items[i];
        if (item->chapter == chapter) {
            cur_items.push_back(item);
        }
    }
ReInputItemNum:
    system("cls");
    printf("Chapter %d\n", chapter);
    for (size_t i = 0; i < cur_items.size(); i++)
    {
        printf("[%d] %s\n", i, cur_items[i]->serialNumber.c_str());
    }
    printf("[%d] Exit\n", cur_items.size());
    cin.clear();
    printf("Input the item num which to run");
    int item_num;
    scanf_s("%d", &item_num);
    if (item_num < 0 || item_num > cur_items.size())
        goto ReInputItemNum;
    if (item_num == cur_items.size())
        return;
    runLocation(cur_items.at(item_num)->location);
    printf("\nContinue...");
    cin.clear();
    getchar();
    getchar();
    goto ReInputItemNum;
}
using namespace std;
int main()
{
    std::string inPath = "./*.exe";
    std::smatch matchResult;
    long handle;
    struct _finddata_t fileinfo;
    handle = _findfirst(inPath.c_str(), &fileinfo);
    if (handle == -1)
        return -1;
    vector<Item*> items = vector<Item*>();
    do
    {
        string name = fileinfo.name;
        if (regex_match(name, matchResult, FILENAME)) {
            printf("Found %s\n", fileinfo.name);
            int page = atoi(matchResult[1].str().c_str());
            items.push_back(new Item(page, getChapterByPage(page), matchResult[2].str(), name));
        }

    } while (!_findnext(handle, &fileinfo));

    _findclose(handle);
    while (true)
    {
        drawChapter();
        handleChapter(items);
    }
    system("pause");
    return 0;
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
