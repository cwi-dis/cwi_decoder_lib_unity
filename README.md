# Copyright (c) 2017-, Stichting Centrum Wiskunde en Informatica (CWI).

cwi-pcl-codec
=============

This distribution contains a codec for encoding/decoding 3D Point Cloud data streams, and a toolset for its objective evaluation.   
The codec is described in detail in a journal paper(R. Mekuria, K. Blom, and P. Cesar, "Design, Implementation and Evaluation of a Point Cloud Codec for Tele-Immersive Video," IEEE Transactions on Circuits and Systems for Video Technology, 27(4): 828 -842, 2017, of which a preprint is available at: https://ir.cwi.nl/pub/24395.   
The codec has served as the software to generate the anchors for the Call for Proposals for Point Cloud Compression by  the MPEG working group 3DG-PCC on PointCloud Compression
(http://mpeg.chiariglione.org/standards/exploration/point-cloud-compression).

This version can be build on  Ubuntu 16.04 (64 bit) or Windows 32 bit, using pre-build PointCloudLibrary(PCL)
installers, or on many other systems by downloading and building PCL and its dependencies.

This package contains:

* codec software (cloud_codec_v2)
* auxiliary files needed (for using 'cmake'  and building 'jpeg_io')
* quality metrics
* evaluation library
* tools for testing and evaluation of several aspects of this codec
* installation instruction
* a codec DLL

To use it, several dependencies (Boost,Eigen,Flann,QHull,VTK and libjpeg-turbo) need to be installed:  

 * for Ubuntu 16.04 by installing a number of Debian packages
* for Windows 7,8 and 10, most of this can be done using an all-in-one installer
* for all other supported systems by downloading, building and installing PCL 
  and its necessary Third Party Package (TPP's) as described at:
  http://pointclouds.org/downloads -> 'Compiling from source'.

Installation
============

Installation
PointCLoudLibrary PCL-1.8.1 and liblpeg-turbo:
To build the package 'cwi-pcl-codec', first the Point Cloud Library (PCL) (http://pointclouds.org) its dependencies and libjpeg-turbo need to be installed:

for Ubuntu 18.04 by installing 2 Debian packages ('gcc', 'cmake' and 'make' required):
libpcl-dev and libturbojpeg0-dev using the package manger 'synaptic'

for Windows 8 and 10 with VisualStudio 2015/2017, use the all-in-one installer for PCL-1.8.1 for your system
and Visual Studio version available at: http://unanancyowen.com/en/pcl181/. Make sure you also set the System Environment Variable 'PCL_ROOT' en 'PATH' as detailed at the download webrite !
In addition, get and install 'libjpeg-turbo', from 'libjpeg-turbo.org'

For MacOS 10.13.8 High Sierra type in a terminal window: brew install jpeg-turbo pcl

for all other supported systems by downloading, building and installing PCL and its necessary Third Party Package (TPP's: Boost,Eigen,Flann,QHull,VTK and libjpeg-turbo) as described at:
http://pointclouds.org/downloads -> 'Compiling from source'.

Ubuntu 18.04 Build & Install:
Start 'cmake-gui (>= 3.10)', specify the directory where this file is located in 'Where is the source code', another empty directory 'Where to build the binaries', and select 'Unix Makefiles' in the 'CMakeSetup' pop-up window. Click(tap) 'Configure', and 'Generate'.
Now the codec libraries and evaluation tools can be build by typing 'make' in the directory that was specified in 'cmake-gui' to build the binaries.

Windows 8,10 Build & Install:
Install 'Visual Studio (2015 or 2017)' and 'cmake-gui'
Download source tarball for 'libjpeg-turbo' from 'www.libjpeg-turbo.org':
https://sourceforge.net/projects/libjpeg-turbo/files/1.5.3/libjpeg-turbo-1.5.3.tar.gz/download
Unpack the tarball and start 'cmake_gui', select for 'source code' directory the top-level directory
of 'libturbo-jpeg' (contains 'CMakelists.txt'), and for 'binaries' another directory, click 'Configure' and 'Generate'.
Now in your 'binaries' directory open the file 'libjpeg-turbo-1.5.3.sln' with Visual Studio 2015.
In the Solution Explorer click Project 'INSTALL'. Select Build->Build Solution, if this is successful select 'Build->Build INSTALL'. By default this installs the include files and libraries libraries in 'C:\libjpeg-turbo\include' and 'C:\libjpeg-turbo\lib'

Next start 'cmake-gui', select for 'source code' the directory 'cwi-pcl-codec' (where this file INSTALL.md is located), and for 'binaries' another (empty) directory

For JPEG_INCLUDES specify 'C:/libjpeg-turbo/include' and for 'JPEG_LIBRARY'
'C:/libjpeg-turbo/lib/turbojpeg-static.lib'. Next select 'Configure' and 'Generate', and you'll find a Microsoft Visual Studio Solution
in the directory that was specified for 'binaries'.

Start Visual Studio with the 'Solution' file created in the previous paragraph and select 'Build->Build Solution'.

After successful building, the program 'evaluate_compression.exe' can be found in the directory:
'binaries'\apps\evaluate_compression\Debug.
Before running, adapt the following environment variable:
set path=%path%;C:\libjpeg-turbo-gcc\bin;C:\Program Files (x86)\OpenNI2\Tools

Suitable input files for the program can be downloaded from: http://vcl.iti.gr/reconstruction/ Most of these data sets are huge; unpack some and specify the full directory path as an argument to the program: evaluate_compression --input_directories=

Other platforms: install PCL 1.8.1 from source:
Get PCL source code from 'https://github.com/PointCloudLibrary/pcl/releases/tag/pcl-1.8.1' (note that the source code in the PCL development tree is not compatible with this package).

Get 3rd party packages: follow the instructions in: http://pointclouds.org/documentation/tutorials/compiling_pcl_dependencies_windows.php or http://pointclouds.org/documentation/tutorials/compiling_pcl_macosx.php#compiling-pcl-macosx Be aware that the version numbers of some 3rd party packages are outdated and should match those used in the 'apt-install' commands above.

Use 'cmake-gui (>= 3.10)' to configure and generate the files for building each of the additional libraries and excutables in these package; build and install each of the libraries using the build system selected by 'cmake'

Use 'cmake-gui (>= 3.10)' to configure and generate the files for building PCL; build and install the libraries using the build system selected by 'cmake'

Download libjpeg-turbo https://sourceforge.net/projects/libjpeg-turbo/files/1.5.3/libjpeg-turbo-1.5.3.tar.gz/download Use: 'configure; make install' to install the libraries

Use 'cmake-gui (>= 3.10)' to configure and generate the files for building cwi-pcl-codec; build and install the libraries using the build system selected by 'cmake'


Running the evaluation program
==============================

The following arguments are recognized by the program 'evaluate_compression':  
(long version arguments without '--' can also be put in a file 'parameter_config.txt' in the working directory or its parent)

  -h [ --help ]                         produce help message  
  -K [ --K_outlier_filter ] arg (=0)    K neighbours for radius outlier filter   
  --radius arg (=0.01)                  radius outlier filter, maximum radius  
  -g [ --group_size ] arg (=0)          maximum number of files to be compressed together (0=read all files, then en(de)code 1 by 1)  
  -f [ --bb_expand_factor ] arg (=0.2)  bounding box expansion to keep bounding box equal accross frames  
  -a [ --algorithm ] arg (=V2)          compression algorithm ('V1' or 'V2')  
  -i [ --input_directories ] arg        Directory containing supported files (.pcd or .ply)  
  -o [ --output_directory ] arg         Directory to store decompressed pointclouds (.ply)  
  -s [ --show_statistics ] [=arg(=1)] (=0) gather and show a bunch of releavant statistical data  
  -v [ --visualization ] [=arg(=1)] (=0) show both original and decoded PointClouds graphically  
  -p [ --point_resolution ] arg (=0.2)  XYZ resolution of point coordinates  
  -r [ --octree_resolution ] arg (=0.2) voxel size  
  -b [ --octree_bits ] arg (=11)        octree resolution (bits)  
  -c [ --color_bits ] arg (=8)          color resolution (bits)  
  -e [ --enh_bits ] arg (=0)            bits to code the points towards the center  
  -t [ --color_coding_type ] arg (=1)   pcl=0,jpeg=1 or graph transform  
  -m [ --macroblock_size ] arg (=16)    size of macroblocks used for predictive frame (has to be a power of 2)  
  --keep_centroid  arg (=0)             keep voxel grid positions or not  
  --create_scalable arg (=0)            create scalable bitstream (not yet implemented)  
  --do_connectivity_coding arg (=0)     connectivity coding (not yet implemented)  
  --icp_on_original arg (=0)            icp_on_original  
  -q [ --jpeg_quality ] arg (=0)        jpeg quality parameter  
  -d [ --do_delta_coding ] arg (=0)     use delta (predictive) en(de)coding  
  --do_quality_computation arg (=0)     compute quality of en(de)coding  
  --do_icp_color_offset arg (=0)        do color offset en(de)coding on predictive frames  
  -j [ --num_threads ] arg (=1)         number of parallel threads (1=default, single  thread, no parallel execution)  
  --intra_frame_quality_csv arg (=intra_frame_quality.csv) intra frame coding quality results filename (.csv file)  
  --predictive_quality_csv arg (=predictive_quality.csv) predictive coding quality results file name (.csv file)  
  --debug_level arg (=0)                debug print level (0=no debug print, 3=all debug print)  

The precise meanings of these parameters are explained in the journal paper mentioned above.

Functions exported by the DLL
=============================

extern "C" __declspec(dllexport) MyPointCloud Cwi_decoder(unsigned char * compFrame)
Decompress a point ploud passed as a bytestream without name mangling

The point cloud is returned in the following structure:
struct MyPoint
{
	float x;
	float y;
	float z;
	INT8 r;
	INT8 g;
	INT8 b;
};


struct MyPointCloud
{
	MyPoint pointcloud[921600];
	int size;
	uint64_t timeStamp;
};

MyPointCloud includes the capture timestamp from the point cloud header

Apr.6, 2017, updated: Jun 25, 2017 and Apr. 23, 2018.   
Kees Blom (Kees.Blom@cwi.nl) CWI, Amsterdam, The Netherlands


