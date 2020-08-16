#include "StringTool.h"
#include "TypeTool.h"
#include <random>

using namespace GCL::Base;

std::vector<std::string> StringTool::Split(const std::string& str, char c) {
	return Split(str, std::set<char>{ c });
}

std::vector<std::string> StringTool::Split(const std::string& str, std::set<char> c) {
	std::vector<std::string> ret;
	if (str.empty()) {
		return ret;
	}
	ret.reserve(2);

	std::size_t posH = 0;
	for (std::size_t i = 0; i < str.length(); ++i) {
		if (c.find(str[i]) == c.end()) {
			continue;
		}
		if (posH == i) {
			posH = i + 1;
			continue;
		}
		ret.emplace_back(std::move(str.substr(posH, i - posH)));
		posH = i + 1;
	}

	if (posH < str.length()) {
		ret.emplace_back(std::move(str.substr(posH, str.length() - posH)));
	}

	return ret;
}

std::vector<std::string> StringTool::SplitAndTrim(const std::string& s, char c) {
	return SplitAndTrim(s, std::set<char>{ c });
}
std::vector<std::string> StringTool::SplitAndTrim(const std::string& s, std::set<char> c) {
	auto ret = std::move(Split(s, c));
	auto ite = ret.begin();
	while (ite != ret.end()) {
		auto dest = std::move(Trim(*ite));
		if (dest.empty()) {
			ite = ret.erase(ite);
		} else {
			*ite = std::move(dest);
			++ite;
		}
	}
	return ret;
}
std::string StringTool::Trim(const std::string& str, const std::set<char>& c) {
	if (str.empty()) {
		return "";
	}
	std::size_t posH = 0;
	for (auto i = 0u; i < str.size(); ++i) {
		char p = str[i];
		if (c.find(p) == c.end()) {
			break;
		}
		posH = i + 1;
	}
	std::size_t posE = 0;
	for (int i = (int)str.size() - 1; i >= 0; --i) {
		char p = str[i];
		if (c.find(p) == c.end()) {
			break;
		}
		posE = i;
	}
	if ((posH == 0) && (posE == 0)) {
		return str;
	}
	if (posH >= posE) {
		return "";
	}
	return str.substr(posH, posE - posH);
}

std::string StringTool::Replace(const std::string& str, const std::string& find, const std::string& dest) {
	if (str.empty()) {
		return "";
	}
	std::string ret;
	ret.reserve(str.size());
	std::size_t index = 0;
	while (true) {
		std::size_t pos = str.find(find, index);
		if (pos == std::string::npos) {
			break;
		}
		ret.append(str.substr(index, pos - index));
		ret.append(dest);
		index = pos + find.size();
	}
	ret.append(str.substr(index, std::string::npos));
	return ret;
}

std::string StringTool::ToPrivateNickName(const std::string& str, bool bUTF8) {
	int step = bUTF8 ? 3 : 2;

	std::vector<std::string> tempVec;
	std::size_t i = 0;
	while (i < str.size()) {
		char specialValue = str[i];
		bool bSpecial = (specialValue >= 0 && specialValue <= 127);
		std::size_t nextPos = bSpecial ? i + 1 : i + step;
		nextPos = std::min<std::size_t>(nextPos, str.size());
		tempVec.emplace_back(std::move(str.substr(i, nextPos - i)));
		i = nextPos;
	}

	std::string ret = "";
	if (tempVec.size() > 0) {
		ret += tempVec[0];
	}
	for (std::size_t i = 1; i < tempVec.size() - 1; ++i) {
		ret += "*";
	}
	if (tempVec.size() > 2) {
		ret += tempVec[tempVec.size() - 1];
	}
	return ret;
}

std::string StringTool::ToMoneyString(long long money, char symbol) {
	std::string ret = TypeTool::ToString(abs(money));
	int index = (int)ret.size() - 3;
	while (index > 0) {
		ret.insert(ret.begin() + index, symbol);
		index -= 3;
	}

	if (money < 0) {
		ret.insert(0, "-");
	}
	return ret;
}
