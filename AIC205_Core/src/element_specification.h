#if !defined(ELEMENT_SPECIFICATION_H)
#define ELEMENT_SPECIFICATION_H

typedef struct
{
	char   Memory[TOTAL_ELEMENT_ARRAY_BYTES];
	size_t per_element_size;
} ElementSpecification;

#endif