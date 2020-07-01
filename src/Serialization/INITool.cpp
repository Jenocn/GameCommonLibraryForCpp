/*
	By Jenocn
	https://jenocn.github.io/
*/

#include "INITool.h"
#include "../Base/StringTool.h"

using namespace GCL::Serialization;
using namespace GCL::Base;

static const std::set<char> TRIM_WORD = {' ', '\t', '\r', '\n'};
static const std::set<char> COMMENTS = {';', '#'};
static const char KV_SPLIT = '=';

std::shared_ptr<INIReader> INITool::ParseTo(const std::string& src) {
	return std::shared_ptr<INIReader>(new INIReader(Parse(src)));
}

/// <summary>
/// 将INI读取器中的配置数据转为字符串
/// </summary>
std::string INITool::ToString(const INIReader* reader) {
	if (reader) {
		return ToString(reader->GetPrototypeMap());
	}
	return "";
}

/// <summary>
/// 解析配置到Dictionary中
/// </summary>
INIPrototypeMap INITool::Parse(const std::string& src) {
	INIPrototypeMap ret;
	if (src.empty()) {
		return ret;
	}
	std::unordered_map<std::string, std::string>* curHeadDict{nullptr};
	const auto& lineStrArray = StringTool::SplitAndTrim(src, '\n');
	for (int i = 0; i < lineStrArray.size(); ++i) {
		const std::string& lineStr = lineStrArray[i];
		auto length = lineStr.size();
		if (length < 3) {
			continue;
		}
		if (COMMENTS.find(lineStr[0]) != COMMENTS.end()) {
			continue;
		}
		const auto& headStr = _ParseHead(lineStr);
		if (!headStr.empty()) {
			curHeadDict = &ret[headStr];
			continue;
		}
		if (!curHeadDict) {
			continue;
		}
		auto kvIndex = lineStr.find(KV_SPLIT);
		if (kvIndex < 1 || kvIndex >= length - 1) {
			continue;
		}
		const auto& key = lineStr.substr(0, kvIndex);
		if (key.empty()) {
			continue;
		}
		auto value = std::move(lineStr.substr(kvIndex + 1));
		if (value.empty()) {
			continue;
		}
		auto findNoteIdx = std::string::npos;
		for (const auto& sign : COMMENTS) {
			findNoteIdx = std::min<std::size_t>(findNoteIdx, value.find(sign));
		}
		if (findNoteIdx == 0) {
			continue;
		}
		if (findNoteIdx > 0 && findNoteIdx < value.size()) {
			value = std::move(value.substr(0, findNoteIdx));
		}
		curHeadDict->emplace(StringTool::Trim(key), StringTool::Trim(value));
	}

	return ret;
}

/// <summary>
/// 从Dictionary中转换为INI字符串
/// </summary>
std::string INITool::ToString(const INIPrototypeMap& data) {
	if (data.empty()) {
		return "";
	}
	std::string ret;
	ret.reserve(data.size() * 4);
	for (const auto& item : data) {
		ret.append("[");
		ret.append(item.first);
		ret.append("]\n");
		for (const auto& content : item.second) {
			ret.append(content.first);
			ret.append("=");
			ret.append(content.second);
			ret.append("\n");
		}
	}
	return ret;
}

std::string INITool::_ParseHead(const std::string& str) {
	int len = str.length();
	if (str[0] != '[' && str[len - 1] != ']') {
		return "";
	}
	return str.substr(1, len - 2);
}
