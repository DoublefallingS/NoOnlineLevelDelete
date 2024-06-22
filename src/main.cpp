#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/cocos/sprite_nodes/CCSprite.h>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
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
        auto DeleteButton2 = RightSideMenu->getChildByID("delete-button");
        auto value = Mod::get()->getSettingValue<bool>("moderator-button-disabled");
        if (value == true) {
            DeleteButton2->setID("normal-delete-button"); //Both delete buttons have the same name
            RightSideMenu->removeChildByID("delete-button"); //Delete the correct button
            DeleteButton2->setID("delete-button"); //Rename the top right delete button back
            RightSideMenu->updateLayout();
        }
        return true;
	}
};
