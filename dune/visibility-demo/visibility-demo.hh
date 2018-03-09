#ifndef DUNE_VISIBILITY_DEMO_HH
#define DUNE_VISIBILITY_DEMO_HH

#include <dune/common/visibility.hh>

namespace xtvis {
  struct DUNE_EXPORT VisibleSingleton {

    DUNE_EXPORT static VisibleSingleton& instance() {
      static VisibleSingleton visible_instance;
      return visible_instance;
    }

    int count;

    VisibleSingleton()
        :count(0)
    {}
  };

  struct HiddenSingleton {

    static HiddenSingleton& instance() {
      static HiddenSingleton hidden_instance;
      return hidden_instance;
    }

    int count;

    HiddenSingleton()
        :count(0)
    {}
  };
}

#endif // DUNE_VISIBILITY_DEMO_HH
