#pragma once

#include "src/Renderer/RenderInfo.h"
#include "Vendor/glm/glm/glm.hpp"


class Entity
{
    RenderInfo info;
    glm::vec3 position, rotation, scale;
public:
    Entity();
    /*virtual*/ void update(glm::vec3 posIncrement, glm::vec3 rotIncrement, glm::vec3 scaleIncrement);
    inline void setRenderInfo(const RenderInfo& _info) {info = _info;}
    inline const RenderInfo& getRenderInfo() const {return info;}
    inline glm::vec3 getPosition() const {return position;}
    inline glm::vec3 getRotation() const {return rotation;}
    inline glm::vec3 getScale() const {return scale;}
};
