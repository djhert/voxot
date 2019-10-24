#include "world.hpp"

namespace Voxot {

REGISTER_CLASS(World);

float World::tileSize;

World::World() {}

World::~World() {}

void World::_register_methods() {
	GDNATIVE_REGISTER(World)
	World::Register<World>();
}

void World::_init() {
	ChunkWidth = 12;
	ChunkHeight = 12;
	ChunkDepth = 12;
	tiles = 2;

	Chunklist = Dictionary::make<String, Variant>("default", GODOT_VARIANT_TYPE_NIL);

	BlockBin::instance().Init();

	Init();
}

void World::_ready() {
	tileSize = 1.0f / tiles;
	Generate();
	Ready();
}

Chunk *World::_NewChunk(const String &name) {
	if (!Chunklist.has(name)) {
#ifdef DEBUG
		Godot::print("Unable to find chunk " + name);
#endif
		return nullptr;
	}
	Ref<PackedScene> c = Chunklist[name];
	return Node::cast_to<Chunk>(c->instance());
}

void World::_process(double delta) {
	Update(delta);
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

void World::settilesize(int t) {
	tiles = t;
}

int World::gettilesize() {
	return tiles;
}

bool World::AddBlock(const Vector3 &place, MetaBlock meta) {
	int chunkX = floor(place.x / ChunkWidth) * ChunkWidth;
	int chunkY = floor(place.y / ChunkHeight) * ChunkHeight;
	int chunkZ = floor(place.z / ChunkDepth) * ChunkDepth;

	Chunk *a = GetChunk(Chunk::toName(chunkX, chunkY, chunkZ));
	if (!a)
		return false;
	int blockX = place.x - a->X;
	int blockY = place.y - a->Y;
	int blockZ = place.z - a->Z;
	Godot::print("Add Block X: " + String::num(blockX) + " | Block Y: " + String::num(blockY) + " Block Z: " + String::num(blockZ));

	return false;
}

bool World::DeleteBlock(const Vector3 &place) {
	int chunkX = floor(place.x / ChunkWidth) * ChunkWidth;
	int chunkY = floor(place.y / ChunkHeight) * ChunkHeight;
	int chunkZ = floor(place.z / ChunkDepth) * ChunkDepth;

	Chunk *a = GetChunk(Chunk::toName(chunkX, chunkY, chunkZ));
	if (!a)
		return false;
	int blockX = place.x - a->X;
	int blockY = place.y - a->Y;
	int blockZ = place.z - a->Z;

	return a->DeleteBlock(blockX, blockY, blockZ);
}

Chunk *World::GetChunk(const String &name) {
	const NodePath &path = NodePath(name);
	if (has_node(path)) {
		return Node::cast_to<Chunk>(get_node(path));
	}
	return nullptr;
}

MetaBlock *GetBlock(const Vector3 &place) {
	return new MetaBlock("air", 0);
}

} // namespace Voxot