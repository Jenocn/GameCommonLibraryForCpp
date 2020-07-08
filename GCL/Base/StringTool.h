/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>
#include <vector>
#include <set>

namespace GCL {
namespace Base {
class StringTool {
public:
	static std::vector<std::string> Split(const std::string& s, char c);
	static std::vector<std::string> Split(const std::string& s, std::set<char> c);
	static std::vector<std::string> SplitAndTrim(const std::string& s, char c);
	static std::vector<std::string> SplitAndTrim(const std::string& s, std::set<char> c);
	static std::string Trim(const std::string& s, const std::set<char>& c = { ' ', '\r', '\n', '\t' });
	static std::string Replace(const std::string& str, const std::string& find, const std::string& dest);
	/*
	convert 'Name' to 'N**e'
	*/
	static std::string ToPrivateNickName(const std::string& str, bool bUTF8 = true);
	/*
	convert number to money number: 123456 => 123,456
	*/
	static std::string ToMoneyString(long long money, char symbol = ',');
};
} // namespace Base
} // namespace GCL