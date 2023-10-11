#if !defined(METHOD_UTILS_H)
#define METHOD_UTILS_H

#define MAX_DATASTRUCT_OBJECTS 6

#define METHOD_DECL(retVal, name, ...) \
typedef retVal (*name##_SIGN)(__VA_ARGS__); \
extern  retVal _##name##_##01(__VA_ARGS__); \
extern  retVal _##name##_##02(__VA_ARGS__); \
extern  retVal _##name##_##03(__VA_ARGS__); \
extern  retVal _##name##_##04(__VA_ARGS__); \
extern  retVal _##name##_##05(__VA_ARGS__); \
extern  retVal _##name##_##06(__VA_ARGS__);

#define METHOD_INIT(type) \
	local_persist type* obj = NULL; \
	local_persist int initPhase = 1; \
	if (initPhase == 1) \
	{ \
		obj = targ; \
		initPhase = 0; \
		return; \
	}

#define METHOD_INIT_ZERO(type) \
	local_persist type* obj = NULL; \
	local_persist int initPhase = 1; \
	if (initPhase == 1) \
	{ \
		obj = targ; \
		initPhase = 0; \
		return(0); \
}

#define INIT_CTOR(clsType) \
	local_persist _##clsType instance[MAX_DATASTRUCT_OBJECTS] = { 0 }; \
	local_persist int n = NilValue; \
	n++

#define _LOAD_FUNCPOOL(clsType, name) \
	name##_##clsType##_SIGN name##_##clsType##_##FuncPool[] = \
	{ \
		_##name##_##clsType##_01, \
		_##name##_##clsType##_02, \
		_##name##_##clsType##_03, \
		_##name##_##clsType##_04, \
		_##name##_##clsType##_05, \
		_##name##_##clsType##_06, \
	}

#define _BIND_METHOD_TO_OBJECT(clsType, name, ...) \
	name##_##clsType##_##FuncPool[n](__VA_ARGS__); \
	THIS.Public.name = name##_##clsType##_##FuncPool[n];

#define THIS (instance[n])

#endif
