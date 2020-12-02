#include "voxot/chunk.hpp"

namespace voxot {

GDREGISTER(Chunk)

Chunk::~Chunk() {}

void Chunk::_init() {
	_material = Ref<SpatialMaterial>();
}

void Chunk::_register_methods() {
	// Variables
	register_property<Chunk, Ref<SpatialMaterial> >("Material",
			&Chunk::_material, Ref<SpatialMaterial>(),
			GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT,
			GODOT_PROPERTY_HINT_RESOURCE_TYPE, "SpatialMaterial");
}

} // namespace voxot