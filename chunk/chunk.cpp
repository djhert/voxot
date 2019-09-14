#include "chunk.hpp"

Chunk::Chunk() {}
Chunk::~Chunk() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			delete[] Blocks[x][y];
		}
		delete[] Blocks[x];
	}
	delete[] Blocks;
}

void Chunk::_register_methods() {
	//	register_method("_process", &Chunk::_process);
}

void Chunk::_init() {
	//_render();
}

void Chunk::setup(VoxotWorld *w, int posx, int posy) {
#ifdef DEBUG
	Godot::print("Chunk setup");
#endif
	_world = w;
	width = _world->getChunkWidth();
	height = _world->getChunkHeight();
	x = posx;
	y = posy;
	Vector3 pos = Vector3(x, 0, y);
	Transform t = get_transform();
	t.origin = pos;
	set_transform(t);

	Blocks = new Block **[width];
	for (int x = 0; x < width; x++) {
		Blocks[x] = new Block *[height];
		for (int y = 0; y < height; y++) {
			Blocks[x][y] = new Block[_world->getChunkDepth()];
		}
	}
}

void Chunk::_process(float delta) {
}

void Chunk::_render() {

	//set_mesh(sf->commit());
}