#include "chunk.hpp"

namespace Voxot {
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

String Chunk::toName(int x, int y) {
	std::string out;
	if (x < 10)
		out = "0" + std::to_string(x);
	else
		out = std::to_string(x);

	if (y < 10)
		out = out + "0" + std::to_string(y);
	else
		out = out + std::to_string(y);

	return String(out.c_str());
}

void Chunk::_register_methods() {
	register_method("_process", &Chunk::_process);
}

void Chunk::_init() {
}

void Chunk::setup(World *w, int posx, int posy) {
#ifdef DEBUG
	Godot::print("Chunk setup");
#endif
	_world = w;
	width = _world->getChunkWidth();
	height = _world->getChunkHeight();
	depth = _world->getChunkDepth();
	x = posx;
	y = posy;
	Vector3 pos = Vector3(x, 0, y);
	Transform t = get_transform();
	t.origin = pos;
	set_transform(t);
	set_name(toName(x, y));

	Blocks = new int **[width];
	for (int x = 0; x < width; x++) {
		Blocks[x] = new int *[height];
		for (int y = 0; y < height; y++) {
			Blocks[x][y] = new int[depth];
		}
	}
	isDirty = false;
	Generate();
	Render();
	//	Build();
}

void Chunk::_process(float delta) {
	if (isDirty) {
		Build();
		Render();
		isDirty = false;
	}
	Update();
}

void Chunk::Init() {
}

void Chunk::Generate() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				if (y % 2 == 0) {
					Blocks[x][y][z] = 0;
					continue;
				}
				Blocks[x][y][z] = 1;
			}
		}
	}
}

void Chunk::Build() {
}

void Chunk::Render() {
	PoolVector3Array data = PoolVector3Array();
	ArrayMesh *mesh = ArrayMesh::_new();

	Array array = Array();

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				((Block *)BlockBin::Get("air"))->Draw(this, &data, x, y, z);
			}
		}
	}

	array.resize(ArrayMesh::ARRAY_MAX);
	array[ArrayMesh::ARRAY_VERTEX] = data;

#ifdef DEBUG
	Godot::print("Dataset Size: " + Chunk::toName(0, data.size()));
#endif

	mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, array);
	set_mesh(mesh);
}

void Chunk::Update() {
}
} // namespace Voxot