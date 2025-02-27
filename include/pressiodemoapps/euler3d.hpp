
#ifndef PRESSIODEMOAPPS_EULER3D_INC_HPP_
#define PRESSIODEMOAPPS_EULER3D_INC_HPP_

#include "./predicates/all.hpp"
#include "./container_fncs/all.hpp"
#include "./mesh.hpp"
#include "./schemes_info.hpp"
#include "./euler_compute_energy.hpp"
#include "./adapter_cpp.hpp"
#include "./adapter_py.hpp"

namespace pressiodemoapps{

// ----------------------------------------------------------
// enums identifying the problems
// ----------------------------------------------------------
enum class Euler3d{
  PeriodicSmooth,
  SedovSymmetry
};
}//end namespace pressiodemoapps

// this include is here because needs visiblity of the enums above
#include "./impl/euler_3d_prob_class.hpp"

namespace pressiodemoapps{

// ----------------------------------------------------------
// create a default problem
// ----------------------------------------------------------

template<
  class mesh_t,
  class RetType = PublicProblemEigenMixinCpp<impleuler3d::EigenApp<mesh_t>>
  >
RetType
// bindings need unique nameing or we get error associated with overloads
#if defined PRESSIODEMOAPPS_ENABLE_BINDINGS
  create_euler_3d_problem_default_for_py
#else
  create_problem_eigen
#endif
(const mesh_t & meshObj,
 Euler3d problemEnum,
 InviscidFluxReconstruction recEnum)
{

  return RetType(meshObj, problemEnum, recEnum,
		 InviscidFluxScheme::Rusanov);
}

// ----------------------------------------------------------
// create a default problem with specific initial condition
// ----------------------------------------------------------

template<
  class mesh_t,
  class RetType = PublicProblemEigenMixinCpp<impleuler3d::EigenApp<mesh_t>>
  >
RetType
// bindings need unique nameing or we get error associated with overloads
#if defined PRESSIODEMOAPPS_ENABLE_BINDINGS
  create_euler_3d_problem_ov1_for_py
#else
  create_problem_eigen
#endif
(const mesh_t & meshObj,
 Euler3d problemEnum,
 InviscidFluxReconstruction recEnum,
 int icId)
{
  return RetType(meshObj, problemEnum, recEnum,
		 InviscidFluxScheme::Rusanov);
}

}//end namespace pressiodemoapps
#endif
