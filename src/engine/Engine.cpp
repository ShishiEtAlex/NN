#include "Engine.h"

const sf::Time Engine::updateTime = sf::seconds(1.f / 60.f);

Engine::Engine()
: m_window ("NEURAL NETWORK", {860u, 640u})
, m_stateManager(&m_sharedContext)
{
	m_sharedContext.m_window = &m_window;
	m_sharedContext.m_eventManager = m_window.getEventManager();
	
	m_stateManager.switchTo(StateName::World);
}

void Engine::run()
{
	sf::Time elapsed = sf::Time::Zero;
	sf::Clock clock;
	
	while (m_window.isOpen())
	{
		processEvents();
		
		elapsed += clock.restart();
		while (elapsed > updateTime)
		{
			elapsed -= updateTime;
			
			processEvents();
			update(updateTime);
		}
		
		render();
		
		lateUpdate();
	}
}

void Engine::processEvents()
{
	m_window.processEvents();
}

void Engine::update(sf::Time dt)
{
	m_stateManager.update(dt);
	m_window.update();
}

void Engine::render()
{
	m_window.beginDraw();
	m_stateManager.draw();
	m_window.endDraw();
}

void Engine::lateUpdate()
{
	m_stateManager.lateUpdate();
}
