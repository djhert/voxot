#ifndef _CHUNK_H_
#define _CHUNK_H_

#include "../voxot.hpp"
#include <ArrayMesh.hpp>
#include <Mesh.hpp>

using namespace godot;

class Block;
class VoxotWorld;

class Chunk : public MeshInstance {
	GODOT_CLASS(Chunk, MeshInstance);

public:
	String _name;

	static void _register_methods();
	void _init();
	void _process(float);
	void _render();

	void setup(VoxotWorld *, int, int);

	Chunk();
	~Chunk();

protected:
	Block ***Blocks;

	int width;
	int height;

	int x;
	int y;

private:
	VoxotWorld *_world;
};

#endif