#include "PathTool.h"
#include "StringTool.h"
#include <list>

using namespace GCL::Base;

std::string PathTool::Join(const std::initializer_list<std::string>& paths, char separtor) {
	std::string ret = "";
	ret.reserve(paths.size() * 4);

	for (auto& item : paths) {
		if (item.empty()) {
			continue;
		}
		if (item == "/" || item == "\\") {
			continue;
		}

		bool bSepartor1 = false;
		bool bSepartor2 = false;
		if (!ret.empty()) {
			bSepartor1 = _IsSepartor(ret.back());
		}
		if (!item.empty()) {
			bSepartor2 = _IsSepartor(item.front());
		}

		if (bSepartor1 != bSepartor2) {
			ret.append(item);
			continue;
		}

		if (bSepartor1) {
			ret.append(item.substr(1));
			continue;
		}

		if (!ret.empty()) {
			ret.append(1, separtor);
		}
		ret.append(item);
	}

	return ret;
}

std::string PathTool::Join(const std::string& path, const std::string& add, char separtor) {
	return Join({path, add}, separtor);
}

std::string PathTool::NormalizeJoin(const std::initializer_list<std::string>& paths, char separtor) {
	return Normalize(Join(paths, separtor), separtor);
}
std::string PathTool::NormalizeJoin(const std::string& src, const std::string& dest, char separtor) {
	return NormalizeJoin({src, dest}, separtor);
}

std::string PathTool::Normalize(const std::string& path, char separtor) {
	if (path.empty()) {
		return "";
	}

	bool bFirstSepartor = _IsSepartor(path[0]);

	std::list<std::string> tempList;
	auto arr = std::move(StringTool::SplitAndTrim(path, {'/', '\\'}));
	for (auto& item : arr) {
		if (item == "..") {
			if (!tempList.empty()) {
				auto& backItem = tempList.back();
				if (backItem != "..") {
					tempList.pop_back();
					continue;
				}
			} else {
				if (bFirstSepartor) {
					return "";
				}
			}
		}
		tempList.emplace_back(std::move(item));
	}

	std::string ret;
	ret.reserve(path.size());

	while (!tempList.empty()) {
		auto& item = tempList.back();
		if (ret.empty()) {
			ret = std::move(item);
		} else {
			ret.insert(0, 1, separtor);
			ret.insert(0, item);
		}
		tempList.pop_back();
	}

	if (bFirstSepartor) {
		ret.insert(0, 1, separtor);
	}

	return ret;
}

std::string PathTool::Extname(const std::string& filename) {
	auto pos = filename.find_last_of('.');
	if (pos == std::string::npos) {
		return "";
	}
	return filename.substr(pos);
}

bool PathTool::_IsSepartor(char ch) {
	return (ch == '/') || (ch == '\\');
}
