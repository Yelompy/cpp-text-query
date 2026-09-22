#include "textquery.h"
#include "queryresult.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>)
{
	std::string text;
	while (std::getline(is, text)) {
		file->push_back(text);
		std::istringstream line(text);
		int n = file->size() - 1;
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines) {
				lines.reset(new std::set<line_on>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string& s)
{
	static const auto nodata = std::make_shared<std::set<line_on>>();
	auto loc = wm.find(s);
	if (loc == wm.end())
		return QueryResult(s, file, nodata);
	else
		return QueryResult(s, file, loc->second);
}
