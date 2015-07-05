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

#ifndef _FDCPP_MEMFD_HPP_
#define _FDCPP_MEMFD_HPP_

#include <sys/memfd.h>

#include <string>

#include <fds/base/iofile_descriptor.hpp>

namespace fd {

class memfd : public iofile_descriptor {
    explicit memfd(const char *name, int flags = 0);
    explicit memfd(const std::string &name, int flags = 0);
    memfd(const memfd &other) = delete;
    memfd(memfd &&other);
    
    virtual ~memfd() = default;
    
    memfd &operator=(const memfd &other) = delete;
    memfd &operator=(memfd &&other);
    
    void ftruncate(size_t size = 0) const;
};

}

#endif /* _FDCPP_MEMFD_HPP_ */