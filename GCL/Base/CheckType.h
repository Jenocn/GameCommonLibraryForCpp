/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <string>

namespace GCL {
namespace Base {

struct __CheckTypeValue {
	enum {
		CheckTypeValueNone = 0,
		CheckTypeValueInt,
		CheckTypeValueFloat,
		CheckTypeValueDouble,
		CheckTypeValueLongLong,
		CheckTypeValueChar,
		CheckTypeValueBool,
		CheckTypeValueString,
	};
};

template <typename T>
struct __CheckType {
	enum { value = __CheckTypeValue::CheckTypeValueNone,
	};
};
template <>
struct __CheckType<std::string> {
	enum { IsString = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueString,
	};
};
template <>
struct __CheckType<char*> {
	enum { IsString = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueString,
	};
};
template <>
struct __CheckType<const char*> {
	enum { IsString = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueString,
	};
};
template <>
struct __CheckType<int> {
	enum { IsInt = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueInt,
	};
};
template <>
struct __CheckType<float> {
	enum { IsFloat = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueFloat,
	};
};
template <>
struct __CheckType<double> {
	enum { IsDouble = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueDouble,
	};
};
template <>
struct __CheckType<long long> {
	enum { IsLongLong = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueLongLong,
	};
};
template <>
struct __CheckType<char> {
	enum { IsChar = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueChar,
	};
};
template <>
struct __CheckType<bool> {
	enum { IsBool = 1 };
	enum { value = __CheckTypeValue::CheckTypeValueBool,
	};
};

template <typename T>
struct __CheckTypeString {
	enum { value = __CheckType<T>::IsString,
	};
};
template <typename T>
struct __CheckTypeInt {
	enum { value = __CheckType<T>::IsInt,
	};
};
template <typename T>
struct __CheckTypeFloat {
	enum { value = __CheckType<T>::IsFloat,
	};
};
template <typename T>
struct __CheckTypeDouble {
	enum { value = __CheckType<T>::IsDouble,
	};
};
template <typename T>
struct __CheckTypeLongLong {
	enum { value = __CheckType<T>::IsLongLong,
	};
};
template <typename T>
struct __CheckTypeChar {
	enum { value = __CheckType<T>::IsChar,
	};
};
template <typename T>
struct __CheckTypeBool {
	enum { value = __CheckType<T>::IsBool,
	};
};

class CheckTypeTool {
public:
	template <typename T>
	static bool IsString() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueString);
	}
	template <typename T>
	static bool IsInt() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueInt);
	}
	template <typename T>
	static bool IsFloat() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueFloat);
	}
	template <typename T>
	static bool IsDouble() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueDouble);
	}
	template <typename T>
	static bool IsLongLong() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueLongLong);
	}
	template <typename T>
	static bool IsChar() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueChar);
	}
	template <typename T>
	static bool IsBool() {
		return (__CheckType<T>::value == __CheckTypeValue::CheckTypeValueBool);
	}

	template <typename T>
	static void CheckStaticString() {
		static_assert(__CheckTypeString<T>::value, "CheckStaticString");
	}
	template <typename T>
	static void CheckStaticInt() {
		static_assert(__CheckTypeInt<T>::value, "CheckStaticInt");
	}
	template <typename T>
	static void CheckStaticFloat() {
		static_assert(__CheckTypeFloat<T>::value, "CheckStaticFloat");
	}
	template <typename T>
	static void CheckStaticDouble() {
		static_assert(__CheckTypeDouble<T>::value, "CheckStaticDouble");
	}
	template <typename T>
	static void CheckStaticLongLong() {
		static_assert(__CheckTypeLongLong<T>::value, "CheckStaticLongLong");
	}
	template <typename T>
	static void CheckStaticChar() {
		static_assert(__CheckTypeChar<T>::value, "CheckStaticChar");
	}
	template <typename T>
	static void CheckStaticBool() {
		static_assert(__CheckTypeBool<T>::value, "CheckStaticBool");
	}
};
} // namespace Base
} // namespace GCL