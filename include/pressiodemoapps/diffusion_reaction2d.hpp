
#ifndef PRESSIODEMOAPPS_DIFFUSION_REACTION_HPP_
#define PRESSIODEMOAPPS_DIFFUSION_REACTION_HPP_

/*
  diffusion-reaction enumerations and public APIs
*/

#include "./predicates/all.hpp"
#include "./container_fncs/all.hpp"
#include "./mesh.hpp"
#include "./schemes_info.hpp"
#include "./adapter_mixins.hpp"

namespace pressiodemoapps{

enum class DiffusionReaction2d{
  /*
    ds/dt = D (d^2s/d^2x + d^2s/d^2y) + k*s^2 + u(x, y, t)

    BC: ghost cells are set such that s is zero at boundary

    D, k, u(x, y, t) can be provided to constructor
    u(x, y, t) must be a functor:
      void operator()(const scalar_t & x,
		      const scalar_t & y,
		      const scalar_t & time,
		      scalar_t & value);

    Default:
    D, k = 0.01, 0.01
    u(x, y, t) = std::sin(M_PI*x*(y-0.2)) * 4.*std::sin(4.*M_PI*y*x);

   */
  ProblemA,

  /*
    two species:
    du/dt = Laplacian(u) + F(1-u) - u*v^2
    dv/dt = Laplacian(v) + (F+k)v + u*v^2

    where F is feeding rate, k is kill rate
    periodic BC

   */
  GrayScott
};

}//end namespace pressiodemoapps

// this include is here because needs visiblity of the enums above
#include "./impl/diffusion_reaction_2d_prob_class.hpp"

namespace pressiodemoapps{

#if not defined PRESSIODEMOAPPS_ENABLE_BINDINGS
template<class mesh_t, class ...Args>
auto create_problem_eigen(const mesh_t & meshObj,
			::pressiodemoapps::DiffusionReaction2d probEnum,
			::pressiodemoapps::ViscousFluxReconstruction recEnum,
			Args && ... args)
{
  impldiffreac::check_stencil_admissibility(meshObj, recEnum);
  using RetType = PublicProblemMixinCpp<impldiffreac::EigenDiffReac2dApp<mesh_t>>;
  return RetType(meshObj, probEnum, recEnum, std::forward<Args>(args)...);
}

#endif

} //end namespace pressiodemoapps
#endif




// namespace impldiffreac{
// template<class mesh_t>
// void check_stencil_admissibility(const mesh_t & meshObj,
// 			       ::pressiodemoapps::ViscousFluxReconstruction recEnum)
// {
//   const auto stencilSize = meshObj.stencilSize();
//   const auto check1 = stencilSizeCompatibleWithViscousFluxReconstruction(recEnum, stencilSize);
//   if (!check1){
//     throw std::runtime_error
//       ("Stencil size in the mesh object not compatible with desired viscous flux reconstruction.");
//   }
// }

// #ifdef PRESSIODEMOAPPS_ENABLE_BINDINGS
// template<class mesh_t, class T, class ProbType>
// T create_problem_for_pyA(const mesh_t & meshObj,
// 			 ProbType probEnum,
// 			 ::pressiodemoapps::ViscousFluxReconstruction recEnum)
// {
//   impldiffreac::check_stencil_admissibility(meshObj, recEnum);
//   return T(meshObj, probEnum, recEnum);
// }

// template<class mesh_t, class T, class ProbType>
// T create_problem_for_pyB(const mesh_t & meshObj,
// 			 ProbType probEnum,
// 			 ::pressiodemoapps::ViscousFluxReconstruction recEnum,
// 			 typename mesh_t::scalar_t diffusionCoeff,
// 			 typename mesh_t::scalar_t reactionCoeff)
// {
//   impldiffreac::check_stencil_admissibility(meshObj, recEnum);
//   return T(meshObj, probEnum, recEnum, diffusionCoeff, reactionCoeff);
// }

// template<class mesh_t, class T>
// T create_problem_for_pyC1d(const mesh_t & meshObj,
// 			   ::pressiodemoapps::DiffusionReaction1d probEnum,
// 			   ::pressiodemoapps::ViscousFluxReconstruction recEnum,
// 			   // source term is passed as a Python functor
// 			   pybind11::object pyFunctor,
// 			   typename mesh_t::scalar_t diffusionCoeff,
// 			   typename mesh_t::scalar_t reactionCoeff)
// {
//   impldiffreac::check_stencil_admissibility(meshObj, recEnum);
//   using scalar_t = typename mesh_t::scalar_t;
//   auto sourceWrapper = [=](const scalar_t & x, const scalar_t & evaltime, scalar_t & value){
//     value = pyFunctor.attr("__call__")(x, evaltime).template cast<scalar_t>();
//   };

//   return T(meshObj, probEnum, recEnum, sourceWrapper, diffusionCoeff, reactionCoeff);
// }

// template<class mesh_t, class T>
// T create_problem_for_pyC2d(const mesh_t & meshObj,
// 			   ::pressiodemoapps::DiffusionReaction2d probEnum,
// 			   ::pressiodemoapps::ViscousFluxReconstruction recEnum,
// 			   // source term is passed as a Python functor
// 			   pybind11::object pyFunctor,
// 			   typename mesh_t::scalar_t diffusionCoeff,
// 			   typename mesh_t::scalar_t reactionCoeff)
// {
//   impldiffreac::check_stencil_admissibility(meshObj, recEnum);
//   using scalar_t = typename mesh_t::scalar_t;
//   auto sourceWrapper = [=](const scalar_t & x,
// 			   const scalar_t & y,
// 			   const scalar_t & evaltime,
// 			   scalar_t & value){
//     value = pyFunctor.attr("__call__")(x, y, evaltime).template cast<scalar_t>();
//   };

//   return T(meshObj, probEnum, recEnum, sourceWrapper, diffusionCoeff, reactionCoeff);
// }

// template<class mesh_t, class T, class ProbType>
// T create_problem_for_pyD(const mesh_t & meshObj,
// 			 ProbType probEnum,
// 			 ::pressiodemoapps::ViscousFluxReconstruction recEnum,
// 			 typename mesh_t::scalar_t Da,
// 			 typename mesh_t::scalar_t Db,
// 			 typename mesh_t::scalar_t feedRate,
// 			 typename mesh_t::scalar_t killRate)
// {
//   impldiffreac::check_stencil_admissibility(meshObj, recEnum);
//   return T(meshObj, probEnum, recEnum, Da, Db, feedRate, killRate);
// }
//#endif
//} //end namespace impldiffreac
