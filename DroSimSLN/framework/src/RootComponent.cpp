#include <vector>
#include "RootComponent.h"

RootComponent::RootComponent(){}
RootComponent::~RootComponent(){}

void RootComponent::initialize(){}
std::vector<LeafComponent*> RootComponent::getListLeafComponents(){
	return leafComponents;
}
