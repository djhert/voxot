#ifndef _CHUNK_H_
#define _CHUNK_H_

//#include "../block/block.hpp"
//#include "../block/types/blockair.hpp"
#include "block.hpp"
#include "blockair.hpp"
#include "blockbin.hpp"
#include "blocksolid.hpp"
#include "voxot.hpp"
#include "world.hpp"

using namespace godot;

namespace Voxot {

class Block;
class BlockAir;
class BlockSolid;
class World;

class Chunk : public MeshInstance {
	GODOT_CLASS(Chunk, MeshInstance);

public:
	// Constructor
	Chunk();
	// Destroyer
	~Chunk();

	// Name of chunk
	String _name;

	// Godot requirements
	static void _register_methods();
	void _init();
	void _process(float);

	// Chunk functions
	virtual void Generate();
	virtual void Init();
	virtual void Update();

	// Voxot functions
	void Build();
	void Render();
	static String toName(int, int);

	void setup(World *, int, int);

	void dirty();

protected:
	int ***Blocks;

	int width;
	int height;
	int depth;

	int x;
	int y;

	bool isDirty;

private:
	World *_world;
};
} // namespace Voxot
#endif