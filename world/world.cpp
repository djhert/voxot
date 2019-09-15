#include "world.hpp"

void VoxotWorld::_register_methods() {
	register_property<VoxotWorld, int>("Chunk/Width", &VoxotWorld::setChunkWidth, &VoxotWorld::getChunkWidth, 12);
	register_property<VoxotWorld, int>("Chunk/Height", &VoxotWorld::setChunkHeight, &VoxotWorld::getChunkHeight, 12);
	register_property<VoxotWorld, int>("Chunk/Depth", &VoxotWorld::setChunkDepth, &VoxotWorld::getChunkDepth, 12);

	register_method("_process", &VoxotWorld::_process);
}

void VoxotWorld::_init() {
	isInit = false;
	ChunkWidth = 12;
	ChunkHeight = 12;
	ChunkDepth = 12;

	resources = ResourceLoader::get_singleton();
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
	this->add_child(newChunk);
}

void VoxotWorld::Generate() {
	CreateChunk("scenes/Chunk.tscn", 0, 0);
	CreateChunk("scenes/Chunk.tscn", ChunkWidth, 0);
	CreateChunk("scenes/Chunk.tscn", ChunkWidth * 2, 0);
	CreateChunk("scenes/Chunk.tscn", 0, ChunkDepth);
	CreateChunk("scenes/Chunk.tscn", ChunkWidth, ChunkDepth);
	CreateChunk("scenes/Chunk.tscn", ChunkWidth * 2, ChunkDepth);
#ifdef DEBUG
	int count = get_child_count();
	for (int i = 0; i < count; i++) {
		Node *temp = get_child(i);
		Godot::print("Chunk: " + temp->get_name());
	}
	Godot::print("world made");
#endif
}

void VoxotWorld::_process(float delta) {
	if (!isInit) {
		isInit = true;
		Generate();
	}
	Update();
}

void VoxotWorld::Init() {
}

void VoxotWorld::Update() {
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