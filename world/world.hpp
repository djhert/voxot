#ifndef _WORLD_H_
#define _WORLD_H_

#include "../voxot.hpp"
#include <string>

using namespace godot;

class Chunk;

class VoxotWorld : public Spatial {
	GODOT_CLASS(VoxotWorld, Spatial);

public:
	String _name;

	static void _register_methods();
	void _init();
	void _process(float);

	void setChunkWidth(int);
	int getChunkWidth();

	void setChunkHeight(int);
	int getChunkHeight();

	void setChunkDepth(int);
	int getChunkDepth();

	void CreateChunk(String, int, int);

protected:
	int ChunkWidth;
	int ChunkHeight;
	int ChunkDepth;

	int WorldWidth;
	int WorldHeight;

	//Chunk **Chunks;
	Chunk *chunk;

	ResourceLoader *resources;
};

#endif