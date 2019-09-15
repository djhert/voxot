#ifndef _CHUNK_H_
#define _CHUNK_H_

#include "../voxot.hpp"
#include <ArrayMesh.hpp>
#include <Mesh.hpp>
#include <SceneTree.hpp>

using namespace godot;

class Block;
class VoxotWorld;

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

	void setup(VoxotWorld *, int, int);

	void dirty();

protected:
	Block ***Blocks;

	int width;
	int height;
	int depth;

	int x;
	int y;

	bool isDirty;

private:
	VoxotWorld *_world;
};

#endif