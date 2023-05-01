#include <Arduino.h>
#include <TaskManagerIO.h>
#include <U8g2lib.h>
#include <UiUiUi.h>
#include <Wire.h>

#define ESP8266
#include "AiEsp32RotaryEncoder.h"

#define CTRL_PANEL_ENCODER_A_PIN 33
#define CTRL_PANEL_ENCODER_B_PIN 32
#define CTRL_PANEL_ENCODER_BUTTON_PIN 14
#define CTRL_PANEL_ENCODER_VCC_PIN -1
#define CTRL_PANEL_ENCODER_STEPS 2
#define CTRL_PANEL_ENCODER_MIN_VAL 120
#define CTRL_PANEL_ENCODER_MAX_VAL 170
const char* icon_8x8_padlock_opened = "\u0044";  // u8g2_font_open_iconic_thing_1x_t
const char* icon_8x8_padlock_closed = "\u004F";  // u8g2_font_open_iconic_thing_1x_t
const char* icon_8x8_wifi = "\u0048";            // u8g2_font_open_iconic_www_1x_t

const char* icon_8x8_up_arrow = "\u0070";           // u8g2_font_open_iconic_all_1x_t
const char* icon_8x8_down_arrow = "\u006D";         // u8g2_font_open_iconic_all_1x_t
const char* icon_8x8_circle_center_dot = "\u0047";  // u8g2_font_open_iconic_other_1x_t

const char* icon_8x8_shutter = "\u0047";          // u8g2_font_open_iconic_all_1x_t
const char* icon_8x8_up_arrow_long = "\u0053";    // u8g2_font_open_iconic_all_1x_t
const char* icon_8x8_down_arrow_long = "\u0048";  // u8g2_font_open_iconic_all_1x_t
const char* icon_8x8_bell = "\u005D";             // u8g2_font_open_iconic_all_1x_t

const char* icon_8x8_timer = "\u0048";  // u8g2_font_open_iconic_app_1x_t
const char* icon_8x8_clock = "\u0045";  // u8g2_font_open_iconic_app_1x_t

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/22, /* data=*/21, /* reset=*/U8X8_PIN_NONE);
AiEsp32RotaryEncoder ctrlPanelEncoder = AiEsp32RotaryEncoder(CTRL_PANEL_ENCODER_A_PIN, CTRL_PANEL_ENCODER_B_PIN, CTRL_PANEL_ENCODER_BUTTON_PIN, CTRL_PANEL_ENCODER_VCC_PIN, CTRL_PANEL_ENCODER_STEPS);

// ----- FOOTER -----
UITextLine footerText = UITextLine(u8g2_font_scrum_tr, UIAlignment::CenterLeft);
UITextIcon footerIcon = UITextIcon(u8g2_font_open_iconic_all_1x_t, UISize(8, 8), &footerText);
UIColumns footerColumn = UIColumns(&footerIcon, &footerText);
UIEnvelope footerColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &footerColumn);
// UIHorizontalLine horizontalLine = UIHorizontalLine(&footerColumnEnvelope);

// MAIN MIDDLE CONTENT

// ----- middle popup message content -----
UITextLine midPopupMessageText = UITextLine(u8g2_font_spleen16x32_mf, UIAlignment::Center);
UIColumns midPopupMessageTextColumn = UIColumns(&midPopupMessageText);
UIEnvelope midPopupMessageEnvelope = UIEnvelope(UIExpansion::Both, UIAlignment::Center, &midPopupMessageTextColumn);
UIColumns midPopupMessageContent = UIColumns(&midPopupMessageEnvelope);

// ----- up/down indicator (right vertical) -----
UITextIcon upDownIndicatorDownIcon = UITextIcon(u8g2_font_open_iconic_all_1x_t, UISize(16, 16));
UITextIcon clickIndicatorIcon = UITextIcon(u8g2_font_open_iconic_all_1x_t, UISize(16, 8), &upDownIndicatorDownIcon);
UITextIcon upDownIndicatorUpIcon = UITextIcon(u8g2_font_open_iconic_all_1x_t, UISize(16, 16), &clickIndicatorIcon);
UIRows upDownIndicatorRow = UIRows(&upDownIndicatorUpIcon);
UIEnvelope upDownIndicatorRowEnvelope = UIEnvelope(UIExpansion::Vertical, UIAlignment::CenterRight, &upDownIndicatorRow);
// UIVerticalLine verticalLine = UIVerticalLine(&upDownIndicatorRowEnvelope);

