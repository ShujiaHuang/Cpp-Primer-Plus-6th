// new standard header for Microsoft
#include <iostream>
using namespace std;
#pragma once
#ifndef _NEWER_
#define _NEWER_
#ifndef RC_INVOKED
#include <exception>

 #pragma pack(push,_CRT_PACKING)
 #pragma warning(push,3)
// #pragma push_macro("new")

 // #undef new


#if !defined(__CRTDECL)
#if defined(_M_CEE_PURE)
#define __CRTDECL
#else
#define __CRTDECL   __cdecl
#endif
#endif

_STD_BEGIN

		// SUPPORT TYPES
 #if !defined(_INC_NEW) || !defined(_MSC_EXTENSIONS)
// handler for operator new failures
#ifdef _M_CEE_PURE
typedef void (__clrcall * new_handler) ();
#else
typedef void (__cdecl * new_handler) ();
#endif
 #endif /* !defined(_INC_NEW) || !defined(_MSC_EXTENSIONS) */

 #ifndef __NOTHROW_T_DEFINED
struct nothrow_t
	{	// placement new tag type to suppress exceptions
	};

extern const nothrow_t nothrow;	// constant for placement new tag
 #endif /* __NOTHROW_T_DEFINED */

		// FUNCTION AND OBJECT DECLARATIONS
_CRTIMP2 new_handler __cdecl set_new_handler(_In_opt_ new_handler)
	_THROW0();	// establish alternate new handler
_STD_END

		// new AND delete DECLARATIONS (NB: NOT IN std)
void __CRTDECL operator delete(void *) _THROW0();
#pragma warning (suppress: 4985)
_Ret_bytecap_(_Size) void *__CRTDECL operator new(size_t _Size) _THROW1(_STD bad_alloc);

 #ifndef __PLACEMENT_NEW_INLINE
  #define __PLACEMENT_NEW_INLINE
inline void *__CRTDECL operator new(size_t, void *_Where) _THROW0()
	{	// construct array with placement at _Where
	cout << "New!\n";
	return (_Where);
	}

inline void __CRTDECL operator delete(void *, void *) _THROW0()
	{	// delete if placement new fails
		cout << "Delete!\n";
	}
 #endif /* __PLACEMENT_NEW_INLINE */

 #ifndef __PLACEMENT_VEC_NEW_INLINE
  #define __PLACEMENT_VEC_NEW_INLINE
inline void *__CRTDECL operator new[](size_t, void *_Where) _THROW0()
	{	// construct array with placement at _Where
	cout << "New!\n";
	return (_Where);
	}

inline void __CRTDECL operator delete[](void *, void *) _THROW0()
	{	// delete if placement array new fails
		cout << "Delete!\n";
	}
 #endif /* __PLACEMENT_VEC_NEW_INLINE */

void __CRTDECL operator delete[](void *) _THROW0();	// delete allocated array

_Ret_bytecap_(_Size) void *__CRTDECL operator new[](size_t _Size)
	_THROW1(_STD bad_alloc);	// allocate array or throw exception

 #ifndef __NOTHROW_T_DEFINED
  #define __NOTHROW_T_DEFINED
_Ret_opt_bytecap_(_Size) void *__CRTDECL operator new(size_t _Size, const _STD nothrow_t&)
	_THROW0();

_Ret_opt_bytecap_(_Size) void *__CRTDECL operator new[](size_t _Size, const _STD nothrow_t&)
	_THROW0();	// allocate array or return null pointer

void __CRTDECL operator delete(void *, const _STD nothrow_t&)
	_THROW0();	// delete if nothrow new fails -- REPLACEABLE

void __CRTDECL operator delete[](void *, const _STD nothrow_t&)
	_THROW0();	// delete if nothrow array new fails -- REPLACEABLE
 #endif /* __NOTHROW_T_DEFINED */


 #if !defined(_INC_NEW) || !defined(_MSC_EXTENSIONS)
using _STD new_handler;
 #endif /* !defined(_INC_NEW) || !defined(_MSC_EXTENSIONS) */

 #pragma pop_macro("new")
 #pragma warning(pop)
 #pragma pack(pop)

#endif /* RC_INVOKED */
#endif /* _NEWER_ */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V5.03:0009 */
