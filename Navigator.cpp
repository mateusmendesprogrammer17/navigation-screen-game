#include "Navigator.h"



Navigator::Navigator(std::unique_ptr<Screen> initialScreen) {
	screenStack.push(std::move(initialScreen));
};

void Navigator::pushScreen(std::unique_ptr<Screen> screen) {
	screenStack.push(std::move(screen));
};
void Navigator::popScreen() {
	if (!screenStack.empty()) {
		screenStack.pop();
	}
};
 void Navigator::navigate(NavigationType type, std::unique_ptr<Screen> screen) {
	switch (type) {
	case NavigationType::PUSH:
		pushScreen(std::move(screen));
		break;
	case NavigationType::REPLACE:
		popScreen();
		pushScreen(std::move(screen));
		break;
	case NavigationType::BACK:
		popScreen();
		break;
	case NavigationType::QUIT:
		while (!screenStack.empty()) {
			screenStack.pop();
		}
		break;
	default:
		break;
	}

	

}
 Screen* Navigator::getCurrentScreen() const
 {
	 if (screenStack.empty())
		 return nullptr;

	 return screenStack.top().get();
 }