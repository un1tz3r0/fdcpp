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

#ifndef _FDCPP_SOCKET_HPP_
#define _FDCPP_SOCKET_HPP_

#include <sys/socket.h>

#include <string>
#include <cstdint>

#include <fds/base/iofile_descriptor.hpp>

namespace fd {

class socket : public iofile_descriptor {
public:    
    explicit socket(int domain, int type, int protocol = 0);
    socket(const socket &other) = delete;
    socket(socket &&other);
    
    virtual ~socket();
    
    socket &operator=(const socket &other) = delete;
    socket &operator=(socket &&other);
    
    void connect(const struct sockaddr *saddr, socklen_t len) const;
    
    void bind(const struct sockaddr *saddr, socklen_t len) const;
    
    void listen(int backlog = 5) const;
    
    socket accept() const;
    socket accept(struct sockaddr *saddr, socklen_t *len) const;
    
    void shutdown(int mode) const;
    
    size_t recv(char *buffer, size_t size, int flags = 0) const;
    size_t recvmsg(struct msghdr *msg, int flags = 0) const;
    size_t recvfrom(char *buffer, 
                    size_t size,
                    struct sockaddr *saddr,
                    socklen_t *len,
                    int flags = 0) const;
    size_t recvfrom(char *buffer, size_t size, int flags = 0) const;
    
    size_t send(const char *buffer, size_t size, int flags = 0) const;
    size_t sendmsg(const struct msghdr *msg, int flags = 0) const;
    size_t sendto(const char *buffer, 
                  size_t size, 
                  const struct sockaddr *saddr,
                  socklen_t len,
                  int flags = 0) const;
    
    void getsockopt(int level, int name, char *val, socklen_t *len) const;
    void setsockopt(int level, int name, const char *val, socklen_t len) const;
private:
    explicit socket(int fd);
};

}

#endif /* _FDCPP_SOCKET_HPP_ */