// ----- desk height indicator (middle) -----
UITextLine deskHeightIndicatorUnitsText = UITextLine(u8g2_font_spleen16x32_mf);
UITextLine deskHeightIndicatorValueText = UITextLine(u8g2_font_spleen16x32_mf, UIAlignment::CenterRight, &deskHeightIndicatorUnitsText);
UIColumns deskHeightIndicatorColumn = UIColumns(&deskHeightIndicatorValueText, &deskHeightIndicatorUnitsText);

UIEnvelope deskHeightIndicatorEnvelope = UIEnvelope(UIExpansion::Both, UIAlignment::Center, &deskHeightIndicatorColumn, &upDownIndicatorRowEnvelope);

UIColumns midContents = UIColumns(&deskHeightIndicatorEnvelope, &midPopupMessageContent);
UICards middleContentColumnCard = UICards(&midContents);
UIEnvelope middleContentColumnCardEnvelope = UIEnvelope(UIExpansion::Both, UIAlignment::Center, &middleContentColumnCard, &footerColumnEnvelope);

// ----- menu items list -----

// 16x16 icon | w x 16 text
// 16x16 icon | w x 16 text
// 16x16 icon | w x 16 text
UITextLine menuSelectionItem3Text = UITextLine(u8g2_font_spleen6x12_mu, UIAlignment::CenterLeft);
UITextIcon menuSelectionItem3TextIcon = UITextIcon(u8g2_font_open_iconic_arrow_1x_t, UISize(18, 16), &menuSelectionItem3Text);
UIColumns menuSelectionItem3Column = UIColumns(&menuSelectionItem3TextIcon, &menuSelectionItem3Text);
UIEnvelope menuSelectionItem3ColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &menuSelectionItem3Column);

UITextLine menuSelectionItem2Text = UITextLine(u8g2_font_spleen6x12_mu, UIAlignment::CenterLeft, &menuSelectionItem3ColumnEnvelope);
UITextIcon menuSelectionItem2TextIcon = UITextIcon(u8g2_font_open_iconic_arrow_1x_t, UISize(18, 16), &menuSelectionItem2Text);
UIColumns menuSelectionItem2Column = UIColumns(&menuSelectionItem2TextIcon, &menuSelectionItem2Text);
UIEnvelope menuSelectionItem2ColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &menuSelectionItem2Column, &menuSelectionItem3ColumnEnvelope);

UITextLine menuSelectionItem1Text = UITextLine(u8g2_font_spleen6x12_mu, UIAlignment::CenterLeft, &menuSelectionItem2ColumnEnvelope);
UITextIcon menuSelectionItem1TextIcon = UITextIcon(u8g2_font_open_iconic_arrow_1x_t, UISize(18, 16), &menuSelectionItem1Text);
UIColumns menuSelectionItem1Column = UIColumns(&menuSelectionItem1TextIcon, &menuSelectionItem1Text);
UIEnvelope menuSelectionItem1ColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &menuSelectionItem1Column, &menuSelectionItem2ColumnEnvelope);

UIRows menuSelectionItemRows = UIRows(&menuSelectionItem1ColumnEnvelope);
UIEnvelope menuSelectionItemRowsEnvelope = UIEnvelope(UIExpansion::Both, UIAlignment::BottomLeft, &menuSelectionItemRows);

// ----- memory menu item contents -----
UITextLine memorySelectionItem3Text = UITextLine(u8g2_font_UnnamedDOSFontIV_tr, UIAlignment::CenterLeft);
UITextIcon memorySelectionItem3TextIcon = UITextIcon(u8g2_font_open_iconic_arrow_1x_t, UISize(18, 16), &memorySelectionItem3Text);
UIColumns memorySelectionItem3Column = UIColumns(&memorySelectionItem3TextIcon, &menuSelectionItem3Text);
UIEnvelope memorySelectionItem3ColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &memorySelectionItem3Column);

