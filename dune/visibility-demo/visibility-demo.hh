#ifndef DUNE_VISIBILITY_DEMO_HH
#define DUNE_VISIBILITY_DEMO_HH

#include <dune/common/visibility.hh>

namespace xtvis {
  struct VisibleSingleton {

    DUNE_EXPORT static VisibleSingleton& instance() {
      static VisibleSingleton s;
      return s;
    }

    int count;

    VisibleSingleton()
        :count(0)
    {}
  };

  struct HiddenSingleton {

    static HiddenSingleton& instance() {
      static HiddenSingleton s;
      return s;
    }

    int count;

    HiddenSingleton()
        :count(0)
    {}
  };
}

#endif // DUNE_VISIBILITY_DEMO_HH
