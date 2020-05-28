// C_P229Fi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
static string& strip(string& s, const string& chars = " ")
{
    s.erase(0, s.find_first_not_of(chars.c_str()));
    s.erase(s.find_last_not_of(chars.c_str()) + 1);
    return s;
}

static void split(const string& s, vector<string>& tokens, const string& delimiters = " ")
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

int main()
{
	string str;
	getline(cin, str);
    vector<string> elements;
    split(str, elements);
    string result = "";
    for (vector<string>::iterator iter = elements.begin(); iter != elements.end(); iter++) {
        string str = *iter;
        if (str.length() > 0 && next(iter) != elements.end()) {
            char* _char = new char[2]();
            _char[0] = toupper(str[0]);
            _char[1] = '\0';
            result.append(_char);
        }
        if (next(iter) == elements.end()) {
            result.append(*iter);
        }
    }
	printf(result.c_str());
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
