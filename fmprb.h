/*=============================================================================

    This file is part of ARB.

    ARB is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    ARB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ARB; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2012 Fredrik Johansson

******************************************************************************/

#ifndef FMPRB_H
#define FMPRB_H

#include "fmpr.h"

typedef struct
{
    fmpr_struct mid;
    fmpr_struct rad;
}
fmprb_struct;

typedef fmprb_struct fmprb_t[1];

#define fmprb_midref(x) (&(x)->mid)
#define fmprb_radref(x) (&(x)->rad)


#define FMPRB_RAD_PREC 30
#define FMPRB_MIN_ADJUSTED_PREC 

static __inline__ void
fmprb_init(fmprb_t x)
{
    fmpr_init(fmprb_midref(x));
    fmpr_init(fmprb_radref(x));
}

static __inline__ void
fmprb_clear(fmprb_t x)
{
    fmpr_clear(fmprb_midref(x));
    fmpr_clear(fmprb_radref(x));
}

static __inline__ int
fmprb_is_exact(const fmprb_t x)
{
    return fmpr_is_zero(fmprb_radref(x));
}

static __inline__ void
fmprb_set(fmprb_t x, const fmprb_t y)
{
    fmpr_set(fmprb_midref(x), fmprb_midref(y));
    fmpr_set(fmprb_radref(x), fmprb_radref(y));
}

static __inline__ void
fmprb_neg(fmprb_t x, const fmprb_t y)
{
    fmpr_neg(fmprb_midref(x), fmprb_midref(y));
    fmpr_set(fmprb_radref(x), fmprb_radref(y));
}

static __inline__ void
fmprb_abs(fmprb_t x, const fmprb_t y)
{
    fmpr_abs(fmprb_midref(x), fmprb_midref(y));
    fmpr_set(fmprb_radref(x), fmprb_radref(y));
}


static __inline__ void
fmprb_set_si(fmprb_t x, long y)
{
    fmpr_set_si(fmprb_midref(x), y);
    fmpr_zero(fmprb_radref(x));
}

static __inline__ void
fmprb_set_ui(fmprb_t x, ulong y)
{
    fmpr_set_ui(fmprb_midref(x), y);
    fmpr_zero(fmprb_radref(x));
}

static __inline__ void
fmprb_set_fmpz(fmprb_t x, const fmpz_t y)
{
    fmpr_set_fmpz(fmprb_midref(x), y);
    fmpr_zero(fmprb_radref(x));
}

static __inline__ void
fmprb_adjust(fmprb_t x)
{
    if (!fmprb_is_exact(x))
    {
        /* reduce precision here */
    }
}

void fmprb_add(fmprb_t z, const fmprb_t x, const fmprb_t y, long prec);
void fmprb_add_ui(fmprb_t z, const fmprb_t x, ulong y, long prec);
void fmprb_add_si(fmprb_t z, const fmprb_t x, long y, long prec);
void fmprb_add_fmpz(fmprb_t z, const fmprb_t x, const fmpz_t y, long prec);

void fmprb_addmul(fmprb_t z, const fmprb_t x, const fmprb_t y, long prec);
void fmprb_addmul_ui(fmprb_t z, const fmprb_t x, ulong y, long prec);
void fmprb_addmul_si(fmprb_t z, const fmprb_t x, long y, long prec);
void fmprb_addmul_fmpz(fmprb_t z, const fmprb_t x, const fmpz_t y, long prec);

void fmprb_div(fmprb_t z, const fmprb_t x, const fmprb_t y, long prec);
void fmprb_div_ui(fmprb_t z, const fmprb_t x, ulong y, long prec);
void fmprb_div_si(fmprb_t z, const fmprb_t x, long y, long prec);
void fmprb_div_fmpz(fmprb_t z, const fmprb_t x, const fmpz_t y, long prec);

void fmprb_mul(fmprb_t z, const fmprb_t x, const fmprb_t y, long prec);
void fmprb_mul_ui(fmprb_t z, const fmprb_t x, ulong y, long prec);
void fmprb_mul_si(fmprb_t z, const fmprb_t x, long y, long prec);
void fmprb_mul_fmpz(fmprb_t z, const fmprb_t x, const fmpz_t y, long prec);

void fmprb_sqrt(fmprb_t z, const fmprb_t x, long prec);
void fmprb_sqrt_ui(fmprb_t z, ulong x, long prec);
void fmprb_sqrt_fmpz(fmprb_t z, const fmpz_t x, long prec);

void fmprb_sub(fmprb_t z, const fmprb_t x, const fmprb_t y, long prec);
void fmprb_sub_ui(fmprb_t z, const fmprb_t x, ulong y, long prec);
void fmprb_sub_si(fmprb_t z, const fmprb_t x, long y, long prec);
void fmprb_sub_fmpz(fmprb_t z, const fmprb_t x, const fmpz_t y, long prec);

void fmprb_submul(fmprb_t z, const fmprb_t x, const fmprb_t y, long prec);
void fmprb_submul_ui(fmprb_t z, const fmprb_t x, ulong y, long prec);
void fmprb_submul_si(fmprb_t z, const fmprb_t x, long y, long prec);
void fmprb_submul_fmpz(fmprb_t z, const fmprb_t x, const fmpz_t y, long prec);

void fmprb_const_pi_chudnovsky(fmprb_t x, long prec);

static __inline__ void
fmprb_printd(const fmprb_t x, long digits)
{
    fmpr_printd(fmprb_midref(x), digits);
    printf(" +/- ");
    fmpr_printd(fmprb_radref(x), 5);
}

#endif
