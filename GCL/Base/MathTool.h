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

	// 贝塞尔曲线获取目标点
	static float BezierAt(float start, float control0, float control1, float end, float timePercent);
	// 贝塞尔曲线获取长度
	static float BezierLength(float startx, float starty, float cx0, float cy0, float cx1, float cy1, float endx, float endy, unsigned int precision);
};
}
}