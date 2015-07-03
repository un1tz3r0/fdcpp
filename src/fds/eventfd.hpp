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

#ifndef _FDCPP_EVENTFD_HPP_
#define _FDCPP_EVENTFD_HPP_

#include <cstdint>
#include <sys/eventfd.h>

#include <fds/base/iofile_descriptor.hpp>

namespace fd {

class eventfd : public iofile_descriptor {
public:
    
    explicit eventfd(unsigned int initval = 0, int flags = 0);
    eventfd(const eventfd &other) = delete;
    eventfd(eventfd &&other);
    
    virtual ~eventfd();
    
    eventfd &operator=(const eventfd &other) = delete;
    eventfd &operator=(eventfd &&other);
    
    uint64_t read() const;
    void write(uint64_t val) const;
};

}

#endif /* _FDCPP_EVENTFD_HPP_ */