/*
//@HEADER
// ************************************************************************
//
// asdiagonalmatrix_traits.hpp
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

#ifndef EXPRESSIONS_IMPL_ASDIAGONALMATRIX_TRAITS_HPP_
#define EXPRESSIONS_IMPL_ASDIAGONALMATRIX_TRAITS_HPP_

namespace pressio{ namespace expressions{  namespace impl{

#ifdef PRESSIO_ENABLE_TPL_EIGEN
template <typename VectorType>
struct AsdiagmatrixTraits<
  AsDiagonalMatrixExpr<VectorType>,
  ::pressio::mpl::enable_if_t<
    ::pressio::is_dynamic_vector_eigen<VectorType>::value
    >
  >
  : public ::pressio::impl::EigenTraits<
      ::pressio::mpl::remove_cvref_t<VectorType>,
      2
    >,
    public ::pressio::impl::StaticAllocTrait,
    public ::pressio::impl::DenseMatrixTrait
{
  using scalar_type = typename ::pressio::Traits<
    ::pressio::mpl::remove_cvref_t<VectorType>
  >::scalar_type;

  // type of the native expression
  using _native_expr_type =
    decltype( std::declval<VectorType>().asDiagonal() );

  using _const_native_expr_type =
    decltype( std::declval<const VectorType>().asDiagonal() );

  using native_expr_type = typename std::conditional<
    std::is_const<VectorType>::value,
    _const_native_expr_type,
    _native_expr_type
    >::type;

  using reference_type = typename std::conditional<
    std::is_const<VectorType>::value, scalar_type, scalar_type &
  >::type;

  using const_reference_type = typename std::conditional<
    std::is_const<VectorType>::value, scalar_type, scalar_type const &
    >::type;
};
#endif

}}}
#endif  // EXPRESSIONS_IMPL_ASDIAGONALMATRIX_TRAITS_HPP_
