#pragma once
#include "gd.h"

#include "macros.h"

// ItzZyann
// FROM GEODE BINDINGS

class TextArea;
class TextInputDelegate;

class CCTextInputNode : CCLayer, CCIMEDelegate, CCTextFieldDelegate {
public:
 CCTextInputNode() {
  m_numberInput = false;
  m_caption = "";
  m_unknown1 = 0;
  m_selected = false;
  m_unknown2 = false;
  m_fontValue1 = -0.5f;
  m_fontValue2 = 8.0f;
  m_isChatFont = false;
  m_allowedChars = "";
  m_maxLabelWidth = 0.0f;
  m_maxLabelScale = 0.0f;
  m_placeholderScale = 0.0f;
  m_placeholderColor = ccc3(0, 0, 0);
  m_textColor = ccc3(0, 0, 0);
  m_cursor = nullptr;
  m_textField = nullptr;
  m_delegate = nullptr;
  m_maxLabelLength = 0;
  m_placeholderLabel = nullptr;
  m_unknown3 = false;
  m_usePasswordChar = false;
  m_forceOffset = false;
  m_textArea = nullptr;
 }

 static CCTextInputNode* create(float, float, char const*, char const*, int, char const*);
	
 static CCTextInputNode* create(float width, float height, char const* placeholder, char const* fontPath) {
  return CCTextInputNode::create(width, height, placeholder, 0x18, fontPath);
 }

 static CCTextInputNode* create(float width, float height, char const* placeholder, int fontSize, char const* fontPath) {
  return CCTextInputNode::create(width, height, placeholder, "Thonburi", fontSize, fontPath);
 }

 void setDelegate(TextInputDelegate* delegate) {
  m_delegate = delegate;
 }
 
 void setMaxLabelScale(float v) {
  m_maxLabelScale = v;
  this->refreshLabel();
 }

 void setMaxLabelWidth(float v) {
  m_maxLabelWidth = v;
  this->refreshLabel();
 }

 void setMaxLabelLength(int v) {
  m_maxLabelLength = v;
  this->refreshLabel();
 }
	
 void setLabelPlaceholderScale(float v) {
  m_placeholderScale = v;
  this->refreshLabel();
 }
 
 void setLabelPlaceholderColor(ccColor3B color) {
  m_placeholderColor = color;
  this->refreshLabel();
 }
 
 void setAllowedChars(std::string filter) {
  m_allowedChars = filter;
 }
 
 void addTextArea(TextArea*);
 void forceOffset();
 std::string getString() { return m_textField->getString(); }
 bool init(float, float, char const*, char const*, int, char const*);
 void refreshLabel();
 void setLabelNormalColor(ccColor3B);
 void setString(std::string);
 void updateBlinkLabel();
 void updateBlinkLabelToChar(int);
 void updateCursorPosition(CCPoint, CCRect);
 void updateDefaultFontValues(std::string);
 void updateLabel(std::string);

 virtual void visit();
 virtual bool ccTouchBegan(CCTouch*, CCEvent*);
 virtual void ccTouchMoved(CCTouch*, CCEvent*);
 virtual void ccTouchEnded(CCTouch*, CCEvent*);
 virtual void ccTouchCancelled(CCTouch*, CCEvent*);
 virtual void registerWithTouchDispatcher();
 virtual void textChanged();
 virtual void onClickTrackNode(bool);
 virtual void keyboardWillShow(CCIMEKeyboardNotificationInfo&);
 virtual void keyboardWillHide(CCIMEKeyboardNotificationInfo&);
 virtual bool onTextFieldInsertText(CCTextFieldTTF*, char const*, int, enumKeyCodes);
 virtual bool onTextFieldAttachWithIME(CCTextFieldTTF*);
 virtual bool onTextFieldDetachWithIME(CCTextFieldTTF*);

 bool m_numberInput;
 std::string m_caption;
 int m_unknown1;
 bool m_selected;
 bool m_unknown2;
 float m_fontValue1;
 float m_fontValue2;
 bool m_isChatFont;
 std::string m_allowedChars;
 float m_maxLabelWidth;
 float m_maxLabelScale;
 float m_placeholderScale;
 ccColor3B m_placeholderColor;
 ccColor3B m_textColor;
 CCLabelBMFont* m_cursor;
 CCTextFieldTTF* m_textField;
 TextInputDelegate* m_delegate;
 int m_maxLabelLength;
 CCLabelBMFont* m_placeholderLabel;
 bool m_unknown3;
 bool m_usePasswordChar;
 bool m_forceOffset;
 TextArea* m_textArea;
 PAD(0xC); // ANDROID 32
};