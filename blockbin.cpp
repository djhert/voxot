#include "blockbin.hpp"

namespace Voxot {

BlockBin::_bbin BlockBin::_blocks = [] {
	_bbin ret;
	return ret;
}();

BlockBin::_bvec BlockBin::_storage = [] {
	_bvec ret;
	return ret;
}();

bool BlockBin::Register(std::string key, std::function<VBlock *()> fc) {
	if (auto it = _storage.find(key); it == _storage.end()) {
		_storage[key] = fc;
		return true;
	}
	return false;
}

bool BlockBin::Init() {
	for (auto &fn : _storage) {
		add(fn.first, (fn.second)());
	}
	return true;
}

void BlockBin::add(std::string key, VBlock *block) {
	if (auto it = _blocks.find(key); it == _blocks.end())
		_blocks[key] = block;
}

Block *BlockBin::Get(std::string key) {
	if (auto it = _blocks.find(key); it != _blocks.end()) {
		return (Block *)_blocks[key];
	}
	return nullptr;
}
} // namespace Voxot