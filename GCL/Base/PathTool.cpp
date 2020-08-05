#include "PathTool.h"
#include "StringTool.h"
#include <list>

using namespace GCL::Base;

static bool _IsSepartor(char ch) {
	return ch == '/' || ch == '\\';
}

std::string PathTool::Join(const std::initializer_list<std::string>& paths) {
	std::string ret;
	ret.reserve(64);
	for (const auto& item : paths) {
		auto path = std::move(Normalize(item));
		if (path.empty()) {
			continue;
		}
		if (ret.empty()) {
			ret = std::move(path);
			continue;
		}
		if (!_IsSepartor(path[0])) {
			ret.append(1, '/');
		}
		ret.append(path);
	}
	return Normalize(ret);
}
std::string PathTool::Join(const std::string& src, const std::string& dest) {
	return Join({ src, dest });
}

std::string PathTool::Normalize(const std::string& path) {
	if (path.empty()) {
		return "";
	}

	bool bFirstSepartor = _IsSepartor(path[0]);

	std::list<std::string> tempList;
	auto arr = std::move(StringTool::SplitAndTrim(path, { '/', '\\' }));
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
			ret.insert(0, "/");
			ret.insert(0, item);
		}
		tempList.pop_back();
	}

	if (bFirstSepartor) {
		ret.insert(0, "/");
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
