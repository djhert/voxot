#include "voxot/world.hpp"

namespace voxot {

GDREGISTER(World)

World::~World() {}

void World::_init() {
	_chunkList = Dictionary::make();
	_chunkSize = Vector3(0, 0, 0);

	Chunk *_test = Chunk::_new();
	add_child(_test);
}

void World::_register_methods() {
	Register<World>();
}

void World::setChunkSize(Vector3 size) {
	_chunkSize.x = std::round(size.x);
	_chunkSize.y = std::round(size.y);
	_chunkSize.z = std::round(size.z);
}

void World::setWorldSize(Vector3 size) {
	_worldSize.x = std::round(size.x);
	_worldSize.y = std::round(size.y);
	_worldSize.z = std::round(size.z);
}

} // namespace voxot