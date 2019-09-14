#include "world.hpp"

void VoxotWorld::_register_methods() {
	register_property<VoxotWorld, int>("Chunk/Width", &VoxotWorld::setChunkWidth, &VoxotWorld::getChunkWidth, 12);
	register_property<VoxotWorld, int>("Chunk/Height", &VoxotWorld::setChunkHeight, &VoxotWorld::getChunkHeight, 12);
	register_property<VoxotWorld, int>("Chunk/Depth", &VoxotWorld::setChunkDepth, &VoxotWorld::getChunkDepth, 12);
}

void VoxotWorld::_init() {
#ifdef DEBUG
	Godot::print("hello world");
#endif
	resources = ResourceLoader::get_singleton();
	CreateChunk("scenes/Chunk.tscn", 2, 0);
	CreateChunk("scenes/Chunk.tscn", 0, 1);
	CreateChunk("scenes/Chunk.tscn", -2, 2);
	int count = get_child_count();
	for (int i = 0; i < count; i++) {
		Node *temp = get_child(i);
	}
#ifdef DEBUG
	Godot::print("world made");
#endif
}

void VoxotWorld::CreateChunk(String path, int x, int y) {
	Chunk *newChunk;
	Ref<PackedScene> res = resources->load(path);
	if (res.is_valid()) {
		newChunk = Object::cast_to<Chunk>(res->instance());
		if (newChunk) {
			newChunk->setup(this, x, y);
		} else
			return;
	}
	std::string out = std::to_string(x) + std::to_string(y);
	newChunk->set_name(String(out.c_str()));
	this->add_child(newChunk);
}

void VoxotWorld::_process(float delta) {
}

void VoxotWorld::setChunkWidth(int w) {
	ChunkWidth = w;
}

int VoxotWorld::getChunkWidth() {
	return ChunkWidth;
}

void VoxotWorld::setChunkHeight(int h) {
	ChunkHeight = h;
}

int VoxotWorld::getChunkHeight() {
	return ChunkHeight;
}

void VoxotWorld::setChunkDepth(int d) {
	ChunkDepth = d;
}

int VoxotWorld::getChunkDepth() {
	return ChunkDepth;
};