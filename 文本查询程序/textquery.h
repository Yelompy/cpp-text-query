#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <fstream>

class QueryResult;
class TextQuery
{
public:
	using line_on = std::vector<std::string >::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&);

private:
	std::map<std::string, std::shared_ptr<std::set<line_on>>> wm;	//记录单词所在行数
	std::shared_ptr<std::vector<std::string>> file;		//输入的文件
};