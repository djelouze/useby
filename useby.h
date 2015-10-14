#ifndef USEBY_H
#define USEBY_H
#include <string>

typedef std::string (*AuthentificateFunc)();
typedef bool (*AuthorizeFunc)();

extern "C"{
std::string authentificate();
bool authorize();
}

#endif // USEBY_H
