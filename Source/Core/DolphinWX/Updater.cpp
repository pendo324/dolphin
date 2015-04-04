#include <SFML/Network/Http.hpp>

#include "Common/MsgHandler.h"
#include "Updater.h"
#include "Common\Common.h"
#include "DolphinWX/WxUtils.h"


void CUpdater::CheckUpdate()
{
	int m_newBranch = 0;
	int m_newGit = 0;
	std::string versionAndRevision;
	std::string newVersion;

	memcpy(&versionAndRevision, scm_desc_str, strlen(scm_desc_str) - 6);

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
		WxUtils::ShowErrorDialog("Failed to download.");
	}


	//get the version from the json file and assign it to newVersion format: version-revision

	if (strcmp(versionAndRevision.c_str(), newVersion.c_str()) != 0) {
		if (AskYesNo("Current version: %s\nNew version: %s\n", versionAndRevision, newVersion) == 1) 
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