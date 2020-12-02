#include "voxot/shapebin.hpp"

namespace voxot {

Shape *ShapeBin::Get(const std::string &typeName) {
	auto it = objs.find(typeName);
	if (it != objs.end()) {
		return it->second;
	}

	return nullptr;
}

bool ShapeBin::Register(const std::string &typeName, const instanceGen &funcCreate) {
	return generators.insert(std::make_pair(typeName, funcCreate)).second;
}

void ShapeBin::Init() {
	for (auto const &x : generators) {
		objs.insert(std::make_pair(x.first, x.second()));
	}
	generators.clear();
}

ShapeBin &ShapeBin::instance() {
	static ShapeBin instance;
	return instance;
}
} // namespace voxot