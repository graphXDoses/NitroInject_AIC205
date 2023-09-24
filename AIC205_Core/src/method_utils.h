#if !defined(METHOD_UTILS_H)
#define METHOD_UTILS_H

#define local_persist static
#define NAME_MANGLE(name, id)  _##name##_##id

#define MAX_DATASTRUCT_OBJECTS 6

#define METHOD_DECL(retVal, name, ...) \
typedef retVal (*name##_SIGN)(__VA_ARGS__); \
extern  retVal NAME_MANGLE(name, 01)(__VA_ARGS__); \
extern  retVal NAME_MANGLE(name, 02)(__VA_ARGS__); \
extern  retVal NAME_MANGLE(name, 03)(__VA_ARGS__); \
extern  retVal NAME_MANGLE(name, 04)(__VA_ARGS__); \
extern  retVal NAME_MANGLE(name, 05)(__VA_ARGS__); \
extern  retVal NAME_MANGLE(name, 06)(__VA_ARGS__);


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

#endif