UITextLine memorySelectionItem2Text = UITextLine(u8g2_font_UnnamedDOSFontIV_tr, UIAlignment::CenterLeft, &memorySelectionItem3ColumnEnvelope);
UITextIcon memorySelectionItem2TextIcon = UITextIcon(u8g2_font_open_iconic_arrow_1x_t, UISize(18, 16), &memorySelectionItem2Text);
UIColumns memorySelectionItem2Column = UIColumns(&memorySelectionItem2TextIcon, &menuSelectionItem2Text);
UIEnvelope memorySelectionItem2ColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &memorySelectionItem2Column, &memorySelectionItem3ColumnEnvelope);

UITextLine memorySelectionItem1Text = UITextLine(u8g2_font_UnnamedDOSFontIV_tr, UIAlignment::CenterLeft, &memorySelectionItem2ColumnEnvelope);
UITextIcon memorySelectionItem1TextIcon = UITextIcon(u8g2_font_open_iconic_arrow_1x_t, UISize(18, 16), &memorySelectionItem1Text);
UIColumns memorySelectionItem1Column = UIColumns(&memorySelectionItem1TextIcon, &menuSelectionItem1Text);
UIEnvelope memorySelectionItem1ColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &memorySelectionItem1Column, &memorySelectionItem2ColumnEnvelope);

UIRows memorySelectionItemRows = UIRows(&memorySelectionItem1ColumnEnvelope);
UIEnvelope memorySelectionItemRowsEnvelope = UIEnvelope(UIExpansion::Both, UIAlignment::BottomLeft, &memorySelectionItemRows);

UIColumns menuContents = UIColumns(&menuSelectionItemRowsEnvelope, &memorySelectionItemRowsEnvelope);

UICards menuCardStacker = UICards(&menuContents);

UIRows cardStackerContents = UIRows(&middleContentColumnCardEnvelope, &menuCardStacker);
UICards cardStacker = UICards(&cardStackerContents);
UIEnvelope cardStackerEnvelope = UIEnvelope(UIExpansion::Both, UIAlignment::Center, &cardStacker);

// ----- HEADER -----
UIHorizontalLine headerHorizontalLine = UIHorizontalLine(&cardStackerEnvelope);
UITextIcon headerRightIcon3 = UITextIcon(u8g2_font_open_iconic_www_1x_t, UISize(12, 12));
UITextIcon headerRightIcon2 = UITextIcon(u8g2_font_nokiafc22_tf, UISize(12, 12), &headerRightIcon3);
UITextIcon headerRightIcon1 = UITextIcon(u8g2_font_open_iconic_thing_1x_t, UISize(12, 12), &headerRightIcon2);
UIColumns headerIconsColumn = UIColumns(&headerRightIcon1);
UIEnvelope headerIconsColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::CenterRight, &headerIconsColumn);

UITextLine headerCenterText = UITextLine(u8g2_font_spleen6x12_mf, UIAlignment::Center);
UIColumns headerCenterTextColumn = UIColumns(&headerCenterText);
UIEnvelope headerCenterTextColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::Center, &headerCenterTextColumn, &headerIconsColumnEnvelope);

UITextLine headerLeftText = UITextLine(u8g2_font_spleen6x12_mf, UIAlignment::Center);
UITextIcon headerLeftIcon = UITextIcon(u8g2_font_open_iconic_app_1x_t, UISize(12, 12), &headerLeftText);
UIColumns headerLeftTextColumn = UIColumns(&headerLeftIcon);
UIEnvelope headerLeftTextColumnEnvelope = UIEnvelope(UIExpansion::Horizontal, UIAlignment::CenterLeft, &headerLeftTextColumn, &headerCenterTextColumnEnvelope);

UIColumns headerColumn = UIColumns(&headerLeftTextColumnEnvelope, &headerHorizontalLine);
UIRows fullScreen = UIRows(&headerColumn);

UIDisplay displayManager = UIDisplay(&fullScreen);

char midPopupMessageTextStr[10] = ".";
char encValStr[5] = "120";
char deskHeightIndicatorUnitsStr[4] = "cm";

char uiLockIconStrVal[4] = "\u004F";
bool uiLocked = false;

char menuSelectionItem1IconStr[3] = "";
char menuSelectionItem2IconStr[3] = "";
char menuSelectionItem3IconStr[3] = "";

char upDownIndicatorUpIconStr[3] = "";
char upDownIndicatorDownIconStr[3] = "";
char clickIndicatorIconStr[3] = "";

