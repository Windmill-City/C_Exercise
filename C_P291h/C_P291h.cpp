// C_P291h.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void offsetCipher(FILE* in, FILE* out, int offset, bool decrypt) {
	char ch;
	while ((ch = getc(in)) != EOF)
	{
		if (!decrypt)
			ch += offset;
		else
			ch -= offset;
		putc(ch, out);
	}
}
void substitutionCipher(FILE* in, FILE* out, char from, char to, bool decrypt) {
	char ch;
	while ((ch = getc(in)) != EOF)
	{
		if (ch == from && !decrypt)
			ch = to;
		else if (ch == to && decrypt)
			ch = from;
		putc(ch, out);
	}
}
void test(bool decrypt, bool offset) {
	FILE* fp1 = new FILE();
	FILE* fp2 = new FILE();
	errno_t fp1_err = fopen_s(&fp1, decrypt ? "dest.txt" :"source.txt", "r");
	errno_t fp2_err = fopen_s(&fp2, decrypt ? "source.txt" : "dest.txt", "w+");
	if (fp1_err != 0 || fp2_err != 0)
		return;
	offset ? offsetCipher(fp1, fp2, 128, decrypt) : substitutionCipher(fp1, fp2, 'a', 'l', decrypt);
	fflush(fp1);
	fflush(fp2);
	fclose(fp1);
	fclose(fp2);
}
int main()
{
	test(false,true);
	test(true,true);
	test(false,false);
	test(true,false);
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
