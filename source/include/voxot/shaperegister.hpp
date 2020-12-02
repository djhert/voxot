#ifndef __V_SHAPEREGISTER_HPP__
#define __V_SHAPEREGISTER_HPP__

#include "voxot/shapebin.hpp"

namespace voxot {
namespace ShapeRegister {
template <typename T>
class Registration {
public:
	Registration(const char *id) {
		ShapeBin::instance().Register(id, []() { return static_cast<Shape *>(new T()); })
	}
}
}; // namespace ShapeRegister
} // namespace voxot

#endif