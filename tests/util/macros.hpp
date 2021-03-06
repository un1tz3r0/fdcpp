/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Steffen Nuessle
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _FDCPP_MACROS_HPP_
#define _FDCPP_MACROS_HPP_

#include <cstdlib>

#include <iostream>

#define SYMBOL(x) #x
#define SYMBOL2(x) SYMBOL(x)

#define __LINE_STR__ SYMBOL2(__LINE__)
#define __FILE_POSITION__ __FILE__ ":" __LINE_STR__

#define ASSERT(x, msg)                                                         \
    do {                                                                       \
        if (!(x)) {                                                            \
            std::cerr << "** ASSERTION FAILURE: " << SYMBOL((x))               \
                      << " failed at " << __FILE_POSITION__ << " - " << msg    \
                      << "\n";                                                 \
            std::abort();                                                      \
        }                                                                      \
    } while(0)

#endif /* _FDCPP_MACROS_HPP_ */