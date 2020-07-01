/*
	By Jenocn
	https://jenocn.github.io/
*/

#include "INIReader.h"
#include "../Base/TypeTool.h"

using namespace GCL::Serialization;
using namespace GCL::Base;

INIReader::INIReader() {}
INIReader::INIReader(const INIPrototypeMap& prototypeMap)
	: _prototypeMap(prototypeMap) {
}

const std::string& INIReader::GetString(const std::string& session, const std::string& key, const std::string& defaultValue) const {
	auto ite0 = _prototypeMap.find(session);
	if (ite0 != _prototypeMap.end()) {
		auto ite1 = ite0->second.find(key);
		if (ite1 != ite0->second.end()) {
			return ite1->second;
		}
	}
	return defaultValue;
}
double INIReader::GetDouble(const std::string& session, const std::string& key, double defaultValue) const {
	return TypeTool::ToDouble(GetString(session, key, ""), defaultValue);
}
float INIReader::GetFloat(const std::string& session, const std::string& key, float defaultValue) const {
	return TypeTool::ToFloat(GetString(session, key, ""), defaultValue);
}
int INIReader::GetInt(const std::string& session, const std::string& key, int defaultValue) const {
	return TypeTool::ToInt(GetString(session, key, ""), defaultValue);
}
long long INIReader::GetInt64(const std::string& session, const std::string& key, long long defaultValue) const {
	return TypeTool::ToInt64(GetString(session, key, ""), defaultValue);
}
bool INIReader::GetBool(const std::string& session, const std::string& key, bool defaultValue) const {
	return TypeTool::ToBool(GetString(session, key, ""), defaultValue);
}

void INIReader::Set(const std::string& session, const std::string& key, const std::string& value) {
	_prototypeMap[session][key] = value;
}
void INIReader::Set(const std::string& session, const std::string& key, double value) {
	Set(session, key, TypeTool::ToString(value));
}
void INIReader::Set(const std::string& session, const std::string& key, float value) {
	Set(session, key, TypeTool::ToString(value));
}
void INIReader::Set(const std::string& session, const std::string& key, int value) {
	Set(session, key, TypeTool::ToString(value));
}
void INIReader::Set(const std::string& session, const std::string& key, long long value) {
	Set(session, key, TypeTool::ToString(value));
}
void INIReader::Set(const std::string& session, const std::string& key, bool value) {
	Set(session, key, TypeTool::ToString(value));
}

const INIPrototypeMap& INIReader::GetPrototypeMap() const {
	return _prototypeMap;
}
