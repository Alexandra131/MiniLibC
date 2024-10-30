/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDARG_H__
#define __STDARG_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
//macrocomanda care se foloseste pentru a initializa o variabila de tip va_list
#define va_start(v, l)	__builtin_va_start(v, l)
// pentru a finaliza parcurgearea variabileler de o lungime variabila
#define va_end(v)	__builtin_va_end(v)
//acceseza elemente de lungime variabila
#define va_arg(v, l)	__builtin_va_arg(v, l)
//creaza o copie a nunui element de tip va_list
#define va_copy(d, s)	__builtin_va_copy(d, s)

typedef __builtin_va_list va_list;

#ifdef __cplusplus
}
#endif

#endif
