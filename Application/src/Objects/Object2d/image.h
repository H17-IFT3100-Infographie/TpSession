#ifndef IMAGE_H
#define IMAGE_H

#include "baseObject.h"
#include "Primitive\rect.h"
#include <ofImage.h>

class Image : public BaseObject
{
public:
	Image(const std::string filepath);
	Image(float x, float y, float z, const std::string filepath);
	~Image();
	
	void Load();
	virtual void Setup();

	virtual void Update();
	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);
	virtual void SetAlpha(int a);

	bool IsHovered(float x, float y);

protected:
	ofImage* image;
	Rect* boundingBox;
private:
	std::string filepath;
	std::vector<std::vector<ofColor> > originalColor;
	ofVec2f originalDimension;
};

#endif // IMAGE_H