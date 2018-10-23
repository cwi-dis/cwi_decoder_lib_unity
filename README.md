> Copyright (c) 2017-, Stichting Centrum Wiskunde en Informatica (CWI).

# cwi-pcl-codec

This distribution contains a codec for encoding/decoding 3D Point Cloud data streams, and a toolset for its objective evaluation.   
The codec is described in detail in a journal paper:
> _(R. Mekuria, K. Blom, and P. Cesar, "Design, Implementation and Evaluation of a Point Cloud Codec for Tele-Immersive Video," IEEE Transactions on Circuits and Systems for Video Technology, 27(4): 828 -842, 2017_

of which a preprint is available at: <https://ir.cwi.nl/pub/24395>.   

The codec has served as the software to generate the anchors for the Call for Proposals for Point Cloud Compression by  the MPEG working group 3DG-PCC on PointCloud Compression
<http://mpeg.chiariglione.org/standards/exploration/point-cloud-compression>.

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

To use it, several dependencies need to be installed:  

* Boost
* Eigen
* Flann
* QHull
* VTK
* libjpeg-turbo

## Installation

### Installation of PointCLoudLibrary PCL-1.8.1 and libjpeg-turbo

To build the package _cwi-pcl-codec_, first the Point Cloud Library (PCL) <http://pointclouds.org> its dependencies and libjpeg-turbo need to be installed:

* for Ubuntu 18.04 by installing 2 Debian packages ('gcc', 'cmake' and 'make' required):
_libpcl-dev_ and _libturbojpeg0-dev_ using the package manger 'synaptic'

* for Windows 8 and 10 with VisualStudio 2015/2017, use the all-in-one installer for PCL-1.8.1 for your system
and Visual Studio version available at: <http://unanancyowen.com/en/pcl181/>. Make sure you also set the System Environment Variable `PCL_ROOT` en `PATH` as detailed at the download website!
In addition, get and install _libjpeg-turbo_, from <http://libjpeg-turbo.org>.

* For MacOS 10.13.8 High Sierra type in a terminal window: 
```
brew install jpeg-turbo pcl
```

For all other supported systems by downloading, building and installing PCL and its necessary Third Party Package (TPP's: Boost,Eigen,Flann,QHull,VTK and libjpeg-turbo) as described at:
<http://pointclouds.org/downloads>, section _Compiling from source_.



### Ubuntu 18.04 Build & Install

* Start `cmake-gui` (>= 3.10), 
* specify the directory where this file is located in _Where is the source code_, 
* another empty directory _Where to build the binaries_
* select _Unix Makefiles_ in the _CMakeSetup_ pop-up window. 
* Click _Configure_, and _Generate_.

Now the codec libraries and evaluation tools can be build by typing `make` in the directory that was specified in `cmake-gui` to build the binaries.

###Windows 8,10 Build & Install

* Install _Visual Studio_ (2015 or 2017)
* Install _cmake-gui_
* Download source tarball for [libjpeg-turbo](www.libjpeg-turbo.org) from <https://sourceforge.net/projects/libjpeg-turbo/files/1.5.3/libjpeg-turbo-1.5.3.tar.gz/download>
* Unpack the tarball and start `cmake_gui`
* select for _source code_ directory the top-level directoryof _libturbo-jpeg_ (contains `CMakelists.txt`)
* select for _binaries_ another directory
* click _Configure_ and _Generate_.
* Now in your _binaries_ directory open the file `libjpeg-turbo-1.5.3.sln` with Visual Studio 2015.
* In the Solution Explorer click Project `INSTALL`. 
* Select _Build_->_Build Solution_
* if this is successful select _Build_->_Build INSTALL_. By default this installs the include files and libraries libraries in `C:\libjpeg-turbo\include` and `C:\libjpeg-turbo\lib`

Now build the codec itself.

* start `cmake-gui`
* select for _source code_ the directory _cwi-pcl-codec_ (where this file `INSTALL.md is` located), and for _binaries_ another (empty) directory.
* For `JPEG_INCLUDES` specify `C:/libjpeg-turbo/include`
* * and for `JPEG_LIBRARY`
select `C:/libjpeg-turbo/lib/turbojpeg-static.lib`. * Next select _Configure_ and _Generate_, and you'll find a Microsoft Visual Studio Solution
in the directory that was specified for _binaries_.
* Start Visual Studio with the Solution file created in the previous paragraph
*  select _Build_->_Build Solution_.

After successful building, the program `evaluate_compression.exe` can be found in the directory
_binaries_`\apps\evaluate_compression\Debug`.
Before running, adapt the following environment variable:

```
set path=%path%;C:\libjpeg-turbo-gcc\bin;C:\Program Files (x86)\OpenNI2\Tools
```

Suitable input files for the program can be downloaded from: <http://vcl.iti.gr/reconstruction/> Most of these data sets are huge; unpack some and specify the full directory path as an argument to the program: 

```
evaluate_compression --input_directories=...
```

### Other platforms: 

* install PCL 1.8.1 from source:
Get PCL source code from <https://github.com/PointCloudLibrary/pcl/releases/tag/pcl-1.8.1> (note that the source code in the PCL development tree is not compatible with this package).
* Get 3rd party packages: follow the instructions in: <http://pointclouds.org/documentation/tutorials/compiling_pcl_dependencies_windows.php> or <http://pointclouds.org/documentation/tutorials/compiling_pcl_macosx.php#compiling-pcl-macosx>
*  Be aware that the version numbers of some 3rd party packages are outdated and should match those used in the `apt-install` commands above.
 
* Use `cmake-gui` (>= 3.10) to configure and generate the files for building each of the additional libraries and excutables in these package; 
* build and install each of the libraries using the build system selected by `cmake`

* Use `cmake-gui` (>= 3.10) to configure and generate the files for building PCL; 
* build and install the libraries using the build system selected by `cmake`

* Download _libjpeg-turbo_ from <https://sourceforge.net/projects/libjpeg-turbo/files/1.5.3/libjpeg-turbo-1.5.3.tar.gz/download>
*  Use: `configure; make install` to install the libraries

* Use `cmake-gui` (>= 3.10) to configure and generate the files for building _cwi-pcl-codec_; 
* build and install the libraries using the build system selected by `cmake`


## Running the evaluation program

The following arguments are recognized by the program 'evaluate_compression':  
(long version arguments without '--' can also be put in a file 'parameter_config.txt' in the working directory or its parent)

*  -h [ --help ] 
	*  produce help message  
*  -K [ --K_outlier_filter ] arg (=0)
    * K neighbours for radius outlier filter   
*  --radius arg (=0.01) 
    * radius outlier filter, maximum radius  
*  -g [ --group_size ] arg (=0)
    * maximum number of files to be compressed together (0=read all files, then en(de)code 1 by 1)  
*  -f [ --bb_expand_factor ] arg (=0.2)
    * bounding box expansion to keep bounding box equal accross frames  
*  -a [ --algorithm ] arg (=V2) 
     * compression algorithm ('V1' or 'V2')  
*  -i [ --input_directories ] arg
      * Directory containing supported files (.pcd or .ply)  
*  -o [ --output_directory ] arg
      *  Directory to store decompressed pointclouds (.ply)  
*  -s [ --show_statistics ] [=arg(=1)] (=0)
      * gather and show a bunch of releavant statistical data  
*  -v [ --visualization ] [=arg(=1)] (=0)
      * show both original and decoded PointClouds graphically  
*  -p [ --point_resolution ] arg (=0.2)
       * XYZ resolution of point coordinates  
*  -r [ --octree_resolution ] arg (=0.2)
       * voxel size  
*  -b [ --octree_bits ] arg (=11)
       * octree resolution (bits)  
*  -c [ --color_bits ] arg (=8) 
       * color resolution (bits)  
*  -e [ --enh_bits ] arg (=0) 
       * bits to code the points towards the center  
*  -t [ --color\_coding\_type ] arg (=1)
       * pcl=0,jpeg=1 or graph transform  
*  -m [ --macroblock_size ] arg (=16)
       * size of macroblocks used for predictive frame (has to be a power of 2)  
*  --keep_centroid  arg (=0) 
       * keep voxel grid positions or not  
*  --create_scalable arg (=0) 
       * create scalable bitstream (not yet implemented)  
*  --do\_connectivity_coding arg (=0) 
       * connectivity coding (not yet implemented)  
*  --icp\_on_original arg (=0)
       * icp\_on_original  
*  -q [ --jpeg_quality ] arg (=0) 
       * jpeg quality parameter  
*  -d [ --do\_delta_coding ] arg (=0) 
       * use delta (predictive) en(de)coding  
*  --do\_quality_computation arg (=0)
       * compute quality of en(de)coding  
*  --do\_icp\_color_offset arg (=0) 
       *  do color offset en(de)coding on predictive frames  
*  -j [ --num_threads ] arg (=1) 
       *  number of parallel threads (1=default, single  thread, no parallel execution)  
*  --intra\_frame\_quality_csv arg (=intra\_frame\_quality.csv)
       * intra frame coding quality results filename (.csv file)  
*  --predictive\_quality_csv arg
       * (=predictive_quality.csv) predictive coding quality results file name (.csv file)  
*  --debug_level arg (=0)
       *  debug print level (0=no debug print, 3=all debug print)  

The precise meanings of these parameters are explained in the journal paper mentioned above.

## Functions exported by the DLL

```
extern "C" __declspec(dllexport)
MyPointCloud Cwi_decoder(unsigned char * compFrame);
```
Decompress a point ploud passed as a bytestream without name mangling

The point cloud is returned in the following structure:

```
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
```
MyPointCloud includes the capture timestamp from the point cloud header

> 
Apr.6, 2017, updated: Jun 25, 2017 and Apr. 23, 2018.   
Kees Blom (Kees.Blom@cwi.nl) CWI, Amsterdam, The Netherlands


