#include "DrawRequest.h"

DrawRequest::DrawRequest(glm::mat4x4 _model, Texture* _texture, int _textureCount, int _currTexture)
	: model(_model), texture(_texture), textureCount(_textureCount), currTexture(_currTexture)
{
}
