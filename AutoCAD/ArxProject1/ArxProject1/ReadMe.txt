
ArxAppWizard has created this ArxProject1 application for you.
  You can get regular updates for the Wizards at http://www.autodesk.com/developautocad
  and report issues at: oarxwiz-feedback@autodesk.com

This project uses the ObjectARX SDK .props file from the ObjectARX SDK to set the C++ compiler, MIDL, 
and Linker options appropriately. The project .props file is located in your project directory and reference
the ObjectARX SDK and AutoCAD executable paths.
To create a new configuration and/or change the paths references copy or modify the Autodesk.arx-2025.props
File, like this:
  #7 	<AcadDir Condition="'$(Platform)'=='x64'">[acad.exe path on your x64 windows platform]</AcadDir>
  #8	<ArxSdkDir>[the location you installed the ObjectARX SDK]</ArxSdkDir>
  
Note the Wizards installer also provided an ObjectARX 2025.props file for your convenience as example in
case you want to have multiple configuration (Checkout the Wizards install directory).
To undestand and use .props file, please visit the Microsoft WEB site at https://learn.microsoft.com/en-us/previous-versions/669zx6zc(v=vs.140)
and http://blogs.msdn.com/b/visualstudio/archive/2010/05/14/a-guide-to-vcxproj-and-props-file-structure.aspx
In Visual Studio 2022, the .props editor is in -> View -> Other Windows -> Property Manager

-----------------------------------------------------------------------------
StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ArxProject1.pch and a precompiled types file named StdAfx.obj.

	StdAfx.h either includes arxHeaders.h or dbxHeaders.h which includes all the ObjectARX or 
	RealDWG headers, uses #pragma to import the required .lib file and exports mandatory symbols.
