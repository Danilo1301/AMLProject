#include "pch.h"

MYMODCFG(net.danilo1301.AMLProject, AML Project, 1.0.0, Danilo1301)

//MYMOD(net.rusjj.mymod.guid, AML Mod Template Without Config, 1.0, RusJJ)

//NEEDGAME(net.rusjj.mygame)

//BEGIN_DEPLIST()
//    ADD_DEPENDENCY_VER(net.rusjj.aml, 1.0)
//END_DEPLIST()

uintptr_t pGameLibrary = 0;
ConfigEntry* pCfgMyBestEntry;

extern "C" void OnModLoad()
{
    logger->SetTag("AML Project");
    
    pCfgMyBestEntry = cfg->Bind("mySetting", "DefaultValue is 0?", "MyUniqueSection");
    pCfgMyBestEntry->SetString("DefaultValue is unchanged");
    pCfgMyBestEntry->SetInt(1);
    pCfgMyBestEntry->Reset();
    delete pCfgMyBestEntry; // Clean-up memory
    
    bool bEnabled = cfg->Bind("Enable", true)->GetBool();
    delete Config::pLastEntry; // Clean-up of the latest ConfigEntry*
    
    cfg->Save(); // Will only save if something was changed
}
