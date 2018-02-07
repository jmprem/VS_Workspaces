#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>
#include <string>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	void Update();
	bool IsClosed();

private:
	SDL_Window * m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

#endif //DISPLAY_H_
