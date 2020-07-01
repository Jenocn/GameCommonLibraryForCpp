/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>
#include <unordered_map>

namespace GCL {
namespace Serialization {

using INIPrototypeMap = std::unordered_map<std::string, std::unordered_map<std::string, std::string>>;

class INIReader {
public:
	INIReader();
	INIReader(const INIPrototypeMap& prototypeMap);

	const std::string& GetString(const std::string& session, const std::string& key, const std::string& defaultValue = "") const;
	double GetDouble(const std::string& session, const std::string& key, double defaultValue = 0) const;
	float GetFloat(const std::string& session, const std::string& key, float defaultValue = 0) const;
	int GetInt(const std::string& session, const std::string& key, int defaultValue = 0) const;
	long long GetInt64(const std::string& session, const std::string& key, long long defaultValue = 0) const;
	bool GetBool(const std::string& session, const std::string& key, bool defaultValue = false) const;

	void Set(const std::string& session, const std::string& key, const std::string& value);
	void Set(const std::string& session, const std::string& key, double value);
	void Set(const std::string& session, const std::string& key, float value);
	void Set(const std::string& session, const std::string& key, int value);
	void Set(const std::string& session, const std::string& key, long long value);
	void Set(const std::string& session, const std::string& key, bool value);

	const INIPrototypeMap& GetPrototypeMap() const;

private:
	INIPrototypeMap _prototypeMap;
};
} // namespace Serialization
} // namespace GCL