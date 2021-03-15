#ifndef ENGINE_H
#define ENGINE_H

#include "Window.h"
#include "StateManager.h"

class Engine : sf::NonCopyable
{
	public:
		
		Engine();
		
		void run();
		
	private:
		
		void processEvents();
		void update(sf::Time);
		void render();
		
		void lateUpdate();
		
	private:
		
		Window m_window;
		StateManager m_stateManager;
		
		SharedContext m_sharedContext;
		
		static const sf::Time updateTime;
};

#endif // ENGINE_H
