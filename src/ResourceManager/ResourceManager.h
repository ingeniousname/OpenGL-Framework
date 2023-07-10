#pragma once

#include <unordered_map>
#include <string>
#include <memory>

template<typename Resource>
class UniqueResourceManager
{
public:
	UniqueResourceManager() {};
	void load(const std::string& name)
	{
		m_resources.insert(std::make_pair(name, std::make_unique<Resource>()));
		m_resources[name].get()->createFromFile(folder + name);
	}

	Resource& get(const std::string& name)
	{
		return *m_resources.at(name);
	}
	void setFolder(const std::string& folder_) { folder = folder_; };

private:
	bool exists(const std::string& name) const
	{
		return (m_resources.find(name) != m_resources.end());
	}
	std::unordered_map<std::string, std::unique_ptr<Resource>> m_resources;
	std::string folder;
};

template<typename Resource>
class SharedResourceManager
{
public:
    SharedResourceManager() {};
    void load(const std::string& name)
    {
        m_resources.insert(std::make_pair(name, std::make_shared<Resource>()));
        m_resources[name].get()->createFromFile(folder + name);
    }

    std::shared_ptr<Resource>& getPointer(const std::string& name)
    {
        return m_resources.at(name);
    }
    void setFolder(const std::string& folder_) { folder = folder_; };

private:
    bool exists(const std::string& name) const
    {
        return (m_resources.find(name) != m_resources.end());
    }
    std::unordered_map<std::string, std::shared_ptr<Resource>> m_resources;
    std::string folder;
};


