#ifndef LEMNISCATE_PROCEDUAL_IMAGE_H
#define LEMNISCATE_PROCEDUAL_IMAGE_H

#include "image.h"

class LemniscateProceduralImage : public Image
{
public:
	LemniscateProceduralImage();
	LemniscateProceduralImage(float x, float y, float z);
	~LemniscateProceduralImage();
	
	virtual void Setup();

private:

};

#endif // LEMNISCATE_PROCEDUAL_IMAGE_H