// C_P126De.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primeFactor(int n, vector<int>& ob)
{
    if (isPrime(n))
    {
        ob.push_back(n);
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                ob.push_back(i);
                primeFactor(n / i, ob);
                break;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Input a positive Integer：";
    cin >> n;
    cout << endl;

    if (n == 1)
    {
        cout << "1 neither a prime nor composite" << endl;
        return 0;
    }
    if (isPrime(n))
    {
        cout << n << "is prime!" << endl;
        return 0;
    }

    vector<int> result;
    primeFactor(n, result);
    sort(result.begin(), result.end());
    cout << n << " = ";
    for (int i = 0; i < result.size(); i++)
    {
        if (i == result.size() - 1)
        {
            cout << result[i] << endl;
        }
        else
        {
            cout << result[i] << " * ";
        }
    }
    cout << endl;
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
