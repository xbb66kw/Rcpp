// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// t.h: Rcpp R/C++ interface class library -- t distribution
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp__stats__t_h
#define Rcpp__stats__t_h

namespace Rcpp {

namespace stats {

namespace impl {

	template <bool NA, typename T>
	class DT : public Rcpp::VectorBase< REALSXP, NA, DT<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DT( const VEC_TYPE& vec_, double df_, bool log_ = false ) : 
			vec(vec_), df(df_), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dt( vec[i], df, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df;
		int log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DT<NA,T> dt( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df, bool log = false ) {
	return impl::DT<NA,T>( x, df, log ); 
}
	
}
}

#endif