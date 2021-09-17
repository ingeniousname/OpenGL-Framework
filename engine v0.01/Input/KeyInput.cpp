#include "KeyInput.h"
#include <algorithm>

std::vector<KeyInput*> KeyInput::_instances;


KeyInput::KeyInput(std::vector<int> keysToListen, std::vector<int> keysToListenRelease)
{
    for (int x : keysToListen)
        keymap.insert(std::make_pair(x, false));

    for (int x : keysToListenRelease)
        releasemap.insert(std::make_pair(x, false));

    KeyInput::_instances.push_back(this);
}

KeyInput::~KeyInput()
{
    _instances.erase(std::remove(_instances.begin(), _instances.end(), this), _instances.end());
}

void KeyInput::setupKeyCallback(GLFWwindow* window)
{
    glfwSetKeyCallback(window, KeyInput::key_callback);
    glfwSetMouseButtonCallback(window, KeyInput::mouse_button_callback);
}

void KeyInput::setKeyDown(int key, bool flag)
{
    auto it = keymap.find(key);
    if (it != keymap.end())
        keymap[key] = flag;
}

bool KeyInput::getKeyDown(int key)
{
    bool result;
    auto it = keymap.find(key);
    if (it != keymap.end())
        result = keymap[key];
    return result;
}

bool KeyInput::getMouseButtonDown(int key)
{
    bool result = getKeyDown(key);
    if (result)
    {
        if (getKeyReleased(key))
        {
            setKeyReleased(key, false);
            return true;
        }
        return false;
    }
    else
    {
        if (!getKeyReleased(key))
            setKeyReleased(key, true);
        return false;
    }
}

void KeyInput::setKeyReleased(int key, bool flag)
{
    auto it = releasemap.find(key);
    if (it != releasemap.end())
        releasemap[key] = flag;
}

bool KeyInput::getKeyReleased(int key)
{
    bool result;
    auto it = releasemap.find(key);
    if (it != releasemap.end())
        result = releasemap[key];
    return result;
}

void KeyInput::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    for (KeyInput* instance : _instances)
        instance->setKeyDown(key, action != GLFW_RELEASE);
}

void KeyInput::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    for (KeyInput* instance : _instances)
            instance->setKeyDown(button, action == GLFW_PRESS);
     
        
    
}
