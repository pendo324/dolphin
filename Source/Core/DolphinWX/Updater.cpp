#include <sstream>
#include <SFML/Network/Http.hpp>

#include "Common/MsgHandler.h"
#include "Updater.h"
#include "Common\Common.h"
#include "DolphinWX/WxUtils.h"


void CUpdater::CheckUpdate()
{
	std::string m_versionAndRevision;
	std::string m_newVersion;

	//net shit
	sf::Http::Request req;
	req.setUri("/json/builders/release-win-x64/builds/-1/");

	sf::Http http;
	http.setHost("buildbot.dolphin-emu.org");

	const sf::Http::Response resp = http.sendRequest(req, sf::seconds(5));

	if (sf::Http::Response::Ok == resp.getStatus())
	{
		//parse through the response body, gl m8
		std::istringstream ss(resp.getBody());
	}
	else
	{
		//Commented out because its annoy
		//WxUtils::ShowErrorDialog("Failed to check latest version.");
	}


	//get the version from the json file and assign it to newVersion format: version-revision

	if (strcmp(m_versionAndRevision.c_str(), m_newVersion.c_str()) != 0) {
		if (AskYesNo("Current version: %s\nNew version: %s\n", scm_desc_str, m_newVersion) == 1)
		{
			//if they press yes, update
			CUpdater::Update();
		}
	}


}

void CUpdater::Update()
{
	SuccessAlertT("Doing updater things...");
}