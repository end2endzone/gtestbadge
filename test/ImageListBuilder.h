#include <string>
#include <vector>

class ImageListBuilder
{
public:
  ImageListBuilder();
  virtual ~ImageListBuilder();

  ///<summary>build an HTML file viewer</summary>
  ///<param name="iFilePath">The path of the HTML file to generate</param>
  bool save(const std::string & iFilePath);

  ///<summary>Add an image file to the builder</summary>
  ///<param name="iFilePath">The path of the image file to add to the builder</param>
  void addImage(const std::string & iFilePath);

private:
  std::vector<std::string> mImageFiles;
};
