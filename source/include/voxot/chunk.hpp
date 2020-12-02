#ifndef __V_CHUNK_HPP__
#define __V_CHUNK_HPP__

#include <Spatial.hpp>
#include <SpatialMaterial.hpp>

#include <File.hpp>
#include <OS.hpp>

#include <gdregistry.hpp>

#include "flatbuffers/flatbuffers.h"
#include "voxot/fb/chunk_generated.h"

using namespace godot;

namespace voxot {

class Chunk : public Spatial {
	GDCLASS(Chunk, Spatial)

protected:
	// Exposed Variables
	Ref<SpatialMaterial> _material;

	File *file;

	// Internal Variables

	// Exposed Functions

	//Internal Functions
};

} // namespace voxot

#endif