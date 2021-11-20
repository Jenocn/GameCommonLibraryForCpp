/*
	By Jenocn
	https://jenocn.github.io/

	Encoding: UTF-8 with BOM
*/

#pragma once

#include <set>
#include <string>
#include <memory>
#include "INIReader.h"

namespace GCL {
namespace Serialization {
	
class INITool {
	/// <summary>
	/// 解析配置到INI读取器中
	/// </summary>
public:
	static std::shared_ptr<INIReader> ParseTo(const std::string& src);

	/// <summary>
	/// 将INI读取器中的配置数据转为字符串
	/// </summary>
	static std::string ToString(const INIReader* reader);

	/// <summary>
	/// 解析配置到Dictionary中
	/// </summary>
	static INIPrototypeMap Parse(const std::string& src);

	/// <summary>
	/// 从Dictionary中转换为INI字符串
	/// </summary>
	static std::string ToString(const INIPrototypeMap& data);
};
} // namespace Serialization
} // namespace GCL