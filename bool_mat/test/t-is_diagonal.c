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

    Copyright (C) 2016 Arb authors

******************************************************************************/

#include "bool_mat.h"

int main()
{
    slong iter;
    flint_rand_t state;

    flint_printf("is_diagonal....");
    fflush(stdout);

    flint_randinit(state);

    /* all zero matrices are diagonal */
    {
        slong m, n;
        for (m = 0; m < 10; m++)
        {
            for (n = 0; n < 10; n++)
            {
                bool_mat_t zero;
                bool_mat_init(zero, m, n);
                bool_mat_zero(zero);
                if (!bool_mat_is_diagonal(zero))
                {
                    flint_printf("FAIL (zero matrix)\n");
                    abort();
                }
                bool_mat_clear(zero);
            }
        }
    }

    /* all identity matrices are diagonal */
    {
        slong n;
        for (n = 0; n < 10; n++)
        {
            bool_mat_t one;
            bool_mat_init(one, n, n);
            bool_mat_one(one);
            if (!bool_mat_is_diagonal(one))
            {
                flint_printf("FAIL (identity matrix)\n");
                abort();
            }
            bool_mat_clear(one);
        }
    }

    for (iter = 0; iter < 10000; iter++)
    {
        slong m, n;
        bool_mat_t A;

        m = n_randint(state, 10) + 1;
        n = n_randint(state, 10) + 1;

        bool_mat_init(A, m, n);

        /* random diagonal */
        {
            bool_mat_randtest_diagonal(A, state);
            if (!bool_mat_is_diagonal(A))
            {
                flint_printf("FAIL (random diagonal)\n");
                flint_printf("A:\n"); bool_mat_print(A); flint_printf("\n");
                abort();
            }
        }

        /* random non-diagonal */
        {
            slong i, j;
            bool_mat_randtest(A, state);
            i = n_randint(state, m);
            j = n_randint(state, n);
            if (i != j)
            {
                *bool_mat_entry(A, i, j) = 1;
                if (bool_mat_is_diagonal(A))
                {
                    flint_printf("FAIL (random non-diagonal)\n");
                    flint_printf("A:\n"); bool_mat_print(A); flint_printf("\n");
                    abort();
                }
            }
        }

        bool_mat_clear(A);
    }

    flint_randclear(state);
    flint_cleanup();
    flint_printf("PASS\n");
    return EXIT_SUCCESS;
}
