#include "voxot/shapekey.hpp"

namespace voxot {

ShapeKey &ShapeKey::Get() {
	static ShapeKey instance;
	return instance;
}

/*Vector3 ShapeKey::At(const int &x, const int &y, const int &z,
		const int &index, const float &height) {
	return Vector3(key[index].x + x, y + height, key[index].y + z);
}*/

} // namespace voxot