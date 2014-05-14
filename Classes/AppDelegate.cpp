#include "AppDelegate.h"
#include "GameLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("Rocket Through");
        director->setOpenGLView(glview);
    }

    auto screenSize = glview->getFrameSize();
    auto designSize = Size{768, 1024};
    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::EXACT_FIT);
    
    float screenRatio = screenSize.height/screenSize.width;

    if (screenSize.width >= 768) {
        FileUtils::getInstance()->setSearchPaths({"ipadhd"});
    } else if (screenSize.width >= 320) {
        if (screenRatio >= 1.5f) {
            FileUtils::getInstance()->setSearchPaths({"iphonehd"});
        } else {
            FileUtils::getInstance()->setSearchPaths({"ipad"});
        }
    } else {
        FileUtils::getInstance()->setSearchPaths({"iphone"});
    }
    director->setContentScaleFactor(screenSize.height/designSize.height);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = GameLayer::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
