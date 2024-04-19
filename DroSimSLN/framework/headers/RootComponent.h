#ifndef ROOTCOMPONENT_H_
#define ROOTCOMPONENT_H_

#include <vector>
#include "LeafComponent.h"

class RootComponent {
	
protected :
	std::vector<LeafComponent*> leafComponents;
	
public:
	RootComponent();
	virtual ~RootComponent() = 0;
	std::vector<LeafComponent*> getListLeafComponents();
	
	virtual void initialize();
};
#endif /* ROOTCOMPONENT_H_ */
