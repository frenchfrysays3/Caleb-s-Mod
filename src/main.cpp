#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto godzillaSpr = CCSprite::create("godzilla.png"_spr);
		auto godzillaBtn = CCMenuItemSpriteExtra::create(godzillaSpr, this, menu_selector(MyMenuLayer::onGodzillaBtn));

		log::debug("Added a button");
		
		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(godzillaBtn);

		godzillaBtn->setID("godzillaBtn"_spr);

		menu->updateLayout();

		return true;
	}

	void onGodzillaBtn(CCObject*) {
		FLAlertLayer::create(
			"Godzilla",
			"I have roared!",
			"Ok Cool"
		)->show();

		log::debug("Created and shown popup");

		FMODAudioEngine::sharedEngine()->playEffect("Godzilla-roar.mp3"_spr);

		log::debug("Played Sound Effect eith FMOD");
	}
};
