// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                         avtExtrudedVolFileFormat.h                        //
// ************************************************************************* //

#ifndef AVT_ExtrudedVol_FILE_FORMAT_H
#define AVT_ExtrudedVol_FILE_FORMAT_H

#include <avtSTMDFileFormat.h>

#include <vector>
#include <string>

class DBOptionsAttributes;


// ****************************************************************************
//  Class: avtExtrudedVolFileFormat
//
//  Purpose:
//      Reads in ExtrudedVol files as a plugin to VisIt.
//
//  Programmer: childs -- generated by xml2avt
//  Creation:   Fri May 18 17:52:04 PST 2007
//
// ****************************************************************************

class avtExtrudedVolFileFormat : public avtSTMDFileFormat
{
  public:
                       avtExtrudedVolFileFormat(const char *, 
                                                DBOptionsAttributes *);
    virtual           ~avtExtrudedVolFileFormat() {;};

    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, int domain,
    //                                     const char *type, void *args, 
    //                                     DestructorFunction &);
    //

    //
    // If you know the cycle number, overload this function.
    // Otherwise, VisIt will make up a reasonable one for you.
    //
    // virtual int         GetCyle(void);
    //

    virtual const char    *GetType(void)   { return "ExtrudedVol"; };
    virtual void           FreeUpResources(void); 

    virtual vtkDataSet    *GetMesh(int, const char *);
    virtual vtkDataArray  *GetVar(int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, const char *);

  protected:
    std::string              stem;
    int                      nTimesteps;
    int                      numChunks;
    std::vector<std::string> variables;

    virtual void           PopulateDatabaseMetaData(avtDatabaseMetaData *);
};


#endif
