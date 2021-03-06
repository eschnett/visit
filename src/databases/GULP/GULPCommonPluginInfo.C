// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <GULPPluginInfo.h>
#include <avtGULPFileFormat.h>
#include <avtMTSDFileFormatInterface.h>
#include <avtGenericDatabase.h>

// ****************************************************************************
//  Method:  GULPCommonPluginInfo::GetDatabaseType
//
//  Purpose:
//    Returns the type of a GULP database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
DatabaseType
GULPCommonPluginInfo::GetDatabaseType()
{
    return DB_TYPE_MTSD;
}

// ****************************************************************************
//  Method: GULPCommonPluginInfo::SetupDatabase
//
//  Purpose:
//      Sets up a GULP database.
//
//  Arguments:
//      list    A list of file names.
//      nList   The number of timesteps in list.
//      nBlocks The number of blocks in the list.
//
//  Returns:    A GULP database from list.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
avtDatabase *
GULPCommonPluginInfo::SetupDatabase(const char *const *list,
                                   int nList, int nBlock)
{
    int nTimestepGroups = nList / nBlock;
    avtMTSDFileFormat ***ffl = new avtMTSDFileFormat**[nTimestepGroups];
    for (int i = 0; i < nTimestepGroups; i++)
    {
        ffl[i] = new avtMTSDFileFormat*[nBlock];
        for (int j = 0; j < nBlock; j++)
        {
            ffl[i][j] = new avtGULPFileFormat(list[i*nBlock + j]);
        }
    }
    avtMTSDFileFormatInterface *inter
           = new avtMTSDFileFormatInterface(ffl, nTimestepGroups, nBlock);
    return new avtGenericDatabase(inter);
}
