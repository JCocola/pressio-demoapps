/*
//@HEADER
// ************************************************************************
//
// ode_advance_n_steps.hpp
//                     		  Pressio
//                             Copyright 2019
//    National Technology & Engineering Solutions of Sandia, LLC (NTESS)
//
// Under the terms of Contract DE-NA0003525 with NTESS, the
// U.S. Government retains certain rights in this software.
//
// Pressio is licensed under BSD-3-Clause terms of use:
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Francesco Rizzi (fnrizzi@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef ODE_STATIC_ASSERT_HELPERS_HPP_
#define ODE_STATIC_ASSERT_HELPERS_HPP_

namespace pressio{ namespace ode{ namespace impl{

template<class StepperType, class StateType, class TimeType, class ...Args>
constexpr void
static_assert_is_steppable_with(StepperType &  /*unused*/,
				StateType &    /*unused*/,
				const TimeType /*unused*/,
				Args && ...    /*unused*/)
{
  static_assert
    (::pressio::ode::steppable_with<void, StepperType, StateType, TimeType, Args...>::value,
     "The steppable object does not satisfy the steppable concept.");
}

template<class StepSizeSetterType, class TimeType>
constexpr void
static_assert_admissible_time_step_setter(StepSizeSetterType && /*unused*/,
					  const TimeType        /*unused*/)
{
  static_assert
    (::pressio::ode::time_step_size_manager<StepSizeSetterType, TimeType>::value,
     "The step size setter does not satisfy the required concept.");
}

template<class ObserverType, class StateType, class TimeType>
constexpr void
static_assert_admissible_observer(ObserverType && /*unused*/,
				  StateType &     /*unused*/,
				  const TimeType  /*unused*/)
{
  static_assert
    (::pressio::ode::observer<ObserverType, TimeType, StateType>::value,
     "The observer does not satisfy the required concept");
}

}}} //end namespace pressio::ode::impl
#endif
