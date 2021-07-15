#pragma once

#include <unordered_map>
#include <string>

template<typename Resource>
class ResourceManager
{
public:
	ResourceManager() {};
	void load(const std::string& name)
	{
		Resource r;
		r.createFromFile(folder + name);
		m_resources.insert(std::make_pair(name, r));
	}

	Resource& get(const std::string& name)
	{
		return m_resources.at(name);
	}
	void setFolder(const std::string& folder_) { folder = folder_; };

private:
	bool exists(const std::string& name) const
	{
		return (m_resources.find(name) != m_resources.end());
	}
	std::unordered_map<std::string, Resource> m_resources;
	std::string folder;
};


