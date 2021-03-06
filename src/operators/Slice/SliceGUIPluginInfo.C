// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: SliceGUIPluginInfo.C
// ****************************************************************************

#include <SlicePluginInfo.h>
#include <SliceAttributes.h>
#include <QApplication>
#include <QvisSliceWindow.h>

VISIT_OPERATOR_PLUGIN_ENTRY(Slice,GUI)

// ****************************************************************************
//  Method: SliceGUIPluginInfo::GetMenuName
//
//  Purpose:
//    Return a pointer to the name to use in the GUI menu.
//
//  Returns:    A pointer to the name to use in the GUI menu.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QString *
SliceGUIPluginInfo::GetMenuName() const
{
    return new QString(qApp->translate("OperatorNames", "Slice"));
}


// ****************************************************************************
//  Method: SliceGUIPluginInfo::CreatePluginWindow
//
//  Purpose:
//    Return a pointer to an operator's attribute window.
//
//  Arguments:
//    type      The type of the operator.
//    attr      The attribute subject for the operator.
//    notepad   The notepad to use for posting the window.
//
//  Returns:    A pointer to the operator's attribute window.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

QvisPostableWindowObserver *
SliceGUIPluginInfo::CreatePluginWindow(int type, AttributeSubject *attr,
    const QString &caption, const QString &shortName, QvisNotepadArea *notepad)
{
    return new QvisSliceWindow(type, (SliceAttributes *)attr,
        caption, shortName, notepad);
}

// ****************************************************************************
//  Method: SliceGUIPluginInfo::XPMIconData
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

#include <Slice.xpm>
const char **
SliceGUIPluginInfo::XPMIconData() const
{
    return Slice_xpm;
}

