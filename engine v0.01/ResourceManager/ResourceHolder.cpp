#include "ResourceHolder.h"

ResourceHolder::ResourceHolder()
{
}

ResourceHolder& ResourceHolder::get()
{
	static ResourceHolder holder;
	return holder;
}
