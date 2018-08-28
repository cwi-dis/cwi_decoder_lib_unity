// cwi_encode.cpp : Defines the exported functions for the DLL application.
//
#include <sstream>
#include <evaluate_comp.h>
#include <evaluate_comp_impl.hpp>
#include <fstream>
#include <stdio.h>
//#include "cwi_encode.h"

using namespace std;
// point cloud library

//#include <evaluate_compression_impl.hpp>

/*evaluate_compression_impl<PointT>::assign_option_values()
{
	algorithm_ = vm_["algorithm"].template as<std::string>();
	group_size_ = vm_["group_size"].template as<int>();
	K_outlier_filter_ = vm_["K_outlier_filter"].template as<int>();
	radius_ = vm_["radius"].template as<double>();
	bb_expand_factor_ = vm_["bb_expand_factor"].template as<double>();
	algorithm_ = vm_["algorithm"].template as<std::string>();
	show_statistics_ = vm_["show_statistics"].template as<bool>();
	enh_bits_ = vm_["enh_bits"].template as<int>();
	octree_bits_ = vm_["octree_bits"].template as<int>();
	color_bits_ = vm_["color_bits"].template as<int>();
	visualization_ = vm_["visualization"].template as<bool>();
	if (vm_.count("input_directories")) {
		input_directories_ = vm_["input_directories"].template as<std::vector<std::string> >();
	}
	output_directory_ = vm_["output_directory"].template as<std::string>();
	if (algorithm_ == "V2")
	{
		color_coding_type_ = vm_["color_coding_type"].template as<int>();
		macroblock_size_ = vm_["macroblock_size"].template as<int>();
		keep_centroid_ = vm_["keep_centroid"].template as<int>();
		create_scalable_ = vm_["create_scalable"].template as<bool>();
		jpeg_quality_ = vm_["jpeg_quality"].template as<int>();
		do_delta_coding_ = vm_["do_delta_coding"].template as<bool>();
		do_quality_computation_ = vm_["do_quality_computation"].template as<bool>();
		icp_on_original_ = vm_["icp_on_original"].template as<bool>();
		do_icp_color_offset_ = vm_["do_icp_color_offset"].template as<bool>();
		num_threads_ = vm_["num_threads"].template as<int>();
		intra_frame_quality_csv_ = vm_["intra_frame_quality_csv"].template as<string>();
		predictive_quality_csv_ = vm_["predictive_quality_csv"].template as<string>();
	}
}

encoder_V2_->setMacroblockSize(macroblock_size_);
*/
// This is an example of an exported variable
//DebuG
//CWI_ENCODE_API int ncwi_encode=0;

// This is an example of an exported function.
//Sample function for Testing
//CWI_ENCODE_API int fncwi_encode(void)
//{
	//evaluate_compression_impl<PointXYZRGB> evaluator(argc, argv);
	//return evaluator.evaluate() == true ? 0 : -1;
//}

// This is the constructor of a class that has been exported.
// see cwi_encode.h for the class definition
//Ccwi_encode::Ccwi_encode()
//{
//   return;
//}
//pcl::PointCloud<PointT> & rcloud_out = *p_cloud;
//pcl::PointCloud<PointT> & rcloud_in = *i_cloud;
//Final encoding function for signals

//Original Pointer 
//pcl::PointCloud<PointT> pointcloud
//New pointer 
//CWI_ENCODE_API int cwi_encoder(encoder_params param, void* pc, std::stringstream& comp_frame)
extern "C" __declspec(dllexport) int Cwi_encoder(encoder_params param, void* pc, std::stringstream& comp_frame)
{
	//int argc = 0;
	//char *argv[] = { NULL };
	evaluate_comp_impl<PointXYZRGB> evaluate;
	//std::cout << "Starting evaluator \n";
	return evaluate.evaluator(param, pc, comp_frame) == true ? 0 : -1;
}

