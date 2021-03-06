// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <GetPluginErrorsRPC.h>
#include <DebugStream.h>
#include <string>

using std::string;

// *******************************************************************
// Method: GetPluginErrorsRPC::GetPluginErrorsRPC
//
// Purpose: 
//   Constructor for the GetPluginErrorsRPC class.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//
// *******************************************************************

GetPluginErrorsRPC::GetPluginErrorsRPC() : BlockingRPC("", &errors), errors()
{
}

// *******************************************************************
// Method: GetPluginErrorsRPC::~GetPluginErrorsRPC
//
// Purpose: 
//   Destructor for the GetPluginErrorsRPC class.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//
// *******************************************************************

GetPluginErrorsRPC::~GetPluginErrorsRPC()
{
}

// *******************************************************************
// Method: GetPluginErrorsRPC::operator()
//
// Purpose: 
//   Executes the RPC and returns the plugin errors.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//
// *******************************************************************

string
GetPluginErrorsRPC::operator()()
{
    debug3 << "Executing GetPluginErrorsRPC RPC\n";

    Execute();
    return errors.errorString;
}

// *******************************************************************
// Method: GetPluginErrorsRPC::SelectAll
//
// Purpose: 
//   Selects all the attributes that comprise the RPC's parameter list.
//
// Notes:
//   This RPC has no parameters so the no attributes are selected.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//
// *******************************************************************

void
GetPluginErrorsRPC::SelectAll()
{
    // no data sent
}

// ****************************************************************************
// Method: GetPluginErrorsRPC::TypeName
//
// Purpose: 
//   Returns the RPC name.
//
// Programmer: Brad Whitlock
// Creation:   Fri Dec  7 11:09:23 PST 2007
//
// Modifications:
//   
// ****************************************************************************

const std::string
GetPluginErrorsRPC::TypeName() const
{
    return "GetPluginErrorsRPC";
}

// *******************************************************************
// Method: GetPluginErrorsRPC::PluginErrors::PluginErrors
//
// Purpose: 
//   Constructor for the GetPluginErrorsRPC::PluginErrors class.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//   
// *******************************************************************

GetPluginErrorsRPC::PluginErrors::PluginErrors() : AttributeSubject("s"),
    errorString()
{
}

// *******************************************************************
// Method: GetPluginErrorsRPC::PluginErrors::~PluginErrors
//
// Purpose: 
//   Destructor for the GetPluginErrorsRPC::PluginErrors class.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//   
// *******************************************************************

GetPluginErrorsRPC::PluginErrors::~PluginErrors()
{
}

// *******************************************************************
// Method: GetPluginErrorsRPC::PluginErrors::SelectAll
//
// Purpose: 
//   Selects all the attributes in the object.
//
// Programmer: Jeremy Meredith
// Creation:   February  7, 2005
//
// Modifications:
//   
// *******************************************************************

void
GetPluginErrorsRPC::PluginErrors::SelectAll()
{
    Select(0, (void *)&errorString);
}

// ****************************************************************************
// Method: GetPluginErrorsRPC::PluginErrors::TypeName
//
// Purpose: 
//   Returns the RPC name.
//
// Programmer: Brad Whitlock
// Creation:   Fri Dec  7 11:09:23 PST 2007
//
// Modifications:
//   
// ****************************************************************************

const std::string
GetPluginErrorsRPC::PluginErrors::TypeName() const
{
    return "GetPluginErrorsRPC::PluginErrors";
}
