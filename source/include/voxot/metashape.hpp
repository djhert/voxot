#ifndef __V_METASHAPE_HPP__
#define __V_METASHAPE_HPP__

#include <string>

namespace voxot {
struct MetaShape {
	std::string name;
	int type;

	MetaShape();
	MetaShape(std::string);
	MetaShape(std::string, int);

	bool operator==(const MetaShape &) const;
	bool operator!=(const MetaShape &) const;
};
} // namespace voxot

#endif