
#include "pressio/ode_steppers_explicit.hpp"
#include "pressio/ode_advancers.hpp"
#include "pressiodemoapps/swe2d.hpp"
#include <random>

std::mt19937 gen(2195884);
std::uniform_real_distribution<double> distrib(1.1, 2.0);

template<class T>
void writeToFileRank1(const T & obj, const std::string & fileName)
{
  std::ofstream file; file.open(fileName);
  for (size_t i=0; i<obj.rows(); i++){
    file << std::setprecision(14) << obj(i) << " \n";
  }
  file.close();
}

template<class T>
void writeToFileSparseMat(const T & obj, const std::string & fileName)
{
  std::ofstream file; file.open(fileName);
  for (size_t i=0; i<obj.rows(); i++){
    for (size_t j=0; j<obj.cols(); j++){
      file << std::setprecision(14) << obj.coeff(i,j) << " ";
    }
    file << " \n";
  }
  file.close();
}

int main(int argc, char *argv[])
{
  namespace pda = pressiodemoapps;
  const auto meshObj = pda::load_cellcentered_uniform_mesh_eigen(".");
#ifdef USE_WENO5
  const auto order   = pda::InviscidFluxReconstruction::Weno5;
#elif defined USE_WENO3
  const auto order   = pda::InviscidFluxReconstruction::Weno3;
#else
  const auto order   = pda::InviscidFluxReconstruction::FirstOrder;
#endif

  const auto probId  = pda::Swe2d::SlipWall;
  auto appObj      = pda::create_problem_eigen(meshObj, probId, order);
  using app_t = decltype(appObj);
  using state_t = typename app_t::state_type;
  using scalar_t = typename app_t::scalar_type;

  const auto stateSize = appObj.totalDofStencilMesh();
  state_t state(stateSize);
  const auto &x = meshObj.viewX();
  const auto &y = meshObj.viewY();
  for (int i=0; i<x.size(); ++i){

    const auto a = 1. + 0.1*x(i) + 0.2*y(i);
    const auto b = 2. + 0.1*x(i) + 0.2*y(i);
    const auto c = 3. + 0.1*x(i) + 0.2*y(i);

    const auto ind = i*3;
    state(ind)   = a;
    state(ind+1) = b;
    state(ind+2) = c;
  }

  auto time = 0.0;
  auto velo = appObj.createVelocity();
  auto jac  = appObj.createJacobian();

  appObj.velocityAndJacobian(state, time, velo, jac);
  writeToFileRank1(state,   "state.txt");
  writeToFileRank1(velo,    "velo.txt");
  writeToFileSparseMat(jac, "jacobian.txt");
  return 0;
}
