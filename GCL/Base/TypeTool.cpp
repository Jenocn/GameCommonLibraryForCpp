#include "TypeTool.h"

using namespace GCL::Base;

bool TypeTool::IsNumber(const std::string& s) {
	char* endptr;
	std::strtold(s.c_str(), &endptr);
	return (*endptr == 0);
}
bool TypeTool::IsInteger(const std::string& s) {
	char* endptr;
	std::strtoll(s.c_str(), &endptr, 10);
	return (*endptr == 0);
}
bool TypeTool::IsFloat(const std::string& s) {
	char* endptr;
	auto ret = std::strtold(s.c_str(), &endptr);
	return (*endptr == 0) && ((long long)ret != ret);
}
bool TypeTool::IsBool(const std::string& s) {
	return (s == "true") || (s == "false");
}

int TypeTool::ToInt(const std::string& s, int def) {
	char* endptr;
	auto ret = std::strtoll(s.c_str(), &endptr, 10);
	if (*endptr == 0) {
		return (int)ret;
	}
	return def;
}
double TypeTool::ToDouble(const std::string& s, double def) {
	char* endptr;
	auto ret = std::strtold(s.c_str(), &endptr);
	if (*endptr == 0) {
		return (double)ret;
	}
	return def;
}
float TypeTool::ToFloat(const std::string& s, float def) {
	char* endptr;
	auto ret = std::strtold(s.c_str(), &endptr);
	if (*endptr == 0) {
		return (float)ret;
	}
	return def;
}
long long TypeTool::ToInt64(const std::string& s, long long def) {
	char* endptr;
	auto ret = std::strtoll(s.c_str(), &endptr, 10);
	if (*endptr == 0) {
		return ret;
	}
	return def;
}
bool TypeTool::ToBool(const std::string& s, bool def) {
	if (s == "true") {
		return true;
	} else if (s == "false") {
		return false;
	}
	return def;
}
std::string TypeTool::ToString(int value) {
	char ch[12]{0};
	snprintf(ch, sizeof(ch), "%d", value);
	return ch;
}
std::string TypeTool::ToString(double value) {
	char ch[24]{0};
	snprintf(ch, sizeof(ch), "%0.15lg", value);
	return ch;
}
std::string TypeTool::ToString(float value) {
	char ch[24]{0};
	snprintf(ch, sizeof(ch), "%0.15lg", value);
	return ch;
}
std::string TypeTool::ToString(long long value) {
	char ch[24]{0};
	snprintf(ch, sizeof(ch), "%f", value);
	return ch;
}
std::string TypeTool::ToString(bool value) {
	if (value) {
		return "true";
	}
	return "false";
}