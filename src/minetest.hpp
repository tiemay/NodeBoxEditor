#ifndef MINETEST_HPP_INCLUDED
#define MINETEST_HPP_INCLUDED

#include "common.h"
#include "Configuration.hpp"

class Minetest
{
public:
	Minetest(Configuration *conf);
	bool findMinetest();
	bool runMod(const std::string &modname, const std::string &modpath,
			const std::string &world = "nbe_test", bool new_world = true);
private:
	Configuration *_conf;
	std::string minetest_dir;
};

#endif