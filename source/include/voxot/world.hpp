#ifndef __V_WORLD_HPP__
#define __V_WORLD_HPP__

#include <Dictionary.hpp>
#include <PackedScene.hpp>
#include <Spatial.hpp>

#include <gdregistry.hpp>

#include "voxot/chunk.hpp"

using namespace godot;

namespace voxot {

class World : public Spatial {
	GDCLASS(World, Spatial)

public:
	virtual void Generate(){};

	void setChunkSize(Vector3 size);
	Vector3 getChunkSize() { return _chunkSize; }

	void setWorldSize(Vector3 size);
	Vector3 getWorldSize() { return _worldSize; }

	template <typename T>
	static void Register() {
		register_property<T, Vector3>("World Size",
				&T::setWorldSize, &T::getWorldSize, Vector3(0, 0, 0));
		register_property<T, Dictionary>("Chunk/Types", &T::_chunkList,
				Dictionary::make());
		register_property<T, Vector3>("Chunk/Size",
				&T::setChunkSize, &T::getChunkSize, Vector3(0, 0, 0));
	};

protected:
	Dictionary _chunkList;

	Vector3 _chunkSize;
	Vector3 _worldSize;

	// Exposed Functions
	//Internal Functions
};

} // namespace voxot

#endif