#ifndef TOOLS_HPP_INCLUDED
#define TOOLS_HPP_INCLUDED

// Copyright 2011-2012 Daniel Kr&uuml;gler.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <type_traits>

namespace xstd {
namespace details {
namespace tool_detect_traits {
// Declare but do not define
template<class> struct is_trivially_default_constructible;
template<class> struct has_trivial_default_constructor;
template<class> struct is_trivially_copy_constructible;
template<class> struct has_trivial_copy_constructor;
template<class> struct is_trivially_copy_assignable;
template<class> struct has_trivial_copy_assign;
template<class> struct is_trivially_destructible;
template<class> struct has_trivial_destructor;
}
}
}


namespace xstd {

template<class...>
struct and_;

template<>
struct and_<> : std::true_type
{
};

template<class P1, class... Pn>
struct and_<P1, Pn...> : std::conditional<P1::value,
  and_<Pn...>, std::false_type>::type
{
};

template<class P>
struct not_ : std::integral_constant<bool, !P::value>
{
};

}

#endif // TOOLS_HPP_INCLUDED
