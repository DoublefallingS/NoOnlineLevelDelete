#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* v, bool v2) {
		if (!LevelInfoLayer::init(v, v2)) return false;

		auto DeleteMenu = this->getChildByID("left-side-menu");
        if (!DeleteMenu) {
            return false;
        }
		auto DeleteButton = DeleteMenu->getChildByID("delete-button");
        if (!DeleteButton) {
        } else {
            DeleteMenu->removeChild(DeleteButton);
            DeleteMenu->updateLayout();
        }

        // Right side delete-button (for moderators or FakeModerator mod)
        auto value = Mod::get()->getSettingValue<bool>("moderator-button-disabled");
        if (value == true) {
            auto DeleteMenu2 = this->getChildByID("right-side-menu");
            if (!DeleteMenu2) {
                return false;
            }
		    auto DeleteButton2 = DeleteMenu2->getChildByID("delete-button");
            if (!DeleteButton2) {
            } else {
                DeleteMenu2->removeChild(DeleteButton2);
                DeleteMenu2->updateLayout();
            }
        }
		return true;
	}
};
