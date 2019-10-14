#include "blockair.hpp"

namespace Voxot {

namespace BlockRegister {
Registration<BlockAir> _BlockAir("air");
}

const MetaBlock BlockAir::Block = { "air", 0 };

} // namespace Voxot