#include "MathTool.h"
#include <random>

using namespace GCL::Base;

float MathTool::BezierAt(float a, float b, float c, float d, float t) {
	return (powf(1 - t, 3) * a +
			3 * t * (powf(1 - t, 2)) * b +
			3 * powf(t, 2) * (1 - t) * c +
			powf(t, 3) * d);
}

float MathTool::BezierLength(float startx, float starty, float cx0, float cy0, float cx1, float cy1, float endx, float endy, unsigned int precision) {
	precision = std::min<unsigned int>(10000, std::max<unsigned int>(1, precision));
	float dt = 1.0f / precision;
	float ct = 0;
	float sx = 0;
	float sy = 0;

	cx0 -= startx;
	cy0 -= starty;
	cx1 -= startx;
	cy1 -= starty;
	endx -= startx;
	endy -= starty;

	float length = 0;
	for (int i = 0; i < (int)precision; ++i) {
		float tx = BezierAt(0, cx0, cx1, endx, ct);
		float ty = BezierAt(0, cy0, cy1, endy, ct);

		float x = tx - sx;
		float y = ty - sy;

		length += sqrtf(x * x + y * y);
		
		sx = tx;
		sy = ty;

		ct += dt;
	}

	return length;
}
