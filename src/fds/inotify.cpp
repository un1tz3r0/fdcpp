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

#include <unistd.h>

#include <utility>

#include <fds/inotify.hpp>
#include <util/throw.hpp>


static const char *tag = "inotify";

namespace fd {

inotify::inotify(int flags)
    : idescriptor(inotify_init1(flags))
{
    if (_fd < 0)
        throw_system_error(tag, "inotify()");
}

inotify::inotify(descriptor &&other)
    : idescriptor(std::move(other))
{
    if (_fd < 0)
        throw_system_error(tag, "inotify()", EBADF);
}

inotify::inotify(const inotify &other)
    : idescriptor(::dup(other._fd))
{
    if (_fd < 0)
        throw_system_error(tag, "dup()");
}

const inotify &inotify::operator=(const inotify &other) const
{
    int err = ::dup2(other._fd, _fd);
    if (err < 0)
        throw_system_error(tag, "dup2()");
    
    return *this;
}

inotify inotify::dup() const
{
    return inotify(*this);
}

void inotify::dup2(const inotify &other) const
{
    *this = other;
}

int inotify::add_watch(const char *path, uint32_t mask) const
{
    auto wd = inotify_add_watch(_fd, path, mask);
    if (wd < 0)
        throw_system_error(tag, "add_watch()");
    
    return wd;
}

int inotify::add_watch(const std::string &path, uint32_t mask) const
{
    return add_watch(path.c_str(), mask);
}

void inotify::rm_watch(int wd) const
{
    auto err = inotify_rm_watch(_fd, wd);
    if (err < 0)
        throw_system_error(tag, "rm_watch()");
}

}