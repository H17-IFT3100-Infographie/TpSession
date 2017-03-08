#ifndef IMAGE_H
#define IMAGE_H

#include "baseObject.h"
#include <ofImage.h>

class Image : public BaseObject
{
public:
	Image(const std::string filepath);
	Image(float x, float y, float z, const std::string filepath);
	~Image();
	
	virtual void Draw();

	bool IsHovered(float x, float y);

private:
	Image();

	ofImage* image;

	std::string filepath;
};

#endif // IMAGE_H