// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: InverseGhostZoneViewerEnginePluginInfo.C
// ****************************************************************************

#include <InverseGhostZonePluginInfo.h>
#include <InverseGhostZoneAttributes.h>

//
// Storage for static data elements.
//
InverseGhostZoneAttributes *InverseGhostZoneViewerEnginePluginInfo::clientAtts = NULL;
InverseGhostZoneAttributes *InverseGhostZoneViewerEnginePluginInfo::defaultAtts = NULL;

// ****************************************************************************
//  Method:  InverseGhostZoneViewerEnginePluginInfo::InitializeGlobalObjects
//
//  Purpose:
//    Initialize the operator atts.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
void
InverseGhostZoneViewerEnginePluginInfo::InitializeGlobalObjects()
{
    if (InverseGhostZoneViewerEnginePluginInfo::clientAtts == NULL)
    {
        InverseGhostZoneViewerEnginePluginInfo::clientAtts  = new InverseGhostZoneAttributes;
        InverseGhostZoneViewerEnginePluginInfo::defaultAtts = new InverseGhostZoneAttributes;
    }
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::GetClientAtts
//
//  Purpose:
//    Return a pointer to the viewer client attributes.
//
//  Returns:    A pointer to the viewer client attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
InverseGhostZoneViewerEnginePluginInfo::GetClientAtts()
{
    return clientAtts;
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::GetDefaultAtts
//
//  Purpose:
//    Return a pointer to the viewer default attributes.
//
//  Returns:    A pointer to the viewer default attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

AttributeSubject *
InverseGhostZoneViewerEnginePluginInfo::GetDefaultAtts()
{
    return defaultAtts;
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::SetClientAtts
//
//  Purpose:
//    Set the viewer client attributes.
//
//  Arguments:
//    atts      A pointer to the new client attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
InverseGhostZoneViewerEnginePluginInfo::SetClientAtts(AttributeSubject *atts)
{
    *clientAtts = *(InverseGhostZoneAttributes *)atts;
    clientAtts->Notify();
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::GetClientAtts
//
//  Purpose:
//    Get the viewer client attributes.
//
//  Arguments:
//    atts      A pointer to return the client default attributes in.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
InverseGhostZoneViewerEnginePluginInfo::GetClientAtts(AttributeSubject *atts)
{
    *(InverseGhostZoneAttributes *)atts = *clientAtts;
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::InitializeOperatorAtts
//
//  Purpose:
//    Initialize the operator attributes to the default attributes.
//
//  Arguments:
//    atts        The attribute subject to initialize.
//    plot        The viewer plot that owns the operator.
//    fromDefault True to initialize the attributes from the defaults. False
//                to initialize from the current attributes.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
InverseGhostZoneViewerEnginePluginInfo::InitializeOperatorAtts(AttributeSubject *atts,
                                              const avtPlotMetaData &plot,
                                              const bool fromDefault)
{
    if (fromDefault)
        *(InverseGhostZoneAttributes*)atts = *defaultAtts;
    else
        *(InverseGhostZoneAttributes*)atts = *clientAtts;

    UpdateOperatorAtts(atts, plot);
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::UpdateOperatorAtts
//
//  Purpose:
//    Update the operator attributes when using operator expressions.
//
//  Arguments:
//    atts        The attribute subject to update.
//    plot        The viewer plot that owns the operator.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

void
InverseGhostZoneViewerEnginePluginInfo::UpdateOperatorAtts(AttributeSubject *atts, const avtPlotMetaData &plot)
{
}

// ****************************************************************************
//  Method: InverseGhostZoneViewerEnginePluginInfo::GetMenuName
//
//  Purpose:
//    Return a pointer to the name to use in the viewer menus.
//
//  Returns:    A pointer to the name to use in the viewer menus.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

const char *
InverseGhostZoneViewerEnginePluginInfo::GetMenuName() const
{
    return "Inverse Ghost Zone";
}

