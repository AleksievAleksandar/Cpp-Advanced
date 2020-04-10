#ifndef CONT_INTERFACE_H_
#define CONT_INTERFACE_H_

#include <cstddef>

class ContainerInterface
{
public:
	ContainerInterface() = default;
	virtual ~ContainerInterface() = default;
	virtual size_t getOccupiedMemory() const = 0;
};

#endif /* CONT_INTERFACE_H_ */