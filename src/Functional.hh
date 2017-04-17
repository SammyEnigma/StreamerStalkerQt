#pragma once

#include <algorithm>

namespace fnc {
    template<class Range, class Pred>
    auto find_if(Range&& rng, Pred&& pred) -> decltype(begin(rng)) {
        return std::find_if(begin(rng),end(rng),pred);
    }

}
