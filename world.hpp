#ifndef _WORLD_H_
#define _WORLD_H_

#include "block.hpp"
#include "blockbin.hpp"
#include "chunk.hpp"
#include "voxot.hpp"

#include <iostream>

using namespace godot;

namespace Voxot {

class Chunk;

class World : public Spatial {
	GDNATIVE_CLASS(World, Spatial);

public:
	String _name;

	virtual void Generate(){};

	void setChunkWidth(int);
	int getChunkWidth();

	void setChunkHeight(int);
	int getChunkHeight();

	void setChunkDepth(int);
	int getChunkDepth();

	void settilesize(int);
	int gettilesize();

	Ref<SpatialMaterial> GetMaterial(String);

	static float tileSize;

	Chunk *GetChunk(const String &);

	bool AddBlock(const Vector3 &, MetaBlock);
	bool DeleteBlock(const Vector3 &);
	MetaBlock *GetBock(const Vector3 &);

	template <typename T>
	static void Register() {
		register_property<T, int>("Chunk/Width", &T::setChunkWidth, &T::getChunkWidth, 12);
		register_property<T, int>("Chunk/Height", &T::setChunkHeight, &T::getChunkHeight, 12);
		register_property<T, int>("Chunk/Depth", &T::setChunkDepth, &T::getChunkDepth, 12);

		register_property<T, Dictionary>("Material/Materials", &T::MaterialList, Dictionary::make<String, Variant>("default", GODOT_VARIANT_TYPE_NIL));
		register_property<T, int>("Material/Tiles", &T::settilesize, &T::gettilesize, 2);
	};

protected:
	int ChunkWidth;
	int ChunkHeight;
	int ChunkDepth;

	int WorldWidth;
	int WorldHeight;

	int tiles;

	Dictionary MaterialList;

	void LoadMaterials();
};

} // namespace Voxot

#endif