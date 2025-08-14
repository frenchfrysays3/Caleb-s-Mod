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

		roar();

		log::debug("Roar has played");
	}

	void roar() {
		static int sound = 0;

		if (sound == 0) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar1.mp3"_spr);
		} else if (sound == 1) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar2.mp3"_spr);
		} else if (sound == 2) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar3.mp3"_spr);
		} else if (sound == 3) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar4.mp3"_spr);
		} else if (sound == 4) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar5.mp3"_spr);
		} else if (sound == 5) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar6.mp3"_spr);
		} else if (sound == 6) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar7.mp3"_spr);
		} else if (sound == 7) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar8.mp3"_spr);
		} else if (sound == 8) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar9.mp3"_spr);
		} else if (sound == 9) {
			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar10.mp3"_spr);
		}

		if (sound == 10) {
			sound = 1;

			FMODAudioEngine::sharedEngine()->playEffect("godzilla-roar1.mp3"_spr);
		}

		sound = sound + 1;
	}
};
