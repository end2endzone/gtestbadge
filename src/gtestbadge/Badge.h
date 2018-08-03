#include <string>

class Badge
{
public:
  Badge();
  virtual ~Badge();

  void setLeftFontSize(int size);
  void setLeftText(const std::string & text);
  void setLeftWidth(int width);
  void setLeftBackgroundColor(const std::string & color);
  void setLeftTextLeftPadding(int size);
  void setLeftTextRightPadding(int size);

  void setRightFontSize(int size);
  void setRightText(const std::string & text);
  void setRightWidth(int width);
  void setRightBackgroundColor(const std::string & color);
  void setRightTextLeftPadding(int size);
  void setRightTextRightPadding(int size);

  bool save(const std::string & iFilePath);

  static const int WIDTH_AUTO = -1;

private:
  struct PROPERTIES
  {
    int font_size;
    int width;
    std::string back_color;
    std::string text;
    int text_left_padding;
    int text_right_padding;
  };
  PROPERTIES mLeft;
  PROPERTIES mRight;
};