#ifndef __V_MESHDATA_HPP__
#define __V_MESHDATA_HPP__

#include <Godot.hpp>

using namespace godot;

namespace voxot {
class MeshData {
public:
	PoolVector3Array verts;
	PoolVector3Array normals;
	PoolVector2Array uvs;
	PoolRealArray tangents;

	MeshData() = default;
	~MeshData() = default;

	/*	void Square(const Vector3 &, const Vector3 &,
			const Vector3 &, const Vector3 &);*/
	void UVSquare(const Vector3 &vbl, const Vector3 &vbr,
			const Vector3 &vtl, const Vector3 &vtr,
			const Vector2 &ubl, const Vector2 &ubr,
			const Vector2 &utl, const Vector2 &utr);

private:
	void calcNormal(const Vector3 &a, const Vector3 &b, const Vector3 &c);
	void calcTangent(const Vector3 &a, const Vector3 &b, const Vector3 &c,
			const Vector2 &uva, const Vector2 &uvb, const Vector2 &uvc);
};
} // namespace voxot

using namespace godot;

#endif