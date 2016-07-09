#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <memory>
#include <QString>

struct Constants{
    static const QString version;
};

template<class T> using Ptr = std::shared_ptr<T>;

template<class T> using WeakPtr = std::weak_ptr<T>;

#endif // GLOBAL_H
