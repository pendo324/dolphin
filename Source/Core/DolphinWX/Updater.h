#pragma once

#include <sstream>
#include <SFML/Network/Http.hpp>

class CUpdater
{
public:
	void static CheckUpdate();
private:
	void static Update();
	std::string m_versionAndRevision;
	std::string m_newVersion;
	sf::Http::Request req;
	sf::Http http;
	std::istringstream ss;
};