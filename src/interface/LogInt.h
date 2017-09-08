#ifndef GAMEEE_LOG_H
#define GAMEEE_LOG_H

#define DebugLog(msg) (printf("File:%s, Line:%d, Function:%s, %s\n", __FILE__, __LINE__ , __FUNCTION__, msg))

#define FDebugLog(format, ...) (printf(format, __VA_ARGS__))

#endif
