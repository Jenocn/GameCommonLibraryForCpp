/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>
#include "CheckType.h"

namespace GCL {
namespace Base {
class TypeTool {
public:
	static bool IsNumber(const std::string& s);
	static bool IsInteger(const std::string& s);
	static bool IsFloat(const std::string& s);
	static bool IsBool(const std::string& s);

	static int ToInt(const std::string& s, int def = 0);
	static double ToDouble(const std::string& s, double def = 0);
	static long double ToLongDouble(const std::string& s, long double def = 0);
	static float ToFloat(const std::string& s, float def = 0);
	static long long ToInt64(const std::string& s, long long def = 0);
	static bool ToBool(const std::string& s, bool def = 0);

	static std::string ToString(char value);
	static std::string ToString(int value);
	static std::string ToString(double value);
	static std::string ToString(float value);
	static std::string ToString(long long value);
	static std::string ToString(bool value);
	static std::string ToString(unsigned char value);
	static std::string ToString(unsigned int value);
	static std::string ToString(unsigned long long value);
#if defined(__APPLE__) && !defined(ANDROID)
#if defined(__SIZE_TYPE__)
	static std::string ToString(__SIZE_TYPE__ value) {
		return ToString((unsigned int)value);
	}
#endif
#endif

	static std::string ToString(const std::string& format, ...);
	static std::string ToString(const char* format, ...);

	static bool EqualString(const std::string& a, const std::string& b) {
		return a == b;
	}
	static bool EqualString(const char* a, const char* b) {
		return strcmp(a, b) == 0;
	}

	template<typename T>
	static bool Equal(T a, T b) {
		// If 'T' is 'std::string', please use 'EqualString'
		CheckTypeTool::StaticCheckNotStlString<T>();
		return a == b;
	}
	template<>
	static bool Equal<float>(float a, float b) {
		float v = a - b;
		return fabs(v) < FLT_EPSILON;
	}
	template<>
	static bool Equal<const char*>(const char* a, const char* b) {
		return strcmp(a, b) == 0;
	}
	template<>
	static bool Equal<char*>(char* a, char* b) {
		return Equal<const char*>(a, b);
	}
	template<>
	static bool Equal<double>(double a, double b) {
		return fabs(a - b) < DBL_EPSILON;
	}
};
} // namespace Base
} // namespace GCL