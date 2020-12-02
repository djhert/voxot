#include "voxot/metashape.hpp"

namespace voxot {
MetaShape::MetaShape() {
	name = "air";
	type = 0;
}

MetaShape::MetaShape(std::string n) {
	name = n;
	type = 0;
}

MetaShape::MetaShape(std::string n, int t) {
	name = n;
	type = t;
}

bool MetaShape::operator==(const MetaShape &a) const {
	if (name == a.name)
		if (type == a.type)
			return true;
	return false;
}

bool MetaShape::operator!=(const MetaShape &a) const {
	if (name == a.name)
		if (type == a.type)
			return false;
	return true;
}
} // namespace voxot