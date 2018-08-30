#include "ImageListBuilder.h"

ImageListBuilder::ImageListBuilder()
{
}

ImageListBuilder::~ImageListBuilder()
{
}

bool ImageListBuilder::save(const std::string & iFilePath)
{
  FILE * f = fopen(iFilePath.c_str(), "w");
  if (!f)
    return false;

  //print header
  fputs(""
"<html>\n"
"<head></head>\n"
"<body>\n"
"  <table>\n"
"    <tbody>\n"
"      <td>File</td>\n"
"      <td>Image</td>\n"
"    </tbody>\n"
, f);

  for(size_t i=0; i<mImageFiles.size(); i++)
  {
    const std::string & imageFile = mImageFiles[i];
    fprintf(f, "    <tr><td><a href=\"%s\">%s</a></td><td><img src=\"%s\" /></td></tr>\n", imageFile.c_str(), imageFile.c_str(), imageFile.c_str());
  }

  //print footer
  fputs(""
"  </table>\n"
"</body>\n"
"</html>\n"
, f);

  fclose(f);

  return true;
}

void ImageListBuilder::addImage(const std::string & iFilePath)
{
  mImageFiles.push_back(iFilePath);
}
