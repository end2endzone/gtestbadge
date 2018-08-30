#include <string>

class Badge
{
public:
  ///<summary>Defines the properties of each side of the badge</summary>
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
 
  ///<summary>Enum for specifying left or right side for api functions.</summary>
  enum BadgeSide
  {
    RIGHT_SIDE,
    LEFT_SIZE,
  };

  //constants
  static const int WIDTH_AUTO = -1;
  static const int HEIGHT_AUTO = -1;
 
  //ctor / dtor
 
  ///<summary>ctor</summary>
  Badge();
 
  ///<summary>dtor</summary>
  virtual ~Badge();
 
  ///<summary>Sets the height in pixel.</summary>
  ///<param name="size">The height in pixel. Set to HEIGHT_AUTO to automatically compute the appropriate height based on text font size.</param>
  void setHeight(int size);
 
  ///<summary>Assign an icon to the badge.</summary>
  ///<param name="icon">A string representing an svg icon encoded in base64.</param>
  void setBase64Icon(const std::string & icon);
 
  ///<summary>Saves the badge to a svg file.</summary>
  ///<param name="iFilePath">The path of the file for saving.</param>
  ///<returns>Returns true if the save is succesful. Returns false otherwise.</returns>
  bool save(const std::string & iFilePath);
 
  ///<summary>Set the font size of the given side in pixel.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="size">The size of the font in pixel.</param>
  void setFontSize(const BadgeSide & side, int size);
 
  ///<summary>Set the display text of the given side.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="text">The text to display on the given side.</param>
  void setText(const BadgeSide & side, const std::string & text);
 
  ///<summary>Set the width in pixel of the given side.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="width">The width in pixel of the given side.</param>
  void setWidth(const BadgeSide & side, int width);
 
  ///<summary>Set the background color of the given side.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="color">The color code in web format. ie `#3456a0`.</param>
  void setBackgroundColor(const BadgeSide & side, const std::string & color);
 
  ///<summary>Set the foreground color of the given side.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="color">The color code in web format. ie `#3456a0`.</param>
  void setForegroundColor(const BadgeSide & side, const std::string & color);
 
  ///<summary>Set the left padding space in pixels of the text for the given side.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="size">The padding size in pixels.</param>
  void setTextLeftPadding(const BadgeSide & side, int size);
 
  ///<summary>Set the right padding space in pixels of the text for the given side.</summary>
  ///<param name="side">The side affected by the function call.</param>
  ///<param name="size">The padding size in pixels.</param>
  void setTextRightPadding(const BadgeSide & side, int size);
 
  //inline getters
 
  ///<summary>Get the height.</summary>
  ///<returns>Returns the height.</returns>
  int getHeight() const                               { return mHeight; }
 
  ///<summary>Get the icon string encoded in base64.</summary>
  ///<returns>Returns the icon string encoded in base64.</returns>
  const std::string & getBase64Icon() const           { return mIcon; }
 
  //inline getters for left side
 
  ///<summary>Get the font size in pixels of the left side.</summary>
  ///<returns>Returns the font size in pixels of the left side.</returns>
  int getLeftFontSize() const                         { return mLeft.font_size; }
 
  ///<summary>Get the text of the left side.</summary>
  ///<returns>Returns the text of the left side.</returns>
  const std::string & getLeftText() const             { return mLeft.text; }
 
  ///<summary>Get the width of the left side.</summary>
  ///<returns>Returns the width of the left side.</returns>
  int getLeftWidth() const                            { return mLeft.width; }
 
  ///<summary>Get the background color for the left side.</summary>
  ///<returns>Returns the background color for the left side.</returns>
  const std::string & getLeftBackgroundColor() const  { return mLeft.back_color; }
 
  ///<summary>Get the foreground color for the left side.</summary>
  ///<returns>Returns the foreground color for the left side.</returns>
  const std::string & getLeftForegroundColor() const  { return mLeft.front_color; }
 
  ///<summary>Get the padding space in pixels left of the text for the left side.</summary>
  ///<returns>Returns the padding space in pixels left of the text for the left side.</returns>
  int getLeftTextLeftPadding() const                  { return mLeft.text_left_padding; }
 
  ///<summary>Get the padding space in pixels right of the text for the left side.</summary>
  ///<returns>Returns the padding space in pixels right of the text for the left side.</returns>
  int getLeftTextRightPadding() const                 { return mLeft.text_right_padding; }
 
  //inline getters for right side
 
  ///<summary>Get the font size in pixels of the right side.</summary>
  ///<returns>Returns the font size in pixels of the right side.</returns>
  int getRightFontSize() const                         { return mRight.font_size; }
 
  ///<summary>Get the text of the right side.</summary>
  ///<returns>Returns the text of the right side.</returns>
  const std::string & getRightText() const             { return mRight.text; }
 
  ///<summary>Get the width of the right side.</summary>
  ///<returns>Returns the width of the right side.</returns>
  int getRightWidth() const                            { return mRight.width; }
 
  ///<summary>Get the background color for the right side.</summary>
  ///<returns>Returns the background color for the right side.</returns>
  const std::string & getRightBackgroundColor() const  { return mRight.back_color; }
 
  ///<summary>Get the foreground color for the right side.</summary>
  ///<returns>Returns the foreground color for the right side.</returns>
  const std::string & getRightForegroundColor() const  { return mRight.front_color; }
 
 ///<summary>Get the padding space in pixels left of the text for the right side.</summary>
  ///<returns>Returns the padding space in pixels left of the text for the right side.</returns>
  int getRightTextLeftPadding() const                  { return mRight.text_left_padding; }
 
  ///<summary>Get the padding space in pixels right of the text for the right side.</summary>
  ///<returns>Returns the padding space in pixels right of the text for the right side.</returns>
  int getRightTextRightPadding() const                 { return mRight.text_right_padding; }
 
  //whole side getters
 
  ///<summary>Get all the properties of the left side.</summary>
  ///<returns>Returns all the properties of the left side.</returns>
  const SIDE_PROPERTIES & getLeftSide() const         { return mLeft; }
 
  ///<summary>Get all the properties of the left side.</summary>
  ///<returns>Returns all the properties of the left side.</returns>
  SIDE_PROPERTIES & getLeftSide()                     { return mLeft; }
 
  ///<summary>Get all the properties of the right side.</summary>
  ///<returns>Returns all the properties of the right side.</returns>
  const SIDE_PROPERTIES & getRightSide() const        { return mRight; }
 
  ///<summary>Get all the properties of the right side.</summary>
  ///<returns>Returns all the properties of the right side.</returns>
  SIDE_PROPERTIES & getRightSide()                    { return mRight; }

private:
  int mHeight;
  std::string mIcon;
  SIDE_PROPERTIES mLeft;
  SIDE_PROPERTIES mRight;
};
