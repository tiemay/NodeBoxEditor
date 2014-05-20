#include "minetest.hpp"
#include <stdlib.h>
#include <fstream>

#ifdef _WIN32
#	define DIR_DELIM "\\"
#	include <direct.h>
#else
#	define DIR_DELIM "/"
#endif

Minetest::Minetest(Configuration *conf):
	_conf(conf), minetest_dir("C:\\Games\\Minetest")
{}

bool Minetest::findMinetest()
{
	return true;
}

bool Minetest::runMod(const std::string &modname, const std::string &modpath,
		const std::string &world, bool new_world)
{
	if (new_world) {
		// Delete old world folder
		std::string param = minetest_dir + DIR_DELIM "worlds" DIR_DELIM + world;
		remove(param.c_str());

		// Create new world folder
#ifdef _WIN32
		mkdir(param.c_str());
#else
		mkdir(param.c_str(), 0);
#endif
		// world.mt
		param = minetest_dir + DIR_DELIM "worlds" DIR_DELIM + world + DIR_DELIM "world.mt";
		std::ofstream file(param.c_str());
		file << "gameid = minetest\n";
		file << "backend = sqlite3\n";
		file << "load_mod_" << modname.c_str() << " = true\n";
		file.close();
	}

	// Create mod folder in world
	std::string cmd = minetest_dir + DIR_DELIM  "worlds" DIR_DELIM + world + DIR_DELIM "worldmods";
#ifdef _WIN32
		mkdir(cmd.c_str());
#else
		mkdir(cmd.c_str(), 0);
#endif

	// Install mod
	cmd = minetest_dir + DIR_DELIM "worlds" DIR_DELIM + world + DIR_DELIM "worldmods" DIR_DELIM + modname;
	rename(modpath.c_str(), cmd.c_str());

	// Run minetest
	std::string exec = minetest_dir + DIR_DELIM "bin" DIR_DELIM "minetest";
#ifdef _WIN32
	exec += ".exe";
#endif
	exec += " --worldname " + world + " --go";	
	system(exec.c_str());
	return true;
}
