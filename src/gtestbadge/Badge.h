#include <string>

class Badge
{
public:
  //structures
  struct SIDE_PROPERTIES
  {
    int font_size;
    int width;
    std::string front_color;
    std::string back_color;
    std::string text;
    int text_left_padding;
    int text_right_padding;
  };
  
  //constants
  static const int WIDTH_AUTO = -1;
  static const int HEIGHT_AUTO = -1;

  //ctor
  Badge();
  virtual ~Badge();

  void setHeight(int size);

  void setLeftFontSize(int size);
  void setLeftText(const std::string & text);
  void setLeftWidth(int width);
  void setLeftBackgroundColor(const std::string & color);
  void setLeftForegroundColor(const std::string & color);
  void setLeftTextLeftPadding(int size);
  void setLeftTextRightPadding(int size);

  void setRightFontSize(int size);
  void setRightText(const std::string & text);
  void setRightWidth(int width);
  void setRightBackgroundColor(const std::string & color);
  void setRightForegroundColor(const std::string & color);
  void setRightTextLeftPadding(int size);
  void setRightTextRightPadding(int size);

  bool save(const std::string & iFilePath);

  //inline getters
  int getHeight() const                               { return mHeight; }

  int getLeftFontSize() const                         { return mLeft.font_size; }
  const std::string & getLeftText() const             { return mLeft.text; }
  int getLeftWidth() const                            { return mLeft.width; }
  const std::string & getLeftBackgroundColor() const  { return mLeft.back_color; }
  const std::string & getLeftForegroundColor() const  { return mLeft.front_color; }
  int getLeftTextLeftPadding() const                  { return mLeft.text_left_padding; }
  int getLeftTextRightPadding() const                 { return mLeft.text_right_padding; }

  int getRightFontSize() const                        { return mRight.font_size; }
  const std::string & getRightText() const            { return mRight.text; }
  int getRightWidth() const                           { return mRight.width; }
  const std::string & getRightBackgroundColor() const { return mRight.back_color; }
  const std::string & getRightForegroundColor() const { return mRight.front_color; }
  int getRightTextLeftPadding() const                 { return mRight.text_left_padding; }
  int getRightTextRightPadding() const                { return mRight.text_right_padding; }

  const SIDE_PROPERTIES & getLeftSide() const         { return mLeft; }
  SIDE_PROPERTIES & getLeftSide()                     { return mLeft; }
  const SIDE_PROPERTIES & getRightSide() const        { return mRight; }
  SIDE_PROPERTIES & getRightSide()                    { return mRight; }

private:
  int mHeight;
  SIDE_PROPERTIES mLeft;
  SIDE_PROPERTIES mRight;
};
