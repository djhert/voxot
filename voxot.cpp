#include "voxot.hpp"
#include "chunk.hpp"
#include "world.hpp"

namespace Voxot {
void RegisterVoxot() {
	godot::register_class<World>();
	godot::register_class<Chunk>();
}
} // namespace Voxot