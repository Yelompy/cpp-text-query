#pragma once
#include "textquery.h"
#include <vector>
#include <memory>
#include <string>
#include <set>
#include <iostream>

class QueryResult
{
	friend std::ostream& print(const QueryResult& qr, std::ostream& os);
public:
	QueryResult(std::string s, std::shared_ptr<std::vector<std::string>>f, std::shared_ptr<std::set<TextQuery::line_on>>l) : sought(s), file(f), lines(l) {}
private:
	std::string sought;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<TextQuery::line_on>> lines;
};

inline std::ostream& print(const QueryResult& qr, std::ostream& os)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time") << std::endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << std::endl;
	}
	return os;
}
