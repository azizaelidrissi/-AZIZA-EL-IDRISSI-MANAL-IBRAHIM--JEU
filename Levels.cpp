/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "HelloWorldScene.h"
#include "Levels.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

USING_NS_CC;

Scene* Levels::createScene()
{
    return Levels::create();
}



// on "init" you need to initialize your instance
bool Levels::init()
{
    if (!Scene::init()) {
        return false;
    }
    Size visiblesize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    //partie background

    auto mysprite = Sprite::create("whitebac.png");
    mysprite->setPosition(Point((visiblesize.width / 2) + origin.x, (visiblesize.height / 2 + origin.y + 46)));
    mysprite->setScale(8, 8);
    this->addChild(mysprite);

    //partie boutons levels

    //button lvl1

    auto menu_item = MenuItemImage::create("level01.png", "level01.png", CC_CALLBACK_1(Levels::level1, this));
    menu_item->setPosition(Point(visiblesize.width / 2, (visiblesize.height / 4) * 3));
  
    //button lvl2

    auto menu_item_2 = MenuItemImage::create("level02.png", "level02.png", CC_CALLBACK_1(Levels::level2, this));
    menu_item_2->setPosition(Point(visiblesize.width / 2, (visiblesize.height / 4) * 2));
     //button lvl3

    auto menu_item_3 = MenuItemImage::create("level03.png", "level03.png", CC_CALLBACK_1(Levels::level3, this));
    menu_item_3->setPosition(Point(visiblesize.width / 2, (visiblesize.height / 4) * 1));

    auto* menu = Menu::create(menu_item, menu_item_2, menu_item_3, NULL);
    menu->setPosition(Point(0, 0));

    this->addChild(menu);

    return true;
}
//fonction cliquer sur bouton lvl1
void Levels::level1(cocos2d::Ref* pSender) {
    auto scene1 = Level1::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.2, scene1));
}

//fonction cliquer sur bouton lvl2

void Levels::level2(cocos2d::Ref* pSender) {
    auto scene2 = Level2::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.2, scene2));
}

//fonction cliquer sur bouton lvl3

void Levels::level3(cocos2d::Ref* pSender) {
    auto scene3 = Level3::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(0.2, scene3));
}

