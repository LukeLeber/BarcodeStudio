#ifndef NON_COPYABLE_HPP
#define NON_COPYABLE_HPP

class noncopyable
{
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};

#endif