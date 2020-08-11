/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>

namespace GCL {
namespace Base {

template <typename T1, typename T2>
struct CheckTypeSame {
	enum { value = 0 };
};
template <typename T>
struct CheckTypeSame<T, T> {
	enum { value = 1 };
};

template <typename T>
struct __CheckType {
};
template <>
struct __CheckType<std::string> {
	enum { IsString = 1 };
};
template <>
struct __CheckType<char*> {
	enum { IsString = 1 };
	enum { IsCString = 1 };
};
template <>
struct __CheckType<const char*> {
	enum { IsString = 1 };
	enum { IsCString = 1 };
};
template <>
struct __CheckType<int> {
	enum { IsInt = 1 };
};
template <>
struct __CheckType<float> {
	enum { IsFloat = 1 };
};
template <>
struct __CheckType<double> {
	enum { IsDouble = 1 };
};
template <>
struct __CheckType<long long> {
	enum { IsLongLong = 1 };
};
template <>
struct __CheckType<char> {
	enum { IsChar = 1 };
};
template <>
struct __CheckType<bool> {
	enum { IsBool = 1 };
};
template <>
struct __CheckType<unsigned int> {
	enum { IsUInt = 1 };
};
template <>
struct __CheckType<unsigned long long> {
	enum { IsULongLong = 1 };
};
template <>
struct __CheckType<unsigned char> {
	enum { IsUChar = 1 };
};

template <typename T>
struct __CheckTypeString {
	enum { value = __CheckType<T>::IsString };
};
template <typename T>
struct __CheckTypeCString {
	enum { value = __CheckType<T>::IsCString };
};
template <typename T>
struct __CheckTypeInt {
	enum { value = __CheckType<T>::IsInt };
};
template <typename T>
struct __CheckTypeFloat {
	enum { value = __CheckType<T>::IsFloat };
};
template <typename T>
struct __CheckTypeDouble {
	enum { value = __CheckType<T>::IsDouble };
};
template <typename T>
struct __CheckTypeLongLong {
	enum { value = __CheckType<T>::IsLongLong };
};
template <typename T>
struct __CheckTypeChar {
	enum { value = __CheckType<T>::IsChar };
};
template <typename T>
struct __CheckTypeBool {
	enum { value = __CheckType<T>::IsBool };
};
template <typename T>
struct __CheckTypeUInt {
	enum { value = __CheckType<T>::IsUInt };
};
template <typename T>
struct __CheckTypeULongLong {
	enum { value = __CheckType<T>::IsULongLong };
};
template <typename T>
struct __CheckTypeUChar {
	enum { value = __CheckType<T>::IsUChar };
};

class CheckTypeTool {
public:
	template <typename T>
	static bool IsString() {
		return (CheckTypeSame<T, std::string>::value || CheckTypeSame<T, const char*>::value || CheckTypeSame<T, char*>::value);
	}
	template <typename T>
	static bool IsCString() {
		return (CheckTypeSame<T, const char*>::value || CheckTypeSame<T, char*>::value);
	}
	template <typename T>
	static bool IsInt() {
		return (CheckTypeSame<T, int>::value);
	}
	template <typename T>
	static bool IsFloat() {
		return (CheckTypeSame<T, float>::value);
	}
	template <typename T>
	static bool IsDouble() {
		return (CheckTypeSame<T, double>::value);
	}
	template <typename T>
	static bool IsLongLong() {
		return (CheckTypeSame<T, long long>::value);
	}
	template <typename T>
	static bool IsChar() {
		return (CheckTypeSame<T, char>::value);
	}
	template <typename T>
	static bool IsBool() {
		return (CheckTypeSame<T, bool>::value);
	}
	template <typename T>
	static bool IsUInt() {
		return (CheckTypeSame<T, unsigned int>::value);
	}
	template <typename T>
	static bool IsULongLong() {
		return (CheckTypeSame<T, unsigned long long>::value);
	}
	template <typename T>
	static bool IsUChar() {
		return (CheckTypeSame<T, unsigned char>::value);
	}
	template <typename T>
	static bool IsNumber() {
		return IsInt<T>() || IsFloat<T>() || IsDouble<T>() || IsLongLong<T>() || IsUInt<T>() || IsULongLong<T>() || IsChar<T>() || IsUChar<T>();
	}

	template <typename T>
	static void StaticCheckString() {
		static_assert(__CheckTypeString<T>::value, "The type isn't (std::string) or (char*) or (const char*)");
	}
	template <typename T>
	static void StaticCheckCString() {
		static_assert(__CheckTypeCString<T>::value, "The type isn't (char*) or (const char*)");
	}
	template <typename T>
	static void StaticCheckInt() {
		static_assert(__CheckTypeInt<T>::value, "The type isn't (int)");
	}
	template <typename T>
	static void StaticCheckFloat() {
		static_assert(__CheckTypeFloat<T>::value, "The type isn't (float)");
	}
	template <typename T>
	static void StaticCheckDouble() {
		static_assert(__CheckTypeDouble<T>::value, "The type isn't (double)");
	}
	template <typename T>
	static void StaticCheckLongLong() {
		static_assert(__CheckTypeLongLong<T>::value, "The type isn't (long long)");
	}
	template <typename T>
	static void StaticCheckChar() {
		static_assert(__CheckTypeChar<T>::value, "The type isn't (char)");
	}
	template <typename T>
	static void StaticCheckBool() {
		static_assert(__CheckTypeBool<T>::value, "The type isn't (bool)");
	}
	template <typename T>
	static void StaticCheckUInt() {
		static_assert(__CheckTypeUInt<T>::value, "The type isn't (unsigned int)");
	}
	template <typename T>
	static void StaticCheckULongLong() {
		static_assert(__CheckTypeULongLong<T>::value, "The type isn't (unsigned long long)");
	}
	template <typename T>
	static void StaticCheckUChar() {
		static_assert(__CheckTypeUChar<T>::value, "The type isn't (unsigned char)");
	}
};
} // namespace Base
} // namespace GCL