char headerLeftIconStr[3] = "";
char headerLeftTextStr[6] = "";

char headerCenterTextStr[8] = "|";

// UITextIcon menuSelectionItemUITextIcons[3] = {menuSelectionItem1TextIcon, menuSelectionItem2TextIcon, menuSelectionItem3TextIcon};
int currentMenuSelectionItemIdx = -1;

bool midPopupMessageShown = false;
bool menuSelectionsShown = false;
bool memoryMenuShown = false;
bool timerMenuShown = false;
bool settingsMenuShown = false;
bool mainScreenShown = false;

int selectedMemorySettingIdx = -1;

long encLastVal = 0;
long encValDiff = 0;
long encVal = 0;
int encDirection = 0;

long lastDeskHeight = 0;
long requestedDeskHeight = 0;
long currentDeskHeight = 120;

long deskStoredMemory[] = {-1, 150, -1};

long lastCtrlPanelEncoderInteractionMillis = -1;
taskid_t oledDimmerTaskId = -1;
const uint8_t minOledContrast = 15;
const uint8_t maxOledContrast = 255;
uint8_t desiredOledContrast = 255;
uint8_t currentOledContrast = 255;
bool oledOn = true;
// taskid_t ctrlPanelInactivityWatcherTaskId;

TaskManager taskManager1 = TaskManager();
TaskManager taskManager2 = TaskManager();

void setCtrlPanelEncoderMenuItemSelectionBoundaries() {
    ctrlPanelEncoder.setBoundaries(0, 2, false);
    ctrlPanelEncoder.setEncoderValue(0);
}
void setCtrlPanelEncoderDeskHeightBoundaries() {
    ctrlPanelEncoder.setBoundaries(CTRL_PANEL_ENCODER_MIN_VAL, CTRL_PANEL_ENCODER_MAX_VAL, false);
    ctrlPanelEncoder.setEncoderValue(currentDeskHeight);
}

void showUpDownIndicatorUpIcon() {
    upDownIndicatorUpIcon.setText(upDownIndicatorUpIconStr);
    upDownIndicatorUpIcon.updateText();
}

void setUpDownIndicatorUpIconStr(const char* txt) {
    sprintf(upDownIndicatorUpIconStr, "%s", txt);
    upDownIndicatorUpIcon.updateText();
}

void showUpDownIndicatorDownIcon() {
    upDownIndicatorDownIcon.setText(upDownIndicatorDownIconStr);
    upDownIndicatorDownIcon.updateText();
}

void setUpDownIndicatorDownIconStr(const char* txt) {
    sprintf(upDownIndicatorDownIconStr, "%s", txt);
    upDownIndicatorDownIcon.updateText();
}

void showClickIndicatorIcon() {
    clickIndicatorIcon.setText(clickIndicatorIconStr);
    clickIndicatorIcon.updateText();
}

void setClickIndicatorIconStr(const char* txt) {
    sprintf(clickIndicatorIconStr, "%s", txt);
    clickIndicatorIcon.updateText();
}
void hideUpDownIndicatorUpIcon() {
    setUpDownIndicatorUpIconStr("");
}
void hideUpDownIndicatorDownIcon() {
    setUpDownIndicatorDownIconStr("");
}
void hideClickIndicatorIcon() {
    setClickIndicatorIconStr("");
}

void updateMenuItemSelectionIconStr() {
    switch (currentMenuSelectionItemIdx) {
        case 0:
            sprintf(menuSelectionItem1IconStr, "%s", "\u0052");  // TODO
            sprintf(menuSelectionItem2IconStr, "%s", "");        // TODO
            sprintf(menuSelectionItem3IconStr, "%s", "");        // TODO
            break;
        case 1:
            sprintf(menuSelectionItem2IconStr, "%s", "\u0052");  // TODO
            sprintf(menuSelectionItem1IconStr, "%s", "");        // TODO
            sprintf(menuSelectionItem3IconStr, "%s", "");        // TODO
            break;
        case 2:
            sprintf(menuSelectionItem3IconStr, "%s", "\u0052");  // TODO
            sprintf(menuSelectionItem1IconStr, "%s", "");        // TODO
            sprintf(menuSelectionItem2IconStr, "%s", "");        // TODO

            break;
        default:
            break;
    }
}

