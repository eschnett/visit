// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <MOABPluginInfo.h>
#include <avtMOABWriter.h>

VISIT_DATABASE_PLUGIN_ENTRY(MOAB,Engine)

// ****************************************************************************
//  Method: MOABEnginePluginInfo::GetWriter
//
//  Purpose:
//      Sets up a MOAB writer.
//
//  Returns:    A MOAB writer.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
avtDatabaseWriter *
MOABEnginePluginInfo::GetWriter(void)
{
    return new avtMOABWriter(writeOptions);
}

