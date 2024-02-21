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

		return true;
	}
};
