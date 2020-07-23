/*
	By Jenocn
	https://jenocn.github.io/

	Encoding: UTF-8 with BOM
*/

#pragma once

#include <math.h>

namespace GCL {
namespace Base {

class MathTool {
public:
	// PI
	static constexpr float PI{ 3.141593f };
	// 弧度/每角度 (PI / 180)
	static constexpr float RADIAN_PER_ANGLE{ PI / 180.0f };
	// 角度/每弧度 (180 / PI)
	static constexpr float ANGLE_PER_RADIAN{ 180.0f / PI };
};
}
}