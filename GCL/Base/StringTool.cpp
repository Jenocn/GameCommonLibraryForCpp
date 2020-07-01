#include "StringTool.h"
#include "TypeTool.h"
#include <random>

using namespace GCL::Base;

std::vector<std::string> StringTool::Split(const std::string& str, char c) {
	std::vector<std::string> ret;
	if (str.empty()) {
		return ret;
	}
	ret.reserve(2);

	std::size_t posH = 0;
	for (std::size_t i = 0; i < str.length(); ++i) {
		if (str[i] != c) {
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
std::vector<std::string> StringTool::SplitAndTrim(const std::string& str, char c) {
	std::vector<std::string> ret;
	if (str.empty()) {
		return ret;
	}
	ret.reserve(2);

	std::size_t posH = 0;
	for (std::size_t i = 0; i < str.length(); ++i) {
		if (str[i] != c) {
			continue;
		}
		if (posH == i) {
			posH = i + 1;
			continue;
		}
		auto dest = std::move(Trim(str.substr(posH, i - posH)));
		if (!dest.empty()) {
			ret.emplace_back(dest);
		}
		posH = i + 1;
	}

	if (posH < str.length()) {
		auto dest = std::move(Trim(str.substr(posH, str.length() - posH)));
		if (!dest.empty()) {
			ret.emplace_back(dest);
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
	if (abs(money) < 999) {
		return TypeTool::ToString(money);
	}

	std::string ret = TypeTool::ToString(abs(money));
	ret.insert(ret.size() - 3, ",");
	while (true) {
		int index = (int)ret.find_first_of(',');
		index -= 3;
		if (index <= 0) {
			break;
		}
		ret.insert(index, ",");
	}
	if (money < 0) {
		ret.insert(0, "-");
	}
	return ret;
}
