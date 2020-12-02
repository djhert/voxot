#ifndef __V_SHAPEBIN_HPP__
#define __V_SHAPEBIN_HPP__

#include <string>
#include <unordered_map>

namespace voxot {

class Shape;
typedef Shape *(*instanceGen)();

class ShapeBin {
public:
	static ShapeBin &instance();

	Shape *Get(const std::string &typeName);
	void Init();
	bool Register(const std::string &typeName,
			const instanceGen &funcCreate);

private:
	ShapeBin() = default;
	~ShapeBin() = default;

	ShapeBin(const ShapeBin &) = delete;
	void operator=(const ShapeBin &) = delete;

	std::unordered_map<std::string, instanceGen> generators;
	std::unordered_map<std::string, Shape *> objs;
};

} // namespace voxot

#endif