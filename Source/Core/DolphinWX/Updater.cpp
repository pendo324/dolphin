#include "Common/MsgHandler.h"
#include <SFML/Network/Http.hpp>
#include "Updater.h"

void CUpdater::CheckUpdate()
{
	CUpdater::Update();
}

void CUpdater::Update()
{
	SuccessAlertT("Dolphin will update upon application close");
}