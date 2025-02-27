
#ifndef PRESSIODEMOAPPS_GHOST_FILLER_DIFFREAC_1D_HPP_
#define PRESSIODEMOAPPS_GHOST_FILLER_DIFFREAC_1D_HPP_

namespace pressiodemoapps{
namespace impldiffusionreaction1d{

template<class state_t, class mesh_t, class ghost_t>
class GhostFillerProblemA1d
{

public:
  GhostFillerProblemA1d() = delete;
  GhostFillerProblemA1d(const int stencilSize,
			 const state_t & stateIn,
			 const mesh_t & meshIn,
			 ghost_t & ghostLeft,
			 ghost_t & ghostRight)
    : m_stencilSize(stencilSize),
      m_state(stateIn),
      m_meshObj(meshIn),
      m_ghostLeft(ghostLeft),
      m_ghostRight(ghostRight)
  {}

  template<class index_t>
  void operator()(index_t smPt, int gRow)
  {

    const auto & graph = m_meshObj.graph();
    const auto cellGID = graph(smPt, 0);
    const auto uIndex  = cellGID*1;

    const auto left0  = graph(smPt, 1);
    const auto right0 = graph(smPt, 2);

    if (left0 == -1){
      m_ghostLeft(gRow, 0) = -m_state(uIndex);
    }

    if (right0 == -1){
      m_ghostRight(gRow, 0) = -m_state(uIndex);
    }
  }

private:
  const int m_stencilSize;
  const state_t & m_state;
  const mesh_t & m_meshObj;
  ghost_t & m_ghostLeft;
  ghost_t & m_ghostRight;
};

}}
#endif