extern "C" __declspec(dllexport) int Cwi_decoder(encoder_params param, void* pc, std::stringstream& comp_frame)
{
	int argc = 0;
	char *argv[] = { NULL };
	evaluate_comp_impl<PointXYZRGB> evaluate;
	return evaluate.evaluate_dc(param, pc, comp_frame) == true ? 0 : -1;
}
extern "C" __declspec(dllexport) int Cwi_test(int a, int b)
{
	return a * b;
}


	/*std::ofstream log1;
	log1.open("log.txt", std::ofstream::app);
	log1 << "Entering cwi_test2";
	log1.close();
	encoder_params par;
	par.num_threads = 4;
	par.do_inter_frame = false;
	par.gop_size = 1;
	par.exp_factor = 0;
	par.octree_bits = 9;
	par.color_bits = 8;
	par.jpeg_quality = 85;
	par.macroblock_size = 16;
	std::ofstream log;
	log.open("log.txt");
	log << "\nCompression parameters assigned", std::ofstream::app;
	log.close();
	evaluate_comp_impl<PointXYZRGB> evaluate;
	void * pc;
	std::ofstream log99;
	log99.open("log.txt", std::ofstream::app);
	log99 << "\n The first stringstream will be created now";
	log99.close();
	stringstream comp_frame(comp_fr);
	std::ofstream log2;
	log2.open("log.txt", std::ofstream::app);
	log2 << "\n Input converted to stringstream, decoding initialized";
	log2.close();
	return evaluate.evaluate_dc(par, pc, comp_frame) == true ? 0 : -1;
	*/
struct PLYExport
{
	boost::shared_ptr<pcl::PointCloud<PointXYZRGB>> pc;
};
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
};
extern "C" __declspec(dllexport) MyPointCloud Cwi_test2(char* filename, void* p)
{
	std::string path(filename);
	std::ofstream log1;
	log1.open("log.txt");
	log1 << "\n Entered the function";
	log1.close();
	auto pe = new PLYExport;
	pe->pc = boost::shared_ptr<pcl::PointCloud<PointXYZRGB>>(new PointCloud<PointXYZRGB>());
	std::ofstream log2;
	log2.open("log.txt", std::ofstream::app);
	log2 << "\n Created empty point cloud object :" << path;
	log2.close();
	int res = load_ply_file<PointXYZRGB>(path, pe->pc);
	std::ofstream log3;
	log3.open("log.txt", std::ofstream::app);
	log3 << "\n Load PLY complete size is :" << sizeof(pe->pc);
	log3.close();
	p = reinterpret_cast<void*>(pe);
	std::ofstream log4;
	log4.open("log.txt", std::ofstream::app);
	log4 << "\n Point cloud cast to void pointer";
	log4.close();
	/*
	MyPoint test;
	test.x = 99;
	test.y = 99;
	test.z = 99;
	test.r = 50;
	test.g = 50;
	test.b = 50;
	p = reinterpret_cast<void *>(&test);
	MyPoint *test2;
	test2 = reinterpret_cast<MyPoint *>(p);
	*/
	MyPointCloud ptcld;
	pcl::PointCloud<PointXYZRGB> cld = *(pe->pc);
	int size = cld.height * cld.width;
	ptcld.size = size;
	//ptcld.pointcloud = new MyPoint[size];
	for (int i = 0; i < size; i++)
	{
		ptcld.pointcloud[i].x = cld.points[i].x;
		ptcld.pointcloud[i].y = cld.points[i].y;
		ptcld.pointcloud[i].z = cld.points[i].z;
		ptcld.pointcloud[i].r = cld.points[i].r;
		ptcld.pointcloud[i].g = cld.points[i].g;
		ptcld.pointcloud[i].b = cld.points[i].b;
	}
	/*ptcld.pointcloud = new MyPoint[2];
	ptcld.pointcloud[0] = test;
	ptcld.pointcloud[1].x = 102;
	ptcld.pointcloud[1].y = 102;
	ptcld.pointcloud[1].z = 102;
	ptcld.pointcloud[1].r = 102;
	ptcld.pointcloud[1].b = 102;
	ptcld.pointcloud[1].g = 102;
	*/
	return ptcld;
}