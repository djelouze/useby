#ifndef USEBY_H
#define USEBY_H
#include <string>

#ifdef WIN32
#define WIN32_EXPORT __declspec(dllexport)
#else
#define WIN32_EXPORT
#endif

typedef std::string (*AuthentificateFunc)();
typedef bool (*AuthorizeFunc)();

extern "C"{
std::string WIN32_EXPORT authentificate();
bool WIN32_EXPORT authorize();
}

#endif // USEBY_H
