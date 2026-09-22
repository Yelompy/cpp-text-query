#include <fstream>
#include <iostream>
#include <string>

#include "queryresult.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "用法: " << argv[0] << " <文本文件>\n";
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input) {
		std::cerr << "无法打开文件: " << argv[1] << '\n';
		return 1;
	}

	TextQuery textQuery(input);
	std::cout << "请输入要查询的单词（输入 q 退出）：\n";

	std::string word;
	while (std::cin >> word && word != "q") {
		print(textQuery.query(word), std::cout) << '\n';
		std::cout << "继续查询（输入 q 退出）：\n";
	}

	return 0;
}
