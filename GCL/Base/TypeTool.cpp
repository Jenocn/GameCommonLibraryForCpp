#include "TypeTool.h"
#include <cstdarg>

using namespace GCL::Base;

bool TypeTool::IsNumber(const std::string& s) {
	if (s.empty()) {
		return false;
	}
	char* endptr;
	std::strtold(s.c_str(), &endptr);
	return (*endptr == 0);
}
bool TypeTool::IsInteger(const std::string& s) {
	if (s.empty()) {
		return false;
	}
	char* endptr;
	std::strtoll(s.c_str(), &endptr, 10);
	return (*endptr == 0);
}
bool TypeTool::IsFloat(const std::string& s) {
	if (s.empty()) {
		return false;
	}
	char* endptr;
	auto ret = std::strtold(s.c_str(), &endptr);
	return (*endptr == 0) && ((long long)ret != ret);
}
bool TypeTool::IsBool(const std::string& s) {
	return (s == "true") || (s == "false");
}

int TypeTool::ToInt(const std::string& s, int def) {
	return (int)ToLongDouble(s, def);
}
double TypeTool::ToDouble(const std::string& s, double def) {
	return (double)ToLongDouble(s, def);
}
long double TypeTool::ToLongDouble(const std::string& s, long double def) {
	if (s.empty()) {
		return def;
	}
	char* endptr;
	auto ret = std::strtold(s.c_str(), &endptr);
	if (*endptr == 0) {
		return ret;
	}
	return def;
}

float TypeTool::ToFloat(const std::string& s, float def) {
	return (float)ToLongDouble(s, def);
}
long long TypeTool::ToInt64(const std::string& s, long long def) {
	if (s.empty()) {
		return def;
	}
	char* endptr;
	auto ret = std::strtoll(s.c_str(), &endptr, 10);
	if (*endptr == 0) {
		return ret;
	}
	return (long long)ToLongDouble(s, (long double)def);
}
bool TypeTool::ToBool(const std::string& s, bool def) {
	if (s == "true") {
		return true;
	} else if (s == "false") {
		return false;
	}
	return def;
}
std::string TypeTool::ToString(char value) {
	char ch[5]{ 0 };
	snprintf(ch, sizeof(ch), "%d", (int)value);
	return ch;
}
std::string TypeTool::ToString(int value) {
	char ch[12]{ 0 };
	snprintf(ch, sizeof(ch), "%d", value);
	return ch;
}
std::string TypeTool::ToString(double value) {
	char ch[24]{ 0 };
	snprintf(ch, sizeof(ch), "%0.15lg", value);
	return ch;
}
std::string TypeTool::ToString(float value) {
	char ch[24]{ 0 };
	snprintf(ch, sizeof(ch), "%0.15lg", value);
	return ch;
}
std::string TypeTool::ToString(long long value) {
	char ch[24]{ 0 };
	snprintf(ch, sizeof(ch), "%lld", value);
	return ch;
}
std::string TypeTool::ToString(bool value) {
	if (value) {
		return "true";
	}
	return "false";
}
std::string TypeTool::ToString(unsigned char value) {
	char ch[5]{ 0 };
	snprintf(ch, sizeof(ch), "%d", (int)value);
	return ch;
}
std::string TypeTool::ToString(unsigned int value) {
	char ch[12]{ 0 };
	snprintf(ch, sizeof(ch), "%u", value);
	return ch;
}
std::string TypeTool::ToString(unsigned long long value) {
	char ch[24]{ 0 };
	snprintf(ch, sizeof(ch), "%llu", value);
	return ch;
}

static const std::size_t TYPETOOL_BUFFER_LENGTH = 512;
std::string TypeTool::ToString(const std::string& format_, ...) {
	const char* format = format_.c_str();
	va_list args;
	std::string buffer(TYPETOOL_BUFFER_LENGTH, '\0');

	va_start(args, format);
	int nret = vsnprintf(&buffer.front(), buffer.length() + 1, format, args);
	va_end(args);

	if (nret >= 0) {
		if ((unsigned int)nret < buffer.length()) {
			buffer.resize(nret);
		} else if ((unsigned int)nret > buffer.length()) { // VS2015/2017 or later Visual Studio Version
			buffer.resize(nret);

			va_start(args, format);
			nret = vsnprintf(&buffer.front(), buffer.length() + 1, format, args);
			va_end(args);
		}
		// else equals, do nothing.
	} else { // less or equal VS2013 and Unix System glibc implement.
		do {
			buffer.resize(buffer.length() * 3 / 2);

			va_start(args, format);
			nret = vsnprintf(&buffer.front(), buffer.length() + 1, format, args);
			va_end(args);

		} while (nret < 0);

		buffer.resize(nret);
	}

	return buffer;
}
std::string TypeTool::ToString(const char* format, ...) {
	va_list args;
	std::string buffer(TYPETOOL_BUFFER_LENGTH, '\0');

	va_start(args, format);
	int nret = vsnprintf(&buffer.front(), buffer.length() + 1, format, args);
	va_end(args);

	if (nret >= 0) {
		if ((unsigned int)nret < buffer.length()) {
			buffer.resize(nret);
		} else if ((unsigned int)nret > buffer.length()) { // VS2015/2017 or later Visual Studio Version
			buffer.resize(nret);

			va_start(args, format);
			nret = vsnprintf(&buffer.front(), buffer.length() + 1, format, args);
			va_end(args);
		}
		// else equals, do nothing.
	} else { // less or equal VS2013 and Unix System glibc implement.
		do {
			buffer.resize(buffer.length() * 3 / 2);

			va_start(args, format);
			nret = vsnprintf(&buffer.front(), buffer.length() + 1, format, args);
			va_end(args);

		} while (nret < 0);

		buffer.resize(nret);
	}

	return buffer;
}
