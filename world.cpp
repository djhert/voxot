#include "world.hpp"

namespace Voxot {

float World::tileSize;

World::World() {}

World::~World() {
	MaterialList.clear();
}

void World::_register_methods() {
	register_property<World, int>("Chunk/Width", &World::setChunkWidth, &World::getChunkWidth, 12);
	register_property<World, int>("Chunk/Height", &World::setChunkHeight, &World::getChunkHeight, 12);
	register_property<World, int>("Chunk/Depth", &World::setChunkDepth, &World::getChunkDepth, 12);

	register_property<World, Dictionary>("Material/Materials", &World::MaterialList, Dictionary::make<String, Variant>("default", GODOT_VARIANT_TYPE_NIL));
	register_property<World, int>("Material/Tiles", &World::settilesize, &World::gettilesize, 2);

	register_method("_ready", &World::_ready);
	register_method("_process", &World::_process);
}

void World::_init() {
	ChunkWidth = 12;
	ChunkHeight = 12;
	ChunkDepth = 12;
	tiles = 2;

	MaterialList = Dictionary::make<String, Variant>("default", GODOT_VARIANT_TYPE_NIL);

	BlockBin::instance().Init();

	Init();
}

void World::_ready() {
	tileSize = 1.0f / tiles;
	Generate();
	Ready();
}

Ref<SpatialMaterial> World::GetMaterial(String name) {
	if (!MaterialList.has(name)) {
#ifdef DEBUG
		Godot::print("Unable to find material " + name);
#endif
		return nullptr;
	}
	return MaterialList[name];
}

void World::Generate() {
	this->add_child(Chunk::New<Chunk>(this, 0, 0, 0));
	this->add_child(Chunk::New<Chunk>(this, ChunkWidth, 0, 0));
	this->add_child(Chunk::New<Chunk>(this, 0, 0, ChunkDepth));
	this->add_child(Chunk::New<Chunk>(this, ChunkWidth, 0, ChunkDepth));
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