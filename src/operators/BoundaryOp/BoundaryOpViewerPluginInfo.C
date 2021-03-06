// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: BoundaryOpViewerPluginInfo.C
// ****************************************************************************

#include <BoundaryOpPluginInfo.h>
#include <BoundaryOpAttributes.h>

VISIT_OPERATOR_PLUGIN_ENTRY_EV(BoundaryOp,Viewer)


// ****************************************************************************
//  Method: BoundaryOpViewerPluginInfo::XPMIconData
//
//  Purpose:
//    Return a pointer to the icon data.
//
//  Returns:    A pointer to the icon data.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

#include <BoundaryOp.xpm>
const char **
BoundaryOpViewerPluginInfo::XPMIconData() const
{
    return BoundaryOp_xpm;
}