void updateMenuItemSelectionIcons() {
    menuSelectionItem1TextIcon.updateText();
    menuSelectionItem2TextIcon.updateText();
    menuSelectionItem3TextIcon.updateText();
}

void updateMemorySelectionIcons() {
    memorySelectionItem1TextIcon.updateText();
    memorySelectionItem2TextIcon.updateText();
    memorySelectionItem3TextIcon.updateText();
}

void setHeaderCenterText(const char* txt) {
    sprintf(headerCenterTextStr, "%s", txt);  // TODO
    headerCenterText.updateText();
}

void hideHeaderLeft() {
    headerLeftIcon.clearText();
    headerLeftText.clearText();
}

void showHeaderLeft() {
    headerLeftIcon.setText(headerLeftIconStr);
    headerLeftText.setText(headerLeftTextStr);
    headerLeftIcon.updateText();
    headerLeftText.updateText();
}

void setHeaderLeft(const char* iconStr, const char* textStr) {
    sprintf(headerLeftIconStr, "%s", iconStr);
    sprintf(headerLeftTextStr, "%s", textStr);
    headerLeftIcon.updateText();
    headerLeftText.updateText();
}

void displayMenu() {
    setCtrlPanelEncoderMenuItemSelectionBoundaries();
    cardStacker.setVisibleWidget(&menuCardStacker);
    menuCardStacker.showFirstWidget();
    currentMenuSelectionItemIdx = 0;
    updateMenuItemSelectionIconStr();
    updateMenuItemSelectionIcons();
    hideHeaderLeft();
    setHeaderCenterText("MENU");
    midPopupMessageShown = false;
    menuSelectionsShown = true;
    memoryMenuShown = false;
    timerMenuShown = false;
    settingsMenuShown = false;
    mainScreenShown = false;
}

void displayMemoryMenu() {
    setCtrlPanelEncoderMenuItemSelectionBoundaries();
    cardStacker.setVisibleWidget(&menuCardStacker);
    menuCardStacker.setVisibleWidget(&memorySelectionItemRowsEnvelope);
    currentMenuSelectionItemIdx = 0;
    updateMenuItemSelectionIconStr();
    updateMemorySelectionIcons();
    hideHeaderLeft();
    setHeaderCenterText("MEMORY");

    midPopupMessageShown = false;
    menuSelectionsShown = false;
    memoryMenuShown = true;
    timerMenuShown = false;
    settingsMenuShown = false;
    mainScreenShown = false;
}

void setDefaultUpDownIndicatorIcons() {
    Serial.println("setDefaultUpDownIndicatorIcons");
    // showUpDownIndicatorUpIcon();
    // showUpDownIndicatorDownIcon();
    // showClickIndicatorIcon();
    setUpDownIndicatorUpIconStr(icon_8x8_up_arrow);
    setUpDownIndicatorDownIconStr(icon_8x8_down_arrow);
    setClickIndicatorIconStr(icon_8x8_shutter);
    Serial.print("up: ");
    Serial.print(upDownIndicatorUpIconStr);
    Serial.print(" | down: ");
    Serial.println(upDownIndicatorDownIconStr);
    middleContentColumnCardEnvelope.render(&u8g2, true);
}
void displayMainScreen() {
    setCtrlPanelEncoderDeskHeightBoundaries();
    cardStacker.showFirstWidget();
    middleContentColumnCard.showFirstWidget();
    menuCardStacker.showFirstWidget();
    setHeaderCenterText("|");
    setDefaultUpDownIndicatorIcons();
    showHeaderLeft();
    midPopupMessageShown = false;
    menuSelectionsShown = false;
    memoryMenuShown = false;
    timerMenuShown = false;
    settingsMenuShown = false;
    mainScreenShown = true;
}

