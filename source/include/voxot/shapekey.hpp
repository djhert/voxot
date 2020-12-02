#ifndef __V_SHAPEKEY_HPP__
#define __V_SHAPEKEY_HPP__

#include <Godot.hpp>

using namespace godot;

namespace voxot {
class ShapeKey {
public:
	static ShapeKey &Get();
	//	Vector3 At(const int &, const int &, const int &,
	//			const int &, const float &);

private:
	ShapeKey() = default;
	~ShapeKey() = default;

	//const static Vector2 key[25];
};
} // namespace voxot

#endif