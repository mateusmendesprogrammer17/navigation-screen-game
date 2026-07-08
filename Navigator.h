#pragma once
#include <stack>
#include "Screen.h"
#include <memory>
class Navigator {


public:

	Navigator(std::unique_ptr<Screen> initialScreen);
	enum class NavigationType {
		PUSH,
		REPLACE,
		BACK,
		QUIT	
	};
	 void pushScreen(std::unique_ptr<Screen> screen);
	 void popScreen();
	 virtual Screen* getCurrentScreen() const;
	 void navigate(NavigationType type, std::unique_ptr<Screen> screen = nullptr);
private:
	std::stack<std::unique_ptr<Screen>> screenStack;

};