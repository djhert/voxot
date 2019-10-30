#ifndef _CHUNK_H_
#define _CHUNK_H_

#include "block.hpp"
#include "blockbin.hpp"
#include "meshdata.hpp"
#include "metablock.hpp"
#include "voxot.hpp"
#include "world.hpp"

using namespace godot;

namespace Voxot {

class Block;
class World;
class MeshData;

class Chunk : public MeshInstance {
	GDNATIVE_CLASS(Chunk, MeshInstance)

public:
	// Name of chunk
	String _name;

	virtual void Generate();

	void Render();
	void GenMesh();
	static String toName(const int &, const int &, const int &);

	void setup(World *, const int &, const int &, const int &);
	Block *GetBlock(const int &, const int &, const int &);
	bool DeleteBlock(const int &, const int &, const int &);
	bool SetBlock(const MetaBlock &, const int &, const int &, const int &);
	void dirty() { isDirty = true; };

	template <typename T>
	static T *New(World *w, const int &x, const int &y, const int &z) {
		T *newChunk = T::_new();
		newChunk->setup(w, x, y, z);
		return newChunk;
	}

	int X;
	int Y;
	int Z;

	int Width;
	int Height;
	int Depth;

protected:
	MetaBlock *Blocks;

	bool isDirty;
	bool isGenerating;
	bool doneGenerating;

	bool inBounds(const int &, const int &, const int &);

	static MetaBlock AirBlock;

	World *_world;
	StaticBody *staticBody;
	CollisionShape *collisionShape;

	Ref<SpatialMaterial> GetMaterial(const String &);
	Dictionary MaterialList;

	Array _meshArray;
	ArrayMesh *_mesh;
	ConcavePolygonShape *_collisionMesh;
};

} // namespace Voxot
#endif