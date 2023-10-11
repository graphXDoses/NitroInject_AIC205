#if !defined(ELEMENT_SPECIFICATION_H)
#define ELEMENT_SPECIFICATION_H

#define TOTAL_ELEMENT_ARRAY_BYTES 512

typedef struct
{
	char   Memory[TOTAL_ELEMENT_ARRAY_BYTES];
	size_t per_element_size;
} ElementSpecification;

#endif