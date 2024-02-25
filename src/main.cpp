#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/cocos/sprite_nodes/CCSprite.h>
using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* v, bool v2) {
		if (!LevelInfoLayer::init(v, v2)) return false;
		auto LeftSideMenu = this->getChildByID("left-side-menu");
        if (!LeftSideMenu) {
            return false;
        }
		auto DeleteButton = LeftSideMenu->getChildByID("delete-button");
        if (!DeleteButton) {
        } else {
            LeftSideMenu->removeChild(DeleteButton);
            LeftSideMenu->updateLayout();
        }

        // Right side delete-button (for moderators or FakeModerator mod)
        auto RightSideMenu = this->getChildByID("right-side-menu");
        if (!RightSideMenu) {
            return false;
        }
        auto DeleteButton2 = RightSideMenu->getChildByIDRecursive("delete-button"); // 2nd delete-button, moderator button
        auto value = Mod::get()->getSettingValue<bool>("moderator-button-disabled");
        if (value == true) {
            if (!DeleteButton2) {
            } else {
                auto Sprite = DeleteButton2->getChildByTag(1)
                auto Texture = Sprite->getTexture()
                if (Texture = "GJ_deleteServerBtn_001.png"); {
                    RightSideMenu->removeChild(DeleteButton2);
                    RightSideMenu->updateLayout();
                }
            }
        }
        return true;
	}
};
