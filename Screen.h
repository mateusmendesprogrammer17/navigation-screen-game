#pragma once

class Screen {


public:
	Screen(int width, int height);
	virtual ~Screen() = default;
	void setWidth(int width);
	void  setHeight(int height);
	int getWidth() const;
	int getHeight() const;
	virtual void setContent() = 0;
protected: 
int width;
int height;

};