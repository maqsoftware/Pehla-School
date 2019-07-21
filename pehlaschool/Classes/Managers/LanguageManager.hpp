//
//  LanguageManager.hpp
//  PehlaSchool
//
//  Created by Sungwoo Kang on 6/30/16.
//
//

#ifndef LanguageManager_hpp
#define LanguageManager_hpp

#include <string>
#include <vector>
#include <map>
#include "Common/Basic/SoundEffect.h"


// NB(xenosoz, 2018): I'm confused... Let me summarize the concepts:
//   LocaleType: enum values
//   LocaleCode: "en-US", "sw-TZ", ...
//
//   _currentLocale looks like the only internal variable for locale (in LocaleType).
//
//   LanguageCode = LocaleCode[0:2]
//   LanguageTag = LocaleCode[:]
//   LocaleCode = LocaleCode[:]
//

class LanguageManager {

    static LanguageManager* _instance;
public:
    std::string customLanguageCode = "hi"; // en hi ur bn sw
    enum LocaleType {
        sw_TZ = 0,
        en_US,
        hi_IN,
        ur_IN,
        bn_IN,
        LocaleType_MAX
    };

    static LanguageManager* getInstance();
    void init();
    
    LocaleType convertLocaleCodeToType(std::string localeCode);
    std::string convertLocaleTypeToCode(LocaleType localeType);
    
    void setCurrentLocale(LocaleType type);
    LocaleType getCurrentLocaleType();
    LocaleType findNextLocale();

    
    std::string getCurrentLanguageCode();
    std::string getCurrentLanguageTag();
    std::string getCurrentLocaleCode();
    
    
    std::string soundPathForWordFile(std::string& wordFile);
    
    std::string getLocalizedString(std::string str);
    
    std::string findLocalizedResource(std::string path);
    
    bool isEnglish() { return true; }
    bool isSwahili() { return false; }
    
    std::vector<std::string> getLocalizationMapKeys();
    bool isSignLanguageMode();
    
private:
    LocaleType _currentLocale;

    
    std::vector<std::string> _localizedResourcePaths;

    std::vector<LocaleType> _supportedLocales;
    
    
    std::map<std::string, std::string> _localizationMap;
    std::map<std::string, std::string> _localizationMapEnglish;
    std::map<std::string, std::string> _localizationMapHindi;
    std::map<std::string, std::string> _localizationMapUrdu;
    std::map<std::string, std::string> _localizationMapBengali;
    std::map<std::string, std::string> _localizationMapSwahili;
    
    void initLocalizationMap();
    
    
    
    
};

#endif /* LanguageManager_hpp */
