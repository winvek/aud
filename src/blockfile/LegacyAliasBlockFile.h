/**********************************************************************

  Audacity: A Digital Audio Editor

  LegacyAliasBlockFile.h

  Dominic Mazzoni

**********************************************************************/

#ifndef __AUDACITY_LEGACYALIASBLOCKFILE__
#define __AUDACITY_LEGACYALIASBLOCKFILE__

#include "../BlockFile.h"
#include "PCMAliasBlockFile.h"

/// An AliasBlockFile that references uncompressed data in an existing file
class LegacyAliasBlockFile final : public PCMAliasBlockFile
{
 public:

   // Constructor / Destructor

   /// Constructs a LegacyAliasBlockFile, writing the summary to disk
   LegacyAliasBlockFile(wxFileNameWrapper &&fileName,
                        wxFileNameWrapper &&aliasedFileName,
                        sampleCount aliasStart,
                        sampleCount aliasLen,
                        int aliasChannel,
                        sampleCount summaryLen,
                        bool noRMS);
   virtual ~LegacyAliasBlockFile();

   void SaveXML(XMLWriter &xmlFile) override;
   BlockFilePtr Copy(wxFileNameWrapper &&fileName) override;
   void Recover() override;

   static BlockFilePtr BuildFromXML(const wxString &projDir, const wxChar **attrs);
};

#endif
