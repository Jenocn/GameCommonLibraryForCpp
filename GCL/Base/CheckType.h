/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>

namespace GCL {
namespace Base {

class CheckTypeTool {
private:
	template <typename T1, typename T2>
	struct __CheckTypeSame {
		enum { value = 0 };
	};
	template <typename T>
	struct __CheckTypeSame<T, T> {
		enum { value = 1 };
	};

	template <typename T>
	struct __CheckType {
	};

#ifdef __GENERATE_CHECK_TYPE_CLASS
#undef __GENERATE_CHECK_TYPE_CLASS
#endif
#define __GENERATE_CHECK_TYPE_CLASS(__Type__, __IsString__, __IsStlString__, __IsCString__, __IsInt__, __IsFloat__, __IsDouble__, __IsLongLong__, __IsChar__, __IsBool__, __IsUInt__, __IsULongLong__, __IsUChar__) \
template <> \
struct __CheckType<__Type__> { \
	enum { IsString = __IsString__ }; \
	enum { IsStlString = __IsStlString__ }; \
	enum { IsCString = __IsCString__ }; \
	enum { IsInt = __IsInt__ }; \
	enum { IsFloat = __IsFloat__ }; \
	enum { IsDouble = __IsDouble__ }; \
	enum { IsLongLong = __IsLongLong__ }; \
	enum { IsChar = __IsChar__ }; \
	enum { IsBool = __IsBool__ }; \
	enum { IsUInt = __IsUInt__ }; \
	enum { IsULongLong = __IsULongLong__ }; \
	enum { IsUChar = __IsUChar__ }; \
}

	__GENERATE_CHECK_TYPE_CLASS(std::string, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(char*, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(const char*, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(int, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(float, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(double, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(long long, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(char, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(bool, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(unsigned int, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	__GENERATE_CHECK_TYPE_CLASS(unsigned long long, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	__GENERATE_CHECK_TYPE_CLASS(unsigned char, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);

public:
	template <typename T1, typename T2>
	static bool IsSameType() {
		return __CheckTypeSame<T1, T2>::value;
	}
	//
	template <typename T>
	static bool IsString() {
		return (__CheckTypeSame<T, std::string>::value || __CheckTypeSame<T, const char*>::value || __CheckTypeSame<T, char*>::value);
	}
	template <typename T>
	static bool IsCString() {
		return (__CheckTypeSame<T, const char*>::value || __CheckTypeSame<T, char*>::value);
	}
	template <typename T>
	static bool IsInt() {
		return (__CheckTypeSame<T, int>::value);
	}
	template <typename T>
	static bool IsFloat() {
		return (__CheckTypeSame<T, float>::value);
	}
	template <typename T>
	static bool IsDouble() {
		return (__CheckTypeSame<T, double>::value);
	}
	template <typename T>
	static bool IsLongLong() {
		return (__CheckTypeSame<T, long long>::value);
	}
	template <typename T>
	static bool IsChar() {
		return (__CheckTypeSame<T, char>::value);
	}
	template <typename T>
	static bool IsBool() {
		return (__CheckTypeSame<T, bool>::value);
	}
	template <typename T>
	static bool IsUInt() {
		return (__CheckTypeSame<T, unsigned int>::value);
	}
	template <typename T>
	static bool IsULongLong() {
		return (__CheckTypeSame<T, unsigned long long>::value);
	}
	template <typename T>
	static bool IsUChar() {
		return (__CheckTypeSame<T, unsigned char>::value);
	}
	template <typename T>
	static bool IsNumber() {
		return IsInt<T>() || IsFloat<T>() || IsDouble<T>() || IsLongLong<T>() || IsUInt<T>() || IsULongLong<T>() || IsChar<T>() || IsUChar<T>();
	}
	//
	template <typename T>
	static void StaticCheckString() {
		static_assert((__CheckType<T>::IsString || __CheckType<T>::IsCString || __CheckType<T>::IsStlString), "The type isn't (std::string) or (char*) or (const char*)");
	}
	template <typename T>
	static void StaticCheckStlString() {
		static_assert(__CheckType<T>::IsStlString, "The type isn't (std::string)");
	}
	template <typename T>
	static void StaticCheckCString() {
		static_assert(__CheckType<T>::IsCString, "The type isn't (char*) or (const char*)");
	}
	template <typename T>
	static void StaticCheckInt() {
		static_assert(__CheckType<T>::IsInt, "The type isn't (int)");
	}
	template <typename T>
	static void StaticCheckFloat() {
		static_assert(__CheckType<T>::IsFloat, "The type isn't (float)");
	}
	template <typename T>
	static void StaticCheckDouble() {
		static_assert(__CheckType<T>::IsDouble, "The type isn't (double)");
	}
	template <typename T>
	static void StaticCheckLongLong() {
		static_assert(__CheckType<T>::IsLongLong, "The type isn't (long long)");
	}
	template <typename T>
	static void StaticCheckChar() {
		static_assert(__CheckType<T>::IsChar, "The type isn't (char)");
	}
	template <typename T>
	static void StaticCheckBool() {
		static_assert(__CheckType<T>::IsBool, "The type isn't (bool)");
	}
	template <typename T>
	static void StaticCheckUInt() {
		static_assert(__CheckType<T>::IsUInt, "The type isn't (unsigned int)");
	}
	template <typename T>
	static void StaticCheckULongLong() {
		static_assert(__CheckType<T>::IsULongLong, "The type isn't (unsigned long long)");
	}
	template <typename T>
	static void StaticCheckUChar() {
		static_assert(__CheckType<T>::IsUChar, "The type isn't (unsigned char)");
	}
	//
	template <typename T>
	static void StaticCheckNotString() {
		static_assert(!(__CheckType<T>::IsString || __CheckType<T>::IsCString || __CheckType<T>::IsStlString), "The type is (std::string) or (char*) or (const char*)");
	}
	template <typename T>
	static void StaticCheckNotStlString() {
		static_assert(!__CheckType<T>::IsStlString, "The type is (std::string)");
	}
	template <typename T>
	static void StaticCheckNotCString() {
		static_assert(!__CheckType<T>::IsCString, "The type is (char*) or (const char*)");
	}
	template <typename T>
	static void StaticCheckNotInt() {
		static_assert(!__CheckType<T>::IsInt, "The type is (int)");
	}
	template <typename T>
	static void StaticCheckNotFloat() {
		static_assert(!__CheckType<T>::IsFloat, "The type is (float)");
	}
	template <typename T>
	static void StaticCheckNotDouble() {
		static_assert(!__CheckType<T>::IsDouble, "The type is (double)");
	}
	template <typename T>
	static void StaticCheckNotLongLong() {
		static_assert(!__CheckType<T>::IsLongLong, "The type is (long long)");
	}
	template <typename T>
	static void StaticCheckNotChar() {
		static_assert(!__CheckType<T>::IsChar, "The type is (char)");
	}
	template <typename T>
	static void StaticCheckNotBool() {
		static_assert(!__CheckType<T>::IsBool, "The type is (bool)");
	}
	template <typename T>
	static void StaticCheckNotUInt() {
		static_assert(!__CheckType<T>::IsUInt, "The type is (unsigned int)");
	}
	template <typename T>
	static void StaticCheckNotULongLong() {
		static_assert(!__CheckType<T>::IsULongLong, "The type is (unsigned long long)");
	}
	template <typename T>
	static void StaticCheckNotUChar() {
		static_assert(!__CheckType<T>::IsUChar, "The type is (unsigned char)");
	}
};
} // namespace Base
} // namespace GCL