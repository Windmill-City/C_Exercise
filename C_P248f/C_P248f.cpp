// C_P248f.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct library {
    library(int accession, string title, string author, float price, bool issued) {
        AccessionNumber = accession;
        Title = title;
        AuthorName = author;
        Price = price;
        Issued = issued;
    }
    int AccessionNumber;
    string Title;
    string AuthorName;
    float Price;
    bool Issued;
};

vector<library*>* libraries = new vector<library*>();

bool handleMenu() {
    Start:
    printf("Choose by menu number:");
    int menu;

    int AccessionNumber;
    char Title[21];
    char AuthorName[21];
    float Price;
    bool Issued;
    int IssuedInput;

    scanf_s("%d", &menu);
    switch (menu)
    {
    case 1:
        printf("Input Accession Number:");
        scanf_s("%d", &AccessionNumber);
        printf("Input Title:");
        cin.clear();
        cin.ignore();
        cin.getline(Title, 20);
        printf("Input Author Name:");
        cin.getline(AuthorName, 20);
        printf("Input Price:");
        scanf_s("%f", &Price);
        StartIssued:
        printf("Input Issued:(0=false/1=true)");
        scanf_s("%d", &IssuedInput);
        if (IssuedInput != 0 && IssuedInput != 1) {
            goto StartIssued;
        }
        else {
            Issued = IssuedInput == 1;
        }
        libraries->push_back(new library(AccessionNumber, Title, AuthorName, Price, Issued));
        break;
    case 2:
        for (size_t i = 0; i < libraries->size(); i++)
        {
            library* book = libraries->at(i);
            printf("Accession Number:%d\n", book->AccessionNumber);
            printf("Title:%s\n", book->Title.c_str());
            printf("Author Name:%s\n", book->AuthorName.c_str());
            printf("Price:%f\n", book->Price);
            printf("Issued:%s\n", book->Issued ? "true" : "false");
        }
        break;
    case 3:
        printf("Input the Author Name:");
        cin.clear();
        cin.ignore();
        cin.getline(AuthorName, 20);
        for (size_t i = 0; i < libraries->size(); i++)
        {
            library* book = libraries->at(i);
            if (book->AuthorName == AuthorName) {
                printf("Accession Number:%d\n", book->AccessionNumber);
                printf("Title:%s\n", book->Title.c_str());
                printf("Author Name:%s\n", book->AuthorName.c_str());
                printf("Price:%f\n", book->Price);
                printf("Issued:%s\n", book->Issued ? "true" : "false");
            }
        }
        break;
    case 4:
        printf("Input Accession Number:");
        scanf_s("%d", &AccessionNumber);
        for (size_t i = 0; i < libraries->size(); i++)
        {
            library* book = libraries->at(i);
            if (book->AccessionNumber == AccessionNumber) {
                printf("Title:%s\n", book->Title.c_str());
            }
        }
        break;
    case 5:
        printf("Count:%d\n", libraries->size());
        break;
    case 6:
        sort(libraries->begin(), libraries->end(), [](library* var1, library* var2) {
            return var1->AccessionNumber < var2->AccessionNumber;
            });
        for (size_t i = 0; i < libraries->size(); i++)
        {
            library* book = libraries->at(i);
            printf("Accession Number:%d\n", book->AccessionNumber);
            printf("Title:%s\n", book->Title.c_str());
            printf("Author Name:%s\n", book->AuthorName.c_str());
            printf("Price:%f\n", book->Price);
            printf("Issued:%s\n", book->Issued ? "true" : "false");
        }
        break;
    case 7:
        return false;
    default:
        printf("Wrong number, choose again!\n");
        goto Start;
    }
    return true;
}

void drawMenu() {
    printf("1.Add book infomation\n");
    printf("2.Display book infomation\n");
    printf("3.List all books of given author\n");
    printf("4.List the title of specified book\n");
    printf("5.List the count of books in the library\n");
    printf("6.List the books in the order of accession number\n");
    printf("7.Exit\n");
}

int main()
{
    drawMenu();
    while (handleMenu())
    {
        drawMenu();
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
