#ifndef CURSOR_H
#define CURSOR_H

#include "../Image.h"

class Cursor : public Image
{
public:
	Cursor(const std::string filepath);
	~Cursor();

	virtual void Setup();

	virtual void Update();
	virtual void Draw();

	void Show() { show = true; }
	void Hide() { show = false; }
protected:

private:
	bool show;
};


#endif // CURSOR_H