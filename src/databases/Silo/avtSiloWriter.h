/*****************************************************************************
*
* Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400142
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                             avtSiloWriter.h                               //
// ************************************************************************* //

#ifndef AVT_SILO_WRITER_H
#define AVT_SILO_WRITER_H

#include <avtDatabaseWriter.h>

#include <map>
#include <string>
#include <vector>

#include <silo.h>

using std::map;
using std::string;
using std::vector;

class vtkCellData;
class vtkPointData;
class vtkPolyData;
class vtkRectilinearGrid;
class vtkStructuredGrid;
class vtkUnstructuredGrid;

class avtMeshMetaData;

class DBOptionsAttributes;

// ****************************************************************************
//  Class: avtSiloWriter
//
//  Purpose:
//      A module that writes out Silo files.
//
//  Programmer: Hank Childs
//  Creation:   September 11, 2003
//
//  Modifications
//    Mark C. Miller, Tue Mar  9 07:03:56 PST 2004
//    Added data members to hold args passed in WriteHeaders to facilitate
//    writing extents on multi-objects in CloseFile()
//
//    Hank Childs, Tue Sep 27 10:21:36 PDT 2005
//    Use virtual inheritance.
//
//    Jeremy Meredith, Tue Mar 27 11:39:24 EDT 2007
//    Added numblocks to the OpenFile method, and save off the actual
//    encountered mesh types, because we cannot trust the metadata.
//
//    Cyrus Harrison, Thu Aug 16 20:50:24 PDT 2007
//    Added dir to hold output directory.
//
// ****************************************************************************

class
avtSiloWriter : public virtual avtDatabaseWriter
{
  public:
                   avtSiloWriter(DBOptionsAttributes *);
    virtual       ~avtSiloWriter();

  protected:
    string         stem;
    string         dir;
    string         meshname;
    string         matname;
    int            nblocks;
    int            driver;
    avtMeshType    meshtype;
    DBoptlist     *optlist;

    // places to hold args passed in WriteHeaders
    const avtDatabaseMetaData *headerDbMd;
    vector<string>             headerScalars;
    vector<string>             headerVectors;
    vector<string>             headerMaterials;

    // storage for per-block info to be written in DBPutMulti... calls 
    vector<double>               spatialMins;
    vector<double>               spatialMaxs;
    vector<int>                  zoneCounts;
    map<string,vector<double> > dataMins;
    map<string,vector<double> > dataMaxs;

    virtual bool   CanHandleMaterials(void) { return true; };

    virtual void   OpenFile(const string &, int);
    virtual void   WriteHeaders(const avtDatabaseMetaData *,
                                vector<string> &, 
                                vector<string> &,
                                vector<string> &);
    virtual void   WriteChunk(vtkDataSet *, int);
    virtual void   CloseFile(void);

    void           ConstructMultimesh(DBfile *dbfile, const avtMeshMetaData *);
    void           ConstructMultivar(DBfile *dbfile, const string &,
                                     const avtMeshMetaData *);
    void           ConstructMultimat(DBfile *dbfile, const string &,
                                     const avtMeshMetaData *);
    void           ConstructChunkOptlist(const avtDatabaseMetaData *);

    void           WriteCurvilinearMesh(DBfile *, vtkStructuredGrid *, int);
    void           WritePolygonalMesh(DBfile *, vtkPolyData *, int);
    void           WriteRectilinearMesh(DBfile *, vtkRectilinearGrid *, int);
    void           WriteUnstructuredMesh(DBfile *, vtkUnstructuredGrid *, int);

    void           WriteUcdvars(DBfile *, vtkPointData *, vtkCellData *);
    void           WriteQuadvars(DBfile *, vtkPointData *, vtkCellData *,
                                    int, int *);
    void           WriteMaterials(DBfile *, vtkCellData *, int);
};


#endif


