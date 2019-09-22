#include "world.hpp"

namespace Voxot {
void World::_register_methods() {
	register_property<World, int>("Chunk/Width", &World::setChunkWidth, &World::getChunkWidth, 12);
	register_property<World, int>("Chunk/Height", &World::setChunkHeight, &World::getChunkHeight, 12);
	register_property<World, int>("Chunk/Depth", &World::setChunkDepth, &World::getChunkDepth, 12);

	register_method("_process", &World::_process);
}

void World::_init() {
	isInit = false;
	ChunkWidth = 12;
	ChunkHeight = 12;
	ChunkDepth = 12;

	bool registered = BlockBin::Register("air", BlockAir::Create);
	BlockBin::Init();
	resources = ResourceLoader::get_singleton();
}

void World::CreateChunk(String path, int x, int y) {
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

void World::Generate() {
	//	BlockBin::Register(0, new BlockAir());
	//	BlockBin::Register(1, new BlockSolid());

	CreateChunk("scenes/Chunk.tscn", 0, 0);
//	CreateChunk("scenes/Chunk.tscn", ChunkWidth, 0);
//	CreateChunk("scenes/Chunk.tscn", ChunkWidth * 2, 0);
//	CreateChunk("scenes/Chunk.tscn", 0, ChunkDepth);
//	CreateChunk("scenes/Chunk.tscn", ChunkWidth, ChunkDepth);
#ifdef DEBUG
	int count = get_child_count();
	for (int i = 0; i < count; i++) {
		Node *temp = get_child(i);
		Godot::print("Chunk: " + temp->get_name());
	}
	Godot::print("world made");
#endif
}

void World::_process(float delta) {
	if (!isInit) {
		isInit = true;
		Generate();
	}
	Update();
}

void World::Init() {
}

void World::Update() {
}

void World::setChunkWidth(int w) {
	ChunkWidth = w;
}

int World::getChunkWidth() {
	return ChunkWidth;
}

void World::setChunkHeight(int h) {
	ChunkHeight = h;
}

int World::getChunkHeight() {
	return ChunkHeight;
}

void World::setChunkDepth(int d) {
	ChunkDepth = d;
}

int World::getChunkDepth() {
	return ChunkDepth;
};
} // namespace Voxot