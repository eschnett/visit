// ****************************************************************************
//                               Boxlib2DPluginInfo.h
// ****************************************************************************

#ifndef BOXLIB2D_PLUGIN_INFO_H
#define BOXLIB2D_PLUGIN_INFO_H
#include <DatabasePluginInfo.h>
#include <database_plugin_exports.h>

class avtDatabase;

// ****************************************************************************
//  Class: Boxlib2DDatabasePluginInfo
//
//  Purpose:
//    Classes that provide all the information about the Boxlib2D plugin.
//    Portions are separated into pieces relevant to the appropriate
//    components of VisIt.
//
//  Programmer: haddox1 -- generated by xml2info
//  Creation:   Fri Aug 8 10:55:10 PDT 2003
//
//  Modifications:
//
// ****************************************************************************

class Boxlib2DGeneralPluginInfo : public virtual GeneralDatabasePluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
};

class Boxlib2DCommonPluginInfo : public virtual CommonDatabasePluginInfo, public virtual Boxlib2DGeneralPluginInfo
{
  public:
    virtual DatabaseType              GetDatabaseType();
    virtual std::vector<std::string>  GetDefaultExtensions();
    virtual avtDatabase              *SetupDatabase(const char * const *list,
                                                    int nList, int nBlock);
};

class Boxlib2DMDServerPluginInfo : public virtual MDServerDatabasePluginInfo, public virtual Boxlib2DCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

class Boxlib2DEnginePluginInfo : public virtual EngineDatabasePluginInfo, public virtual Boxlib2DCommonPluginInfo
{
  public:
    // this makes compilers happy... remove if we ever have functions here
    virtual void dummy();
};

#endif
