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
	
	virtual void Setup();

	virtual void Update();
	virtual void Draw();

	virtual void SetColor(int r, int g, int b);
	virtual void SetAlpha(int a);

	bool IsHovered(float x, float y);

private:
	Image();

	ofImage* image;
	
	std::string filepath;

	std::vector<std::vector<ofColor> > originalColor;
};

#endif // IMAGE_H