void displayMenuScreenAtIdx(int menuScreenIdx) {
    switch (menuScreenIdx) {
        case 0:
            displayMemoryMenu();
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}

void setMidPopupMessageText(const char* msg) {
    sprintf(midPopupMessageTextStr, "%s", msg);  // TODO
    midPopupMessageText.updateText();
}

void midPopupMessageTask(const char* msg, uint32_t durationMillis) {
    taskid_t displayMidPopupMessageTaskId = -1;
    if (!midPopupMessageShown) {
        midPopupMessageShown = true;
        setMidPopupMessageText(msg);
        displayMidPopupMessageTaskId = taskManager2.scheduleOnce(
            100, [] {
                Serial.println("100, card stacker first widget");
                cardStacker.showFirstWidget();

                Serial.println("100, setting middleContentColumnCard to mid popup");
                middleContentColumnCard.setVisibleWidget(&midPopupMessageContent);
            },
            TIME_MILLIS);
    }

    taskManager2.scheduleOnce(durationMillis, [displayMidPopupMessageTaskId]() {
        taskManager2.cancelTask(displayMidPopupMessageTaskId);
        if (midPopupMessageShown) {
            midPopupMessageShown = false;
            if (!mainScreenShown) {
                Serial.println("card stacker prev widget");
                cardStacker.showPreviousVisibleWidget();
            }

            Serial.println("setting middleContentColumnCard to prev widget");
            middleContentColumnCard.showPreviousVisibleWidget();
        }
    });
}
void showUILockedMsg() {
    midPopupMessageTask("LOCKED", 1500);
}

void showUIUnlockedMsg() {
    midPopupMessageTask("UNLOCKED", 1500);
}

void lockUI() {
    if (!uiLocked) {
        uiLocked = true;
        sprintf(uiLockIconStrVal, "%s", icon_8x8_padlock_closed);  // TODO
        headerRightIcon1.updateText();
        showUILockedMsg();
    }
}

void unlockUI() {
    if (uiLocked) {
        uiLocked = false;
        sprintf(uiLockIconStrVal, "%s", icon_8x8_padlock_opened);  // TODO
        headerRightIcon1.updateText();
        showUIUnlockedMsg();
    }
}
void toggleUILock() {
    if (uiLocked) {
        unlockUI();
    } else {
        lockUI();
    }
}
/*
    // example from AiEsp32RotaryEncoder
    static unsigned long lastTimePressed = 0;
    if (millis() - lastTimePressed < 500)
        return;  // ignore multiple press in that time milliseconds
    lastTimePressed = millis();

    unsigned long acceletation = ctrlPanelEncoder.getAcceleration() + 50;
    if (acceletation > 400)
        acceletation = 0;
    ctrlPanelEncoder.setAcceleration(acceletation);

    Serial.print("new acceleration is ");
    Serial.println(acceletation);
    Serial.print("Try to set value: ");
    Serial.println(random(-999, 999));
    Serial.println("Set as fast as you can. If it is too hard or you suceeded, press the button again.");


*/

void handleStoreMemory() {
    midPopupMessageTask("STORED", 1000);
}
taskid_t mockDeskHeightIncrease() {
    hideUpDownIndicatorUpIcon();
    hideUpDownIndicatorDownIcon();
    setClickIndicatorIconStr(icon_8x8_up_arrow_long);
    taskid_t mockDeskHeightIncreaseTaskId = taskManager2.scheduleFixedRate(300, [] {
        if (currentDeskHeight < deskStoredMemory[selectedMemorySettingIdx]) {
            currentDeskHeight++;
            sprintf(encValStr, "%03d", (int)currentDeskHeight);
            deskHeightIndicatorValueText.updateText();
        }
    });
    taskManager2.scheduleOnce(
        10000, [mockDeskHeightIncreaseTaskId]() {
            taskManager2.cancelTask(mockDeskHeightIncreaseTaskId);
            setDefaultUpDownIndicatorIcons();
        },
        TIME_MILLIS);
}

void handleMemorySelectionClick() {
    if (deskStoredMemory[currentMenuSelectionItemIdx] == -1) {
        midPopupMessageTask("NOT SET", 1000);
    } else {
        selectedMemorySettingIdx = currentMenuSelectionItemIdx;
        // TODO -
        displayMainScreen();
        mockDeskHeightIncrease();
    }
}

void ctrlPanelEncoderOnBtnClick() {
    Serial.println("ctrlPanelEncoderOnBtnClick");
    if (mainScreenShown) {  // lock/unlock only if main screen is shown
        toggleUILock();
    } else if (menuSelectionsShown) {
        displayMenuScreenAtIdx(currentMenuSelectionItemIdx);
    } else if (memoryMenuShown) {
        // idx is chosen mem setting
        handleMemorySelectionClick();
    }
}

void ctrlPanelEncoderOnBtnHeldDown() {
    Serial.println("ctrlPanelEncoderOnBtnHeldDown");
    toggleUILock();
}

void setOledContrast(uint8_t contrastVal) {
    if (contrastVal >= 255) {
        currentOledContrast = 255;
    } else if (contrastVal <= 0) {
        currentOledContrast = 0;
    } else {
        currentOledContrast = contrastVal;
    }
    u8g2.setContrast(currentOledContrast);
}
void turnOffOled() {
    if (oledOn) {
        oledOn = false;
        displayManager.disable(&u8g2);
    }
}

void turnOnOled() {
    if (!oledOn) {
        oledOn = true;
        displayManager.enable(&u8g2, true, false);
    }
}

void dimOled(uint8_t reduceVal) {
    currentOledContrast = currentOledContrast - reduceVal;
    setOledContrast(currentOledContrast);
}
bool isCtrlPanelEncoderInactive() {
    return (millis() - lastCtrlPanelEncoderInteractionMillis) > 60000;
}
void startCtrlPanelDimmer() {
    oledDimmerTaskId = taskManager2.scheduleFixedRate(1000, [] {
        if (currentOledContrast > minOledContrast) {
            dimOled(5);
        } else {
            turnOffOled();
        }
    });
}

void ctrlPanelEncoderStatusHandler() {
    if (isCtrlPanelEncoderInactive()) {
        if (currentOledContrast == desiredOledContrast) {
            lockUI();
            startCtrlPanelDimmer();
        }
    } else {
        taskManager2.scheduleOnce(100, [] {
            taskManager2.cancelTask(oledDimmerTaskId);
        });
        if (currentOledContrast != desiredOledContrast) {
            turnOnOled();
            setOledContrast(desiredOledContrast);
        }
    }
    encValDiff = ctrlPanelEncoder.encoderChanged();
    if (encValDiff) {
        lastCtrlPanelEncoderInteractionMillis = millis();
        encVal = ctrlPanelEncoder.readEncoder();
        encLastVal = encVal + encValDiff;

        if (encValDiff < 0) {
            encDirection = -1;
        } else if (encValDiff > 0) {
            encDirection = 1;
        } else {
            encDirection = 0;
        }
        Serial.println(encVal);
        if (uiLocked) {
            showUILockedMsg();
        } else {
            if (mainScreenShown) {
                sprintf(encValStr, "%03d", (int)encVal);
                // sprintf(encValStr, "%d | %d", (int)encLastVal, (int)encValDiff);
                Serial.println(encValStr);
                deskHeightIndicatorValueText.updateText();
            } else if (menuSelectionsShown) {
                currentMenuSelectionItemIdx = encVal;
                updateMenuItemSelectionIconStr();
                updateMenuItemSelectionIcons();
            } else if (memoryMenuShown) {
                currentMenuSelectionItemIdx = encVal;
                updateMenuItemSelectionIconStr();
                updateMemorySelectionIcons();
            }
            // Serial.println(encValStr);
        }
    }

    if (ctrlPanelEncoder.isEncoderButtonClicked()) {
        lastCtrlPanelEncoderInteractionMillis = millis();
        ctrlPanelEncoderOnBtnClick();
    } else if (ctrlPanelEncoder.isEncoderButtonClicked(2000)) {
        lastCtrlPanelEncoderInteractionMillis = millis();
        if (uiLocked) {
            showUILockedMsg();
        } else if (mainScreenShown) {  // if main screen shown and ui not locked
            displayMenu();
        } else if (memoryMenuShown) {
            handleStoreMemory();
        } else {  // otherwise return to main screen
            displayMainScreen();
        }
    }
    //  else if (ctrlPanelEncoder.isEncoderButtonClicked(3000)) {
    // }
}

void IRAM_ATTR readEncoderISR() {
    ctrlPanelEncoder.readEncoder_ISR();
}

// void startCtrlPanelInactivityWatcher() {
//     ctrlPanelInactivityWatcherTaskId = taskManager1.scheduleFixedRate(1000, [] {
//         // if (isCtrlPanelEncoderInactive()) {
//         //     Serial.println("ctrl panel inactive");
//         //     startCtrlPanelDimmer();
//         // } else {
//         //     taskManager1.cancelTask(oledDimmerTaskId);
//         //     if (currentOledContrast != desiredOledContrast) {
//         //         setOledContrast(desiredOledContrast);
//         //     }
//         // }
//     });
// }

void setupCtrlPanelEncoder() {
    // pinMode(CTRL_PANEL_ENCODER_A_PIN, INPUT_PULLUP);
    // pinMode(CTRL_PANEL_ENCODER_B_PIN, INPUT_PULLUP);
    pinMode(CTRL_PANEL_ENCODER_A_PIN, INPUT);
    pinMode(CTRL_PANEL_ENCODER_B_PIN, INPUT);
    ctrlPanelEncoder.begin();
    ctrlPanelEncoder.setup(readEncoderISR);
    setCtrlPanelEncoderDeskHeightBoundaries();
    taskManager1.scheduleFixedRate(50, [] {
        ctrlPanelEncoderStatusHandler();
    });
    // startCtrlPanelInactivityWatcher();
}

void setupOledDisplay() {
    // Initialize the display
    u8g2.begin();  // Init U8g2, this is done outside of UiUiUi

    displayManager.init(&u8g2);  // Now init the interface including layouting
    deskHeightIndicatorValueText.setText(encValStr);
    deskHeightIndicatorUnitsText.setText(deskHeightIndicatorUnitsStr);

    upDownIndicatorUpIcon.setText(upDownIndicatorUpIconStr);
    upDownIndicatorDownIcon.setText(upDownIndicatorDownIconStr);
    clickIndicatorIcon.setText(clickIndicatorIconStr);

    headerRightIcon3.setText("\u0048");
    // headerRightIcon2.setText("\u0044");
    headerRightIcon2.setText("");
    headerRightIcon1.setText(uiLockIconStrVal);
    headerCenterText.setText(headerCenterTextStr);
    setHeaderLeft(icon_8x8_timer, "02:25");
    footerIcon.setText("\u005D");              // \u005D bell
    footerText.setText(" Stand-up reminder");  // len 17 is max, -1 for space padding from icon
    // footerIcon.updateText();

    midPopupMessageText.setText(midPopupMessageTextStr);
    displayMainScreen();
    // displayMemoryMenu();
    // middleContentColumnCard.showFirstWidget();

    // menuCardStacker.showFirstWidget();
    // cardStacker.setVisibleWidget(&menuSelectionItemRowsEnvelope);

    menuSelectionItem1TextIcon.setText(menuSelectionItem1IconStr);  // ("\u0052");  // \u0050-> down hat // \u0051 back hat
    menuSelectionItem2TextIcon.setText(menuSelectionItem2IconStr);
    menuSelectionItem3TextIcon.setText(menuSelectionItem3IconStr);
    menuSelectionItem1Text.setText("MEMORY");
    // menuSelectionItem3Text.updateText();
    menuSelectionItem2Text.setText("TIMER");
    menuSelectionItem3Text.setText("SETTINGS");

    memorySelectionItem1TextIcon.setText(menuSelectionItem1IconStr);
    memorySelectionItem1Text.setText("\u004D\u0031");
    memorySelectionItem2TextIcon.setText(menuSelectionItem2IconStr);
    memorySelectionItem2Text.setText("\u004D\u0032");
    memorySelectionItem3TextIcon.setText(menuSelectionItem3IconStr);
    memorySelectionItem3Text.setText("\u004D\u0033");

    taskManager2.scheduleFixedRate(50, [] {
        displayManager.render(&u8g2);
    });
}
/**
 * We'll use this function to print out the milliseconds from start and also the
 * line to write to Serial
 */
void log(const char* logLine) {
    Serial.print(millis());
    Serial.print(": ");
    Serial.println(logLine);
}

void setup() {
    Serial.begin(115200);
    setupOledDisplay();
    setupCtrlPanelEncoder();
}

void loop() {
    taskManager1.runLoop();
    taskManager2.runLoop();
}

// https://github.com/dirkhillbrecht/UiUiUi/blob/master/examples/ButtonsAndLED/ButtonsAndLED.ino
// https://www.upesy.com/blogs/tutorials/rotary-encoder-esp32-with-arduino-code