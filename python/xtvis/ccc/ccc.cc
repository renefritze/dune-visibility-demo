#include <dune/common/parallel/mpihelper.hh>
#include <dune/pybindxi/pybind11.h>
#include <dune/pybindxi/stl.h>

#include <python/dune/xt/common/bindings.hh>

#include <dune/visibility-demo/visibility-demo.hh>

PYBIND11_MODULE(_ccc, m)
{
  namespace py = pybind11;
  using namespace pybind11::literals;

  Dune::XT::Common::bindings::addbind_exceptions(m);

  Dune::XT::Common::bindings::add_initialization(m, "xtvis.ccc");

  xtvis::VisibleSingleton::instance().count += 1;
  xtvis::HiddenSingleton::instance().count += 1;

  m.def("_is_debug", []() {
#ifndef NDEBUG
    return true;
#else
    return false;
#endif
  });

  m.def("count", []() {
    return std::tuple<int, int>{xtvis::HiddenSingleton::instance().count, xtvis::VisibleSingleton::instance().count};
  });
}