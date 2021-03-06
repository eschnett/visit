// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef DBPLUGININFOATTRIBUTES_H
#define DBPLUGININFOATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

class DBOptionsAttributes;
class DBOptionsAttributes;

// ****************************************************************************
// Class: DBPluginInfoAttributes
//
// Purpose:
//    This class contains the attributes for all the database plugins.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

class STATE_API DBPluginInfoAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    DBPluginInfoAttributes();
    DBPluginInfoAttributes(const DBPluginInfoAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    DBPluginInfoAttributes(private_tmfs_t tmfs);
    DBPluginInfoAttributes(const DBPluginInfoAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~DBPluginInfoAttributes();

    virtual DBPluginInfoAttributes& operator = (const DBPluginInfoAttributes &obj);
    virtual bool operator == (const DBPluginInfoAttributes &obj) const;
    virtual bool operator != (const DBPluginInfoAttributes &obj) const;
private:
    void Init();
    void Copy(const DBPluginInfoAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectTypes();
    void SelectHasWriter();
    void SelectDbReadOptions();
    void SelectDbWriteOptions();
    void SelectTypesFullNames();
    void SelectLicense();
    void SelectHost();

    // Property setting methods
    void SetTypes(const stringVector &types_);
    void SetHasWriter(const intVector &hasWriter_);
    void SetTypesFullNames(const stringVector &typesFullNames_);
    void SetLicense(const stringVector &license_);
    void SetHost(const std::string &host_);

    // Property getting methods
    const stringVector &GetTypes() const;
          stringVector &GetTypes();
    const intVector    &GetHasWriter() const;
          intVector    &GetHasWriter();
    const AttributeGroupVector &GetDbReadOptions() const;
          AttributeGroupVector &GetDbReadOptions();
    const AttributeGroupVector &GetDbWriteOptions() const;
          AttributeGroupVector &GetDbWriteOptions();
    const stringVector &GetTypesFullNames() const;
          stringVector &GetTypesFullNames();
    const stringVector &GetLicense() const;
          stringVector &GetLicense();
    const std::string  &GetHost() const;
          std::string  &GetHost();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Attributegroup convenience methods
    void AddDbReadOptions(const DBOptionsAttributes &);
    void ClearDbReadOptions();
    void RemoveDbReadOptions(int i);
    int  GetNumDbReadOptions() const;
    DBOptionsAttributes &GetDbReadOptions(int i);
    const DBOptionsAttributes &GetDbReadOptions(int i) const;

    void AddDbWriteOptions(const DBOptionsAttributes &);
    void ClearDbWriteOptions();
    void RemoveDbWriteOptions(int i);
    int  GetNumDbWriteOptions() const;
    DBOptionsAttributes &GetDbWriteOptions(int i);
    const DBOptionsAttributes &GetDbWriteOptions(int i) const;


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_types = 0,
        ID_hasWriter,
        ID_dbReadOptions,
        ID_dbWriteOptions,
        ID_typesFullNames,
        ID_license,
        ID_host,
        ID__LAST
    };

protected:
    AttributeGroup *CreateSubAttributeGroup(int index);
private:
    stringVector         types;
    intVector            hasWriter;
    AttributeGroupVector dbReadOptions;
    AttributeGroupVector dbWriteOptions;
    stringVector         typesFullNames;
    stringVector         license;
    std::string          host;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define DBPLUGININFOATTRIBUTES_TMFS "s*i*a*a*s*s*s"

#